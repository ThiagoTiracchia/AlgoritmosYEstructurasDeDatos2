//
// Created by clinux01 on 11/11/22.
//


#ifndef TP_JUEGODEPALABRAS_VARIANTE_H
#include "Tipos.h"
#include <map>
#include "trie.h"
#include <iterator>

#define TP_JUEGODEPALABRAS_VARIANTE_H


class  variante {
public :
  //  ~variante();
    variante();

  variante (Nat t, Nat f,  const map<Letra,Nat>& PxL,  const set<vector<Letra>>&  PL)  ;

    Nat tamanotablero() const ;

    Nat CantFichas() const;

    Nat PuntajeLetra ( Letra l ) const ;

    bool palabralegitima( const Palabra& l ) const ;

   Nat CantDeLetras() const ;

    static int Lmax()  ;

    set<vector<Letra>> Palabraslegitimass() const;

   map<Letra ,Nat> PuntajeporLetradicc() const ;

const variante operator= ( const variante& v)   ;

    string_map<vector<Letra>>  Palabraslegitrie() const ;




private :
    Nat _tamano;
    Nat _fichas;
    map<Letra, Nat> PuntajePorLetra;
    set<vector<Letra>> PalabrasLegitimas;
    string_map<vector<Letra>> PalabrasLegitTrie;


};


#endif //TP_JUEGODEPALABRAS_VARIANTE_H
