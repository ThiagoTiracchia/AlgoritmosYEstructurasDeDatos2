//
// Created by clinux01 on 11/11/22.
//
#include "Tipos.h"
#include "tablero.h"




 tablero :: tablero(  Nat n ){
    vector< tuple<bool,Letra, Nat>> fila (n, make_tuple(true, 'a', 0));
    vector<vector< tuple <bool,Letra, Nat>>> res (n,fila);
    _tablero = res;

}


Nat tablero :: tamano() {
return _tablero.size();
}

bool tablero ::hayletratablero(Nat x , Nat y ) {
return !(get<0>(_tablero[x][y]));
}

Letra tablero :: letra( Nat x , Nat y  ){
    return get<1>(_tablero[x][y]);
}

void tablero :: ponerletra(Nat x, Nat y, Letra l){
    get<1>(_tablero[x][y])= l ;
    get<0>(_tablero[x][y] )= false ;

}

void tablero::cambiarturno(Nat x, Nat y, Nat turno) {
        get<0>(_tablero[x][y] ) = turno;

}

bool tablero :: entablero( Nat x , Nat y ){
    return _tablero.size() > x && _tablero.size() > y;
}

void tablero::AUXubicarConjFichas(Ocurrencia const& o) {
    for (auto x:o) {
        ponerletra(get<0>(x),get<1>(x),get<2>(x));
    }
}

void tablero::desubicarfichas(Ocurrencia const& o) {
    for (auto x:o) {
        get<0>(_tablero[get<0>(x)][get<1>(x)]) = true;
    }
}

Nat tablero::turno(Nat x, Nat y) {
    return get<2>(_tablero[x][y]);
}

tablero tablero:: operator=(tablero t){

 this->_tablero = t._tablero;
  return *this;

}


void tablero :: ponerqhayletra (Nat x, Nat y){
    get<0>(_tablero[x][y]) = false;
}

//tablero::~tablero() {
//delete _tablero;
//}



