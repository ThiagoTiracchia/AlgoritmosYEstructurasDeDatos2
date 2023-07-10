#include "Lista.h"

Lista::Lista() : _prim(NULL), _ult(NULL) {
// Completar
}

Lista::Lista(const Lista& l) : Lista() {
//Inicializa una lista vacía y luego utiliza operator= para no duplicar el código de la copia de una lista.
    *this = l;

}

Lista::~Lista() {
    destruirnodos();
}



Lista& Lista::operator=(const Lista& aCopiar) {
    destruirnodos();
    Nodo* actual = aCopiar._prim;
    while ( actual != NULL){
        agregarAtras(actual->valor);
        actual = actual->der;

    }

    return *this;

}

void Lista::agregarAdelante(const int& elem) {
    Nodo* nuevo = new Nodo(NULL, elem, NULL);
    if(_ult == NULL ){
        _ult = nuevo;
    } else {
        nuevo->der = _prim;
        _prim->izq = nuevo;

    }
    _prim = nuevo;
}

void Lista::agregarAtras(const int& elem) {
    Nodo *nuevo = new Nodo(NULL, elem, NULL);
    if( _prim == NULL ){
        _prim = nuevo;
    } else {
        nuevo->izq = _ult;
        _ult->der = nuevo;
    }
    _ult = nuevo;

}
void Lista::eliminar(Nat i) {
    Nodo* actual = _prim;
    Nodo* prev;
    if ( i == 0 && longitud() == 1){
        _prim = NULL;
        _ult = NULL;

    } else {
        for ( int j = 0 ; j < i; j++ ){
            prev = actual;
            actual = actual->der;
        }
        if ( i == 0){
            _prim = actual->der;
            _prim->izq = NULL ;
        } else {
            prev->der = actual->der;
            actual->der = actual->izq;
        }

    }
    delete actual;
}

int Lista::longitud() const {
    int res = 0;
    Nodo* actual = _prim;

    while( actual != NULL ) {
        res++;
        actual = actual->der;
    }
    return res;
}

const int& Lista::iesimo(Nat i) const {
    Nodo* actual = _prim;
    for (int j = 0; j < i; j++) {
        actual = actual->der;

    }

    return actual->valor;

}

int& Lista::iesimo(Nat i) {
    Nodo* actual = _prim;
    for (int j = 0; j < i; j++) {
        actual = actual->der;

    }

    return actual->valor;

}


void Lista::mostrar(ostream& o) {
// Completar
}
void Lista:: destruirnodos(){
Nodo * actual = _prim;

while (actual)
{
Nodo* siguiente = actual->der ;
delete actual;
actual = siguiente;
}
_prim = NULL;
_ult =  NULL;
}
