#ifndef TIPOS_H
#define TIPOS_H

#include <cstdlib>
#include <cassert>
#include <iostream>
#include <set>
#include <tuple>
#include <string>
#include <map>
#include <list>
#include <vector>
#include <queue>

using namespace std;

using Nat = unsigned int;

using Letra = char;

using Repositorio = list<Letra>;

using IdCliente = Nat;

using Ocurrencia = set<tuple<Nat, Nat, Letra>>;

using Palabra = vector<Letra>;

using Ficha = tuple<Nat, Nat, Letra>;

using FichasJugadas = tuple<Ocurrencia,Nat,bool>;

using PuntajeyFichasJugadas = pair<Nat,queue<FichasJugadas > >;



#endif // TIPOS_H

