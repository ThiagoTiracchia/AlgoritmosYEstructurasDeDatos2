//
// Created by clinux01 on 11/11/22.
//

#include "Variante.h"
#include "Letra.h"




variante::variante(Nat t, Nat f, const  map<Letra, Nat>& PxL , const set<vector<Letra>>& PL){
     _tamano = t ;
     _fichas = f;
     PuntajePorLetra =   PxL;
     PalabrasLegitimas = PL;
     string_map<vector<Letra>> pal;
     for ( const vector<Letra>& x : PL   ) {
         pal.insert(make_pair(x,x));
     }
      PalabrasLegitTrie = pal ;
}

Nat variante:: tamanotablero(  ) const {
return _tamano;
}

Nat variante:: CantFichas() const {
return _fichas;
}

Nat variante:: PuntajeLetra (Letra l  ) const {

       return (*PuntajePorLetra.find(l)).second;


}


bool variante:: palabralegitima( const Palabra& l ) const {
    vector<Letra> l1 = {};

    for(int i = 0; i < l.size(); i++){
        l1.push_back(l[i]);
    }

    return PalabrasLegitTrie.count(l1) == 1 ;

}

Nat variante :: CantDeLetras() const{
    return (PuntajePorLetra).size();
}

 set<vector<Letra>>   variante :: Palabraslegitimass() const
{

    return  PalabrasLegitimas;
}

map<Letra ,Nat> variante :: PuntajeporLetradicc() const {
    return PuntajePorLetra;
}



 const variante variante ::operator=( const variante& v)   {
     this->_tamano = v.tamanotablero() ;
     this->_fichas = v.CantFichas();
     this->PuntajePorLetra = v.PuntajeporLetradicc();
     this->PalabrasLegitimas = v.Palabraslegitimass();
     this->PalabrasLegitTrie = v.PalabrasLegitTrie;

     return *this;
}

 /*variante variante ::operator=( variante& v)   {
this->_tamano = v._tamano ;
this->_fichas = v._fichas;
this->PuntajePorLetra = v.PuntajePorLetra;
this->PalabrasLegitimas = v.PalabrasLegitimas;
this->PalabrasLegitTrie = v.PalabrasLegitTrie;

return *this;
}*/


 string_map<vector<Letra>> variante :: Palabraslegitrie() const {
return PalabrasLegitTrie;
}

int variante::Lmax()  {
    return 0;
    //return PalabrasLegitTrie.Altura();
}

variante::variante() : _fichas(0),_tamano(0) {

}

//variante::~variante() {
  //   delete _tamano ;
   //  delete _fichas ;
   //  delete PuntajePorLetra ;
   //  delete   PalabrasLegitimas;
    // delete PalabrasLegitTrie;

//}
