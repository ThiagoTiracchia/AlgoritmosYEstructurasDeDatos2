//
// Created by clinux01 on 11/11/22.
//

#include "Juego.h"
#include "Notificacion.h"
#include "Servidor.h"


Servidor :: Servidor(Nat k,  variante& v,  const Repositorio  & r) {
    clientesConectados = 0 ;
    clientesEsperados = k  ;
    _respositorio = r; // O(n)
    vector<queue<Notificacion>> notifs (k+1);
    _notificacionesPorJugador = notifs;

    _variante = v ;
  Juego j(k,r,v); //ya repartio del repositor!!
    _juego = j ;
    _empezo = false;
    _turno = 0;
    vector<bool> t (k +1 , false);
    _vectorparaverlaprimeranotificacion = t;

    }


Nat  Servidor :: conectarcliente ( ){
    if(ObtCantClientesEsperados() != CAntClientesConectados() ) {
        clientesConectados++;

      _notificacionesPorJugador[clientesConectados].push( Notificacion :: nuevaIdCliente(clientesConectados));

    }
    if (ObtCantClientesEsperados() == CAntClientesConectados() ){
        _turno = 1;
        _empezo = true;

    }

return clientesConectados;
}

list<Notificacion> Servidor :: consultarnotificaiones ( Nat cid){
    list<Notificacion> res = {};

    while (!(_notificacionesPorJugador[cid].empty( ))){

        res.push_back(_notificacionesPorJugador[cid].front());
        _notificacionesPorJugador[cid].pop();
    }

    if (_empezo == true && _turno == 1 && _vectorparaverlaprimeranotificacion[cid] == false ){

    res.push_back(Notificacion ::nuevaEmpezar(_variante.tamanotablero()));
    res.push_back(Notificacion ::nuevaTurnoDe(1 ));
    res.push_back(Notificacion ::nuevaReponer(_juego.fichasareponer()[cid]) );


    _vectorparaverlaprimeranotificacion[cid] = true;

}


        return res;
    }



void Servidor ::  RecibirMensaje( Nat cid ,  const Ocurrencia& o ) {

    if(_juego.TurnoGeneral() % clientesEsperados == cid && _empezo) {
        _turno++;

        if (o.empty()) {
            Notificacion ubicacion = Notificacion::nuevaUbicar(cid, o);

            for (int i = 0; i < clientesConectados; i++) {
                _notificacionesPorJugador[i].push(ubicacion);
                _notificacionesPorJugador[i].push(
                        Notificacion::nuevaSumaPuntos(cid, 0));


            }
            _juego.ubicarConjJuego(o);

            _notificacionesPorJugador[cid].push(Notificacion::nuevaReponer({}));
            for (int i = 0; i < clientesConectados; i++) {
                _notificacionesPorJugador[i].push(
                        Notificacion::nuevaTurnoDe(_juego.TurnoGeneral() % _juego.cantjugadores()));
            }
        } else {
            if (_empezo && _juego.tienelasfichas(o, cid)) {
                if (_juego.jugadavalida(o)) {
                    _juego.ubicarConjJuego(o);
                    Nat turnoo = _juego.TurnoGeneral() % _juego.cantjugadores();
                    multiset<Letra> repuesto = _juego.fichasareponer()[cid];
                    Notificacion puntajeccito = Notificacion::nuevaSumaPuntos(cid, _juego.puntajeOcurrencia(o));
                    Notificacion ubicacion = Notificacion::nuevaUbicar(cid, o);
                    for (int i = 0; i < clientesConectados; i++) {

                        _notificacionesPorJugador[i].push(ubicacion);
                        _notificacionesPorJugador[i].push(puntajeccito);
                    }

                    _notificacionesPorJugador[cid].push(Notificacion::nuevaReponer(repuesto));


                    for (int i = 0; i < clientesConectados; i++) {


                        _notificacionesPorJugador[i].push(
                                Notificacion::nuevaTurnoDe(turnoo));

                    }
                } else {
                    _notificacionesPorJugador[cid].push(Notificacion::nuevaMal());
                }


            } else {
                _notificacionesPorJugador[cid].push(Notificacion::nuevaMal());
            }

        }
    }else{
        _notificacionesPorJugador[cid].push(Notificacion::nuevaMal());
    }
}

 Nat Servidor ::  ObtCantClientesEsperados( ) const{
return clientesEsperados;
}

Nat Servidor :: CAntClientesConectados( ) const{
    return clientesConectados;
}

Juego Servidor :: JuegoJugadoSv( ){
return _juego;
}

Servidor Servidor ::operator=(Servidor& s){
    this->  clientesConectados =s.CAntClientesConectados()  ;
    this->clientesEsperados  =s.ObtCantClientesEsperados()  ;
    this-> _notificacionesPorJugador  = s. _notificacionesPorJugador ;

   this->_variante =  s.JuegoJugadoSv().infovariante();
   this->  _juego = s._juego;
   this-> _empezo =  s._empezo;
   this-> _turno = s._turno;
   return *this;
}

//Servidor::~Servidor() {
//delete _respositorio  ;
//delete _notificacionesPorJugador ;
//delete _juego  ;
//};
