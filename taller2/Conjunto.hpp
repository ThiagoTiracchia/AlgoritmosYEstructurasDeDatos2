
template <class T>
Conjunto<T>::Conjunto(): _raiz(nullptr), _size(0){}

template <class T>
Conjunto<T>::~Conjunto() {
    destruir(_raiz);
}

template <class T>
void Conjunto<T>:: destruir(Nodo* n){
    if(n != nullptr){
        destruir(n->izq);
        destruir(n->der);
        delete(n);

    }
}

template <class T>
bool Conjunto<T>::pertenece(const T& clave) const {
    Nodo* actual = _raiz;
    while (actual != nullptr) {
        if (actual->valor == clave) {
            return true;
        }
        else {
            if (actual->valor < clave) {
                actual = actual->der;
            } else {
                actual = actual->izq;
            }
        }
    }
    return false;
}


template <class T>
void Conjunto<T>::insertar(const T& clave) {
    if (pertenece(clave) == false) {
        Nodo *n = new Nodo(clave);
        if (_raiz == nullptr) {
            _raiz = n;
            _size++;
        } else {
            Nodo *actual = _raiz;
            while (actual != nullptr) {
                if (actual->der == nullptr && actual->valor < clave) {
                    actual->der = n;
                    _size++;
                    actual = nullptr;
                } else {
                    if (actual->izq == nullptr && actual->valor > clave) {
                        actual->izq = n;
                        _size++;
                        actual = nullptr;
                    } else {
                        if (actual->valor < clave) {
                            actual = actual->der;
                        } else {
                            actual = actual->izq;
                        }
                    }
                }
            }
        }
    }
}


template <class T>
void Conjunto<T>::remover(const T& clave) {
    Nodo *actual = _raiz;
    Nodo *padre;
    while (actual != nullptr && actual->valor != clave) {
        padre = actual;
        if (actual->valor < clave) {
            actual = actual->der;
        } else {
            actual = actual->izq;
        }
    }

    if (actual != nullptr) {
        if (actual->izq == nullptr) {
            removerAux(actual, actual->der, padre);
            delete actual;
            _size--;
        } else if (actual->der == nullptr) {
            removerAux(actual, actual->izq, padre);
            delete actual;
            _size--;
        } else {
            Nodo* aux = actual->der;
            while (aux->izq != nullptr) {
                aux = aux->izq;
            }
            T min = aux->valor;
            remover(min);
            actual->valor = min;
        }
    }

}

template <class T>
void Conjunto<T>::removerAux(Nodo* actual, Nodo* nuevo, Nodo* padre){
    if (actual == _raiz){
        _raiz = nuevo;
    }else if (actual == padre->izq){
        padre->izq = nuevo;
    }else{
        padre->der = nuevo;
    }
}

template <class T>
const T& Conjunto<T>::siguiente(const T& clave) {
    T masUno = clave + 1;
    Nodo* actual = _raiz;
    while(actual != nullptr){
        if(actual->valor == masUno){
            return actual->valor;
        }
        else{
            if(actual->valor < masUno){
                actual = actual->der;
            }
            else{
                actual = actual->izq;
            }
        }
    }
    siguiente(masUno);
}

template <class T>
const T& Conjunto<T>::minimo() const {
    Nodo* actual = _raiz;
    while(actual->izq != nullptr){
        actual = actual->izq;
    }
    return actual->valor;
}

template <class T>
const T& Conjunto<T>::maximo() const {
    Nodo* actual = _raiz;
    while(actual->der != nullptr){
        actual = actual->der;
    }
    return actual->valor;
}

template <class T>
unsigned int Conjunto<T>::cardinal() const {
    return _size;
}

template <class T>
void Conjunto<T>::mostrar(std::ostream&) const {
    assert(false);
}

