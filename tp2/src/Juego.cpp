//
// Created by clinux01 on 11/11/22.
//
#include "Tipos.h"
#include "Juego.h"
#include "tablero.h"

Juego  Juego :: operator=(Juego& j ){

    this->turnoGral = j.TurnoGeneral();
    this->_repositorio = j._repositorio;
    this-> _varianteDelJuego = j.infovariante();
    this-> CantidadJugadores = j.cantjugadores();
    this->_t = j.dartablero();
    this->fichasEnMano = j.fichasEnMano;
    this->Puntaje_FichasEnMano_FichasUbicadas_PorJugador = j.Puntaje_FichasEnMano_FichasUbicadas_PorJugador;
    this->_fichasareponer = j._fichasareponer;
    return *this ;
}



Juego:: Juego (Nat jugadores,  const Repositorio& r,  variante& v){
    turnoGral=0;
    _repositorio = r;

   _varianteDelJuego = v;
    CantidadJugadores = jugadores;

    _t = tablero (v.tamanotablero());

    multiset<Letra> a = {};
    vector<multiset<Letra>> f(CantidadJugadores + 1 , a) ;
    _fichasareponer = f;


    vector<vector<Nat>> abc (CantidadJugadores,vector<Nat> (27, 0));
    fichasEnMano = abc;
    vector<PuntajeyFichasJugadas>  socotroco (CantidadJugadores, {0,{}});
    Puntaje_FichasEnMano_FichasUbicadas_PorJugador = socotroco;

    for (int j = 0 ; j < CantidadJugadores ; j++) {
        for (int i = 0; i < _varianteDelJuego.CantFichas(); i++) {
            fichasEnMano[j][ord(_repositorio.front())] ++;
            _fichasareponer[j + 1].insert(_repositorio.front());
            _repositorio.pop_front();

        }
    }
}




bool Juego::jugadavalida( const Ocurrencia& o){
    bool res = false;
    bool pisaLetra = true;
    for ( tuple<Nat ,Nat ,Letra> x : o ) {
        if (_t.hayletratablero(get<0>(x), get<1>(x))){
            pisaLetra = false;
        }
    }

    if (o.size() <= 8  && pisaLetra) {
        if (Chequeo(o)) {
            res = true;
        }
    }
    return res;

}




bool Juego :: Chequeo(const Ocurrencia& o) {
    _t.AUXubicarConjFichas(o);

    bool res = true;
    if(esdiagonal(o)){
        res = false;
    }else {
    for (tuple<Nat, Nat, Letra> x : o){
        res = res && FormaPalVertical( x) && FormaPalHorizontal( x);
    }
    _t.desubicarfichas(o);
}
    return res;
    }

bool Juego :: FormaPalVertical(Ficha x){
list<Letra> palabra;
palabra.push_front(get<2>(x));
int sig = 1;
int ant = 1 ;
int x1 = get<0>(x);
int y1 = get<1>(x);
int Lmax = (_varianteDelJuego.Palabraslegitrie()).PALABRAMASLARGA();
bool res = false;
for (int i = 0; i < Lmax; i++){
    if (y1 + sig < _t.tamano() ){
   if  (_t.hayletratablero(x1 , (y1 + sig))){
    palabra.push_back(_t.letra(x1, (y1 + sig)));
    sig++ ;
    }
    }
    if (y1  - ant >= 0) {
        if (_t.hayletratablero(x1, (y1 - ant))) {
            palabra.push_front(_t.letra(x1, (y1 - ant)));
            ant++;
        }
    }

}

const vector<Letra> Palabraa = listaAvector(palabra);
bool resizq = true;
bool resder = true;

if ((y1 + (sig +1  ) < _t.tamano())){
    resizq = !(_t.hayletratablero(x1, y1 + (sig +1  ) )) ;
}
if ( ((y1  -  ( ant +1 ) >= 0)) ){
    resder = !(_t.hayletratablero(x1 , y1 - (ant+ 1 ))) ;
}

if (resder && resizq ) {
    res=( (_varianteDelJuego.Palabraslegitrie()).count(Palabraa) == 1);

}

return res;
}


bool Juego ::  FormaPalHorizontal(Ficha x ){
list<Letra> palabra = {};
    palabra.push_front(get<2>(x));
    int sig = 1;
    int ant = 1 ;
    int x1 = get<0>(x);
    int y1 = get<1>(x);
    int Lmax = (_varianteDelJuego.Palabraslegitrie()).PALABRAMASLARGA();
    bool res= false;
    int i= 0;
    while (i<Lmax){
        if ((x1+sig)< _t.tamano()) {
            if (_t.hayletratablero(x1 + sig, y1)) {
                palabra.push_back(_t.letra(x1 + sig, y1));
                sig++;
            }
        }
        if ( (x1 - ant) >=  0 ) {
            if ((_t.hayletratablero(x1 - ant, y1))) {
                palabra.push_front(_t.letra(x1 - ant, y1));
                ant++;
            }
        }
        i++;

    }

    // lista a vector
    const vector<Letra>  Palabraa = listaAvector(palabra);

    bool resizq = true;
    bool resder = true;

    if( x1+ (sig +1) < _t.tamano()){
        resder= !(_t.hayletratablero(x1+(sig +1)  , y1));
    }
    if( x1- (ant  + 1) >= 0  ){
        resizq= !(_t.hayletratablero( x1-(ant  + 1), y1));
    }
    if(resizq && resder){
        res= ((_varianteDelJuego.Palabraslegitrie()).count(Palabraa) == 1);
    }

    return res;
}



void Juego:: ubicarConjJuego( const Ocurrencia& o ){
    _fichasareponer[TurnoDelJugador()].clear();
    for (tuple<Nat, Nat, Letra> x : o) {
        _t.ponerletra(get<0>(x),get<1>(x),get<2>(x));
        _t.cambiarturno(get<0>(x),get<1>(x), turnoGral);
        _t.ponerqhayletra(get<0>(x),get<1>(x));

    }

    Puntaje_FichasEnMano_FichasUbicadas_PorJugador[TurnoDelJugador()].second.push(make_tuple(o,turnoGral,eshorizontal(o)));
    reponer(TurnoDelJugador(),o) ;
    turnoGral ++;


}



bool Juego :: eshorizontal( const Ocurrencia& o){
 bool res = false;
 if ( o.size() == 1 ){
     res = true;
 } else {
res = get<1>(*o.begin() ) == get<1>(*o.end());
 }
 return res;
}


variante Juego::infovariante() {
 return _varianteDelJuego;
}

Nat Juego::TurnoDelJugador() const{
 return turnoGral % CantidadJugadores;
}

Nat Juego :: TurnoGeneral() const{
    return turnoGral;
}

Nat Juego::PuntajepalabraSQFormanHorizontal(tuple<Ocurrencia, Nat, bool> f) {
   Nat puntaje = 0;
   Ocurrencia Fichas = get<0>(f);
    for ( tuple<Nat ,Nat, Letra> x : Fichas) {

       puntaje = puntaje + PuntajepalabraQFormaHorizontal(x,get<1>(f));

   }
    return puntaje;
}

Nat Juego::PuntajepalabraSQFormanVertical(tuple<Ocurrencia, Nat , bool> f) {
    Nat puntaje = 0;
    Ocurrencia Fichas = get<0>(f);
   for ( tuple<Nat ,Nat, Letra> x : Fichas)  {

        puntaje = puntaje + PuntajepalabraQFormaVertical(x,get<1>(f));

    }
   return puntaje;
}
Nat Juego :: PuntajepalabraQFormaHorizontal(Ficha f, Nat turno) {
    Nat x = get<0>(f);
    Nat y = get<1>(f);
    int sig = x+1;
    int ant = x-1;
    Nat puntaje = _varianteDelJuego.PuntajeLetra(get<2>(f));
    for (int i=0;i< (_varianteDelJuego.Palabraslegitrie()).PALABRAMASLARGA() ; i++) {

        if (sig < _t.tamano()) {
            if (_t.hayletratablero(sig, y) && _t.turno(sig, y) <= turno) {
                puntaje = puntaje + _varianteDelJuego.PuntajeLetra(_t.letra(sig, y));
                sig++;
            }
        }
        if (ant >= 0) {
            if (_t.hayletratablero(ant, y) && _t.turno(ant, y) <= turno) {
                puntaje = puntaje + _varianteDelJuego.PuntajeLetra(_t.letra(ant, y));
                ant = ant-1;
            }
        }
    }

    return puntaje;
}
Nat Juego::PuntajepalabraQFormaVertical(Ficha f, Nat turno) {
    Nat x = get<0>(f);
    Nat y = get<1>(f);
   int sig = y + 1;
    int ant = y - 1;
    Nat puntaje = _varianteDelJuego.PuntajeLetra(get<2>(f));
    for (int i = 0; i < (_varianteDelJuego.Palabraslegitrie()).PALABRAMASLARGA(); i++) {
        if (sig < _t.tamano()) {
            if (_t.hayletratablero(x, sig) && _t.turno(x, sig) <= turno) {
                puntaje = puntaje + _varianteDelJuego.PuntajeLetra(_t.letra(x, sig));
                sig++;
            }
        }

            if (ant >= 0) {
                if (_t.hayletratablero(x, ant) && _t.turno(x, ant) <= turno) {
                    puntaje = puntaje + _varianteDelJuego.PuntajeLetra(_t.letra(x, ant));
                    ant--;
                }
            }

        }


    return puntaje;
}

Nat Juego:: PuntajeJugador(Nat jug){
    Nat puntos = Puntaje_FichasEnMano_FichasUbicadas_PorJugador[jug].first;
    Nat puntaje = 0;
    queue<tuple<Ocurrencia ,Nat,bool>> FichasUbicadas = (Puntaje_FichasEnMano_FichasUbicadas_PorJugador[jug]).second;

    while(!FichasUbicadas.empty()){
        if(get<0>(FichasUbicadas.front()).empty()){

        }else {

            if (get<2>(FichasUbicadas.front())) {
                puntaje = puntaje + PuntajepalabraQFormaHorizontal(*begin(get<0>(FichasUbicadas.front())),
                                                                   get<1>(FichasUbicadas.front()))
                          + PuntajepalabraSQFormanVertical(FichasUbicadas.front());
            } else {
                puntaje = puntaje + PuntajepalabraQFormaVertical(*begin(get<0>(FichasUbicadas.front())),
                                                                 get<1>(FichasUbicadas.front())) +
                          PuntajepalabraSQFormanHorizontal(FichasUbicadas.front());
            }
        }

        FichasUbicadas.pop();

    }
    puntos = puntos +puntaje;
    return puntos;

}

//Letra Juego:: ObtContCoord( Nat x , Nat y){
  //return t.letra( x, y) ;
//}

Nat Juego:: CantLetraxJugador(Letra x , Nat jug ){
 return fichasEnMano[jug][ord(x)];
}



multiset<Letra> Juego :: reponer(Nat cid , const Ocurrencia& o ) {
   multiset<Letra> res = {};
    for (tuple<Nat, Nat, Letra> x: o) {
        fichasEnMano[cid][ord(get<2>(x))]--;
       _fichasareponer[cid].insert(_repositorio.front());
        fichasEnMano[cid][ord(_repositorio.front())]++;
        res.insert((_repositorio.front()));
        _repositorio.pop_front();


    }
    return res;
}

Nat Juego :: puntajeOcurrencia( const Ocurrencia& o ) {
     Nat puntaje = 0;

    if (eshorizontal(o) && o.size()>1){
        puntaje = PuntajepalabraQFormaHorizontal(*o.begin(), turnoGral) + PuntajepalabraSQFormanVertical(make_tuple( o , turnoGral , true) );

    }
    else if(o.size() == 1) {
        puntaje = PuntajepalabraQFormaVertical(*o.begin(), turnoGral)+PuntajepalabraQFormaHorizontal(*o.begin(), turnoGral)- _varianteDelJuego.PuntajeLetra(
                get<2>(ocurrenciaAvector(o)[0]));
    }
    else {
        puntaje = PuntajepalabraQFormaVertical(*o.begin(), turnoGral) + PuntajepalabraSQFormanHorizontal(make_tuple( o, turnoGral, false) );
    }



return puntaje;
}


tablero Juego :: dartablero(){
    return _t;
}

Nat Juego :: cantjugadores() const{
    return CantidadJugadores;
}




vector<Letra> Juego :: listaAvector(const list<Letra>& p  ){
    Palabra palabra = {};
    for (Letra x : p) {
        palabra.push_back(x);
    }

return palabra;

}

vector<tuple<Nat, Nat, Letra>> Juego :: ocurrenciaAvector(const Ocurrencia& o) {
    vector<tuple<Nat,Nat,Letra>> p = {};
    for (tuple<Nat, Nat, Letra> x: o){
        p.push_back(x);
    }
    return p;
}

bool Juego :: esdiagonal( const Ocurrencia& o){
    bool res = false;
    vector<tuple<Nat, Nat, Letra>> pal = ocurrenciaAvector(o);
    for( int i = 0 ; i< pal.size() -1 ; i++ ){
        if((get<0>(pal[i] )  + 1 ==  get<0>(pal[i+1])  ) && (get<1>(pal[i] )  + 1  ==  get<1>(pal[i+1])) ){
        res = true;
        }
    }
    return res;
};

bool Juego :: tienelasfichas (const Ocurrencia& o, Nat id){
    bool res = false;

    for (tuple<Nat, Nat, Letra> x: o){
        if (  fichasEnMano[id][ord(get<2>(x))] > 1 ) {
            res = true;
        }
    }
    return res;
}

void Juego :: avanzarturno()
{
    turnoGral ++;
};

vector<multiset<Letra>> Juego::  fichasareponer (){
    return _fichasareponer;

}

//Juego::~Juego() {
  //  delete turnoGral;
 //  delete _repositorio;
 //  delete _t;
   // delete fichasEnMano;
 //  delete  Puntaje_FichasEnMano_FichasUbicadas_PorJugador;
  // delete _fichasareponer;
  // delete CantidadJugadores;


//};


