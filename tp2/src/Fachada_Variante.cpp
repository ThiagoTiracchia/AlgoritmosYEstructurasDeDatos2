//
// Created by thiag on 15/11/2022.
//
#include "Fachada_Variante.h"
#include "Tipos.h"
#include "Variante.h"



Fachada_Variante :: Fachada_Variante(Nat tamanoTab, Nat cantFichas,  const map<Letra, Nat>& puntajes,  const set<vector<Letra>>&  palabrasLegitimas) {
    variante v(tamanoTab, cantFichas, puntajes, palabrasLegitimas   );
    VARIANTE = v;
}


Nat Fachada_Variante ::tamanoTablero() const {

  return  VARIANTE.tamanotablero();
}


Nat  Fachada_Variante :: fichas() const{

 return VARIANTE.CantFichas();
}


Nat  Fachada_Variante :: puntajeLetra(Letra l) const  {

    return VARIANTE.PuntajeLetra ( l );
}


bool Fachada_Variante ::  palabraLegitima(const Palabra& palabra) const{

   return  VARIANTE. palabralegitima(palabra);

}


variante & Fachada_Variante ::  FachadaAVariante (const Fachada_Variante& v) const {

    return VARIANTE ;
}

