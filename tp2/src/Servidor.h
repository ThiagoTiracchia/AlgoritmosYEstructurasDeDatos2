//
// Created by clinux01 on 11/11/22.
//

#ifndef TP_JUEGODEPALABRAS_SERVIDOR_H
#include "Tipos.h"
#include "Variante.h"
#include "Juego.h"
#include "trie.h"
#define TP_JUEGODEPALABRAS_SERVIDOR_H


class Servidor {
public:


  //  ~Servidor();


    Servidor (Nat k ,  variante& v, const Repositorio &r );

Nat conectarcliente ( );

    list<Notificacion> consultarnotificaiones ( Nat cid );

 void RecibirMensaje( Nat cid ,  const Ocurrencia& o );

 Nat ObtCantClientesEsperados( ) const;

 Nat CAntClientesConectados( ) const;

 Juego JuegoJugadoSv( );

 Servidor operator=(Servidor&);


//Servidor operator= (Servidor &s );

private:
    Nat clientesConectados;
    Nat clientesEsperados;
   variante _variante = variante(0,0,{},{});
    list<Letra> _respositorio;
    vector<queue<Notificacion>> _notificacionesPorJugador ;
    variante vacia ;
    Juego _juego = Juego(0, {}, vacia  );
    bool _empezo;
    Nat _turno;
    vector<bool> _vectorparaverlaprimeranotificacion;
    vector<multiset<Letra>> fichasRepuestasDeCadaJugador;
};


#endif //TP_JUEGODEPALABRAS_SERVIDOR_H
