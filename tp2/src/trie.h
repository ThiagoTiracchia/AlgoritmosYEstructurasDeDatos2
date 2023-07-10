#ifndef STRING_MAP_H_
#define STRING_MAP_H_

#include <string>

using namespace std;

template<typename T>
class string_map {
public:
    string_map();

    string_map(const string_map<T>& aCopiar);

    string_map& operator=(const string_map& d);

    ~string_map();

    void insert(const pair<vector<char>, T >& a);

    int count(const vector<char> &key) const;

    const T& at(const string& key) const;

    T& at(const string& key);

    void erase(const string& key);

    int size() const;

    bool empty() const;

    T &operator[](const string &key);

    int   PALABRAMASLARGA();

private:

    struct Nodo {
        vector<Nodo*> siguientes;
        T* definicion;
        int hijos;
        Nodo() : siguientes(256,nullptr),definicion(nullptr),hijos(0){};
        Nodo(T* def) : siguientes(256,nullptr),definicion(def),hijos(0){};

    };
   int lmax = 0 ;
    Nodo* raiz;
    int _size;
    void borrarNodo(Nodo* n);
    Nodo* copiar(Nodo* n){
        Nodo* aux = new Nodo();
        if (n->definicion != nullptr){
            aux->definicion = new T(*(n->definicion));
        }
        for (int i = 0; i < n->siguientes.size(); i++) {
            if (n->siguientes[i] != nullptr) {
                aux->siguientes[i] = copiar(n->siguientes[i]);
            }
        }
        return aux;
    }
};

#include "trie.hpp"

#endif // STRING_MAP_H_
