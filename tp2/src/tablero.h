//
// Created by clinux01 on 11/11/22.
//

#include <vector>
#include "Letra.h"
#ifndef TP_JUEGODEPALABRAS_TABLERO_H
#define TP_JUEGODEPALABRAS_TABLERO_H

class tablero{
public:

   // ~tablero();

  tablero(  Nat n );


Nat tamano();

bool hayletratablero( Nat x , Nat y );

Letra letra( Nat x , Nat y  );

void ponerletra( Nat x, Nat y, Letra l);

bool entablero( Nat x , Nat y );

void cambiarturno(Nat x, Nat y, Nat turno);

void AUXubicarConjFichas(const Ocurrencia&  o);
void desubicarfichas(const Ocurrencia& o );

Nat turno (Nat x, Nat y);

tablero operator=(tablero t); //hay que devolver una referencia en la asignacion tablero

    void ponerqhayletra (Nat x, Nat y);
private:
    vector<vector<tuple< bool ,  Letra , Nat >>> _tablero;

};






#endif //TP_JUEGODEPALABRAS_TABLERO_H
