template <typename T>
string_map<T>::string_map() : raiz(new Nodo()), _size(0) {}

template <typename T>
string_map<T>::string_map(const string_map<T>& aCopiar) : string_map() {
    *this = aCopiar;
}

template <typename T>
void string_map<T>::borrarNodo(Nodo* n){
    delete (n->definicion);
    for(int i = 0; i < n->siguientes.size(); i++){
        if (n->siguientes[i] != nullptr) {
            borrarNodo(n->siguientes[i]);
            n->siguientes[i] == nullptr;
            n->hijos = 0;
        }

    }
    delete (n);

}

template <typename T>
string_map<T>& string_map<T>::operator=(const string_map<T>& d) {
    if (raiz != nullptr){
        borrarNodo(raiz);
    }
    if(d.raiz != nullptr){
        raiz = copiar(d.raiz);
    }
    _size = d._size;
    lmax = d.lmax;
    return *this;
}

template <typename T>
string_map<T>::~string_map(){
    borrarNodo(raiz);
    raiz = nullptr;
    _size = 0;

}


template <typename T>
void string_map<T>::insert(const pair<vector<char>, T>& a) {
    Nodo *actual = raiz;
    if ( lmax <= (a.first).size()){
        lmax = (a.first).size();
    }
    for (int i = 0; i < a.first.size(); i++) {
        if (actual->siguientes[int(a.first[i])] == nullptr) {
            actual->siguientes[int(a.first[i])] = new Nodo();
            actual->hijos++;
            actual = actual->siguientes[int(a.first[i])];
        } else {
            actual = actual->siguientes[int(a.first[i])];
        }
    }
    if (actual->definicion == nullptr) {
        actual->definicion = new T(a.second);
    } else {
        delete actual->definicion;
        actual->definicion = new T(a.second);
    }


    _size++;
}



template <typename T>
int string_map<T>::count(const vector<char>& clave) const {
    Nodo *actual = raiz;
    for (int i = 0; i < clave.size(); i++) {
        if (actual->siguientes[int(clave[i])] == nullptr) {
            return 0;
        } else {
            Nodo *prox = actual->siguientes[int(clave[i])];
            actual = prox;

        }
    }
    if(actual->definicion == nullptr) {
        return 0;
    }
    else {
        return 1;
    }

}


template <typename T>
const T& string_map<T>::at(const string& clave) const {
    Nodo* actual = raiz;
    for (int i=0; i<clave.size(); i++) {
        actual  = actual->siguientes[int(clave[i])];
    }
    return *(actual->definicion);
}

template <typename T>
T& string_map<T>::at(const string& clave) {
    Nodo* actual = raiz;
    for (int i=0; i<clave.size(); i++) {
        actual  = actual->siguientes[int(clave[i])];
    }
    return *(actual->definicion);
}


template <typename T>
void string_map<T>::erase(const string& clave) {
    Nodo *actual = raiz;
    for (int i = 0; i < clave.size(); i++) {
        actual = actual->siguientes[int(clave[i])];
    }
    if (actual->hijos != 0) {
        delete(actual->definicion);
        actual->definicion = nullptr;
    } else {
        int tamano_palabra = 0;
        int indice = 0;
        actual = raiz;
        Nodo *ultimo = raiz;
        for (int i = 0; i < clave.size(); i++) {
            if (actual->hijos > 1) {
                ultimo = actual;
                indice = tamano_palabra;
            } else {
                actual = actual->siguientes[int(clave[i])];
                tamano_palabra++;
            }
        }
        borrarNodo(ultimo->siguientes[int(clave[indice])]);
        ultimo->siguientes[int(clave[indice])] = nullptr;

    }

    _size--;
}


template <typename T>
int string_map<T>::size() const{
    return _size;
}

template <typename T>
bool string_map<T>::empty() const{
    if(_size == 0){
        return true;
    }
    else{
        return false;
    }
}

template <typename T>
T& string_map<T>::operator[](const string& clave){
    // COMPLETAR
}
template <typename T>
int string_map<T>::PALABRAMASLARGA() {
    return lmax;
};


