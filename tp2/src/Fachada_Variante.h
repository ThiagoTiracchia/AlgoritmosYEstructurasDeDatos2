#ifndef FACHADA_VARIANTE_H
#define FACHADA_VARIANTE_H

#include "Tipos.h"
#include "Variante.h"
#include "trie.h"
class Fachada_Variante {
public:
    /**
     * Construye una Fachada_Variante a partir de los parametros de las variantes
     */
    Fachada_Variante( Nat tamanoTab, Nat cantFichas, const map<Letra, Nat>& puntajes,  const set<vector<Letra> >&  palabrasLegitimas);

    /**
     * Retorna el tamano del tablero de la variante
     */
    Nat tamanoTablero() const  ;

    /**
     * Retorna la cantidad de fichas que cada jugador deberia tener en su mano.
     */
    Nat fichas() const;

    /**
     * Retorna el puntaje de la letra l
     */
    Nat puntajeLetra(Letra l) const ;

    /**
     * Indica si una palabra es legitima o no
     */
    bool palabraLegitima(const Palabra& palabra) const;

   variante & FachadaAVariante (const Fachada_Variante& v) const;

    //Fachada_Variante  VarianteAFachada (variante v);

private:


    variante vacia ;
  variante& VARIANTE = vacia ;


};

#endif //FACHADA_VARIANTE_H
