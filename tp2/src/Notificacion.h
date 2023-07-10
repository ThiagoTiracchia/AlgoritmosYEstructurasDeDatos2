#ifndef NOTIFICACION_H
#define NOTIFICACION_H

#include "Tipos.h"

enum class TipoNotificacion {
    IdCliente,
    Empezar,
    TurnoDe,
    Ubicar,
    Reponer,
    SumaPuntos,
    Mal
};

class Notificacion {
public:
    /**
     * Los siguientes funcionan como constructores de los distintos tipos de notificaciones.
     */
    static Notificacion nuevaIdCliente(IdCliente id);
    static Notificacion nuevaEmpezar(Nat n);
    static Notificacion nuevaTurnoDe(IdCliente id);
    static Notificacion nuevaUbicar(IdCliente id, const Ocurrencia& oc);
    static Notificacion nuevaReponer(multiset<Letra> letras);
    static Notificacion nuevaSumaPuntos(IdCliente id, Nat puntos);
    static Notificacion nuevaMal();

    Notificacion(TipoNotificacion t);
    /**
     * Retorna el tipo de la notificacion
     */
    TipoNotificacion tipoNotificacion() const;

    /**
     * Retorna el id del cliente en notificaciones de tipo IdCliente
     *
     * Pre: this->tipoNotificacion() == TipoNotificacion::IdCliente
     */
    IdCliente idCliente() const;

    /**
     * Retorna el tamano del tablero en notificaciones de tipo Empezar
     *
     * Pre: this->tipoNotificacion() == TipoNotificacion::Empezar
     */
    Nat empezar() const;

    /**
     * Retorna el id del cliente al que le toca jugar en notificaciones de tipo TurnoDe
     *
     * Pre: this->tipoNotificacion() == TipoNotificacion::TurnoDe
     */
    IdCliente turnoDe() const;

    /**
     * Retorna el id del cliente y las fichas ubicadas en notificaciones de tipo Ubicar
     *
     * Pre: this->tipoNotificacion() == TipoNotificacion::Ubicar
     */
    std::tuple<IdCliente, Ocurrencia> ubicar() const;

    /**
     * Retorna las fichas repuestas en notificaciones de tipo Reponer
     *
     * Pre: this->tipoNotificacion() == TipoNotificacion::Reponer
     */
    multiset<Letra> reponer() const;

    /**
     * Retorna el id del cliente y los puntos sumados en notificaciones de tipo SumaPuntos
     *
     * Pre: this->tipoNotificacion() == TipoNotificacion::SumaPuntos
     */
    std::tuple<IdCliente, Nat> sumaPuntos() const;

    bool operator==(const Notificacion& rhs) const;

private:

    TipoNotificacion _tipoNotificacion;

    IdCliente                           _idCliente;
    Nat                                 _empezar;
    IdCliente                           _turnoDe;
    std::tuple<IdCliente, Ocurrencia>   _ubicar;
    multiset<Letra>                     _reponer;
    std::tuple<IdCliente, Nat>          _sumaPuntos;



};

#endif //NOTIFICACION_H
