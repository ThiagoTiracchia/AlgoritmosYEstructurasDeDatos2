//
// Created by thiag on 15/11/2022.
//
#include "Fachada_Juego.h"
#include "Juego.h"
#include "tablero.h"



Fachada_Juego :: Fachada_Juego(Nat k, const Fachada_Variante& v,const Repositorio& r){
 Juego j1(k, r , v.FachadaAVariante(v)) ;
   _JUEGO =  j1 ;
}

void  Fachada_Juego ::  ubicar(const Ocurrencia& o){

  _JUEGO.ubicarConjJuego(o);
}

IdCliente Fachada_Juego :: turno(){
  return  _JUEGO.TurnoDelJugador();
}

const Fachada_Variante& Fachada_Juego :: variantE(){
    const Fachada_Variante & a = Fachada_Variante (_JUEGO.infovariante().tamanotablero(), _JUEGO.infovariante().CantFichas() , _JUEGO.infovariante().PuntajeporLetradicc() , _JUEGO.infovariante().Palabraslegitimass() );
    return a; // interesante // wtf

}

bool Fachada_Juego :: jugadaValida(const Ocurrencia& o){

   return _JUEGO.jugadavalida( o);
}

bool Fachada_Juego :: hayLetra(Nat x, Nat y){
   return _JUEGO.dartablero().hayletratablero(x,y);
}


Letra  Fachada_Juego ::  letra(Nat i, Nat j){
   return _JUEGO.dartablero().letra(i,j);

}

Nat Fachada_Juego ::  puntaje(IdCliente id){
 return   _JUEGO.PuntajeJugador(id);
}

Nat  Fachada_Juego :: cantFicha(IdCliente id, Letra l){
  return  _JUEGO.CantLetraxJugador(l ,id);

}