//
// Created by thiag on 15/11/2022.
//
#include "Fachada_Servidor.h"
#include "Tipos.h"
#include "Servidor.h"
Fachada_Servidor ::  Fachada_Servidor( Nat cantJugadores, const Fachada_Variante& variante, const Repositorio& r  ){
 Servidor s1(cantJugadores,variante.FachadaAVariante(variante),r);
    //Servidor s1(cantJugadores,variante,r);
    SERVIDOR = s1;
    //preguntar


}

IdCliente  Fachada_Servidor ::  conectarCliente(){

    return   SERVIDOR.conectarcliente();

}

void Fachada_Servidor :: recibirMensaje(IdCliente id, const Ocurrencia& o){

    SERVIDOR.RecibirMensaje(id, o);

}


Nat Fachada_Servidor :: jugadoresEsperados(){

   return  SERVIDOR.ObtCantClientesEsperados();

}

Nat Fachada_Servidor :: jugadoresConectados(){
  return   SERVIDOR .CAntClientesConectados();

}

std::list<Notificacion> Fachada_Servidor :: notificaciones(IdCliente id){
    return  SERVIDOR.consultarnotificaiones(id);

}