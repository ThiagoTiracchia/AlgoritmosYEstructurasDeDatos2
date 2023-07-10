

#ifndef TP_JUEGODEPALABRAS_JUEGO_H
#include "Tipos.h"
#include "Variante.h"
#include "tablero.h"
#include "Fachada_Variante.h"
#include "trie.h"

#define TP_JUEGODEPALABRAS_JUEGO_H


class Juego {
public:
  //  ~Juego();
    Juego (Nat jugadores,   const Repositorio& r,   variante& v );

   bool jugadavalida( const Ocurrencia& o);

   void ubicarConjJuego(const Ocurrencia& o );

   variante infovariante()  ;

   Nat TurnoDelJugador() const;

   Nat PuntajeJugador(Nat jug);

  // Letra ObtContCoord( Nat x , Nat y);

   Nat CantLetraxJugador( Letra x , Nat jug );


    multiset<Letra>  reponer(Nat cid , const Ocurrencia& o );
    Nat TurnoGeneral() const;

    Nat puntajeOcurrencia( const Ocurrencia& o);

    tablero  dartablero();

    Juego operator=(Juego& j );

    bool tienelasfichas(const Ocurrencia& o, Nat cid);

    void  avanzarturno();
    Nat cantjugadores() const;

    vector<multiset<Letra>> fichasareponer ();

private:
   variante  _varianteDelJuego = variante(0,0,{},{} ) ;
    Nat turnoGral;
    list<Letra> _repositorio;
    tablero _t = tablero(0);
    vector<vector<Nat>> fichasEnMano;
    // vector de tupla de:
    // puntaje
    //fichasEnMano
    //fichasUbicadas (cola de tupla:
        //fichasUbicadas
        //esHorizontal?
    vector<PuntajeyFichasJugadas> Puntaje_FichasEnMano_FichasUbicadas_PorJugador;
    Nat CantidadJugadores;

vector<multiset<Letra>> _fichasareponer ;


    bool Chequeo(const Ocurrencia& o);

    bool FormaPalVertical(Ficha x );

    bool FormaPalHorizontal(Ficha x);

    Nat PuntajepalabraSQFormanVertical(tuple<Ocurrencia ,Nat  ,bool> palabra);

   Nat PuntajepalabraQFormaVertical(Ficha f, Nat turno);

    Nat PuntajepalabraSQFormanHorizontal(tuple<Ocurrencia ,Nat,bool> palabra);

    Nat PuntajepalabraQFormaHorizontal(Ficha f, Nat turno);



    static bool eshorizontal(const Ocurrencia& o);

    //const Palabra listaAvector(list<Letra> p  ) const;
;
    static vector<Letra> listaAvector(const list<Letra>& p  );

    bool esdiagonal( const Ocurrencia& o );

    vector<tuple<Nat, Nat, Letra>> ocurrenciaAvector(const Ocurrencia& o);

};


#endif //TP_JUEGODEPALABRAS_JUEGO_H
