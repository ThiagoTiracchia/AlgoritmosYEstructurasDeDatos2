#ifndef ALGO2_LABO_CLASE5_ALGORITMOS_H
#define ALGO2_LABO_CLASE5_ALGORITMOS_H

#include <utility>
#include <iterator>
#include <vector>

template<class Contenedor>
typename Contenedor::value_type minimo(const Contenedor& c){
    typename Contenedor::const_iterator it  = c.begin();
    auto min = *it;

    for (auto elem = it ; elem != c.end() ; ++elem){
        if (*elem < min) {
            min = *elem;
        }

    }
    return min;
}

template<class Contenedor>
typename Contenedor::value_type promedio(const Contenedor& c){
    typename Contenedor::const_iterator it  = c.begin();
    typename Contenedor::value_type  suma = 0;
    int cant = 0;
    for (auto elem = it ; elem != c.end() ; ++elem){
        cant++;
        suma = suma + *elem;
    }
    return suma/cant;
}






template<class Iterator>
typename Iterator::value_type minimoIter(const Iterator& desde, const Iterator&  hasta){

    auto min = *desde;

    for (auto it = desde ; it != hasta ; it ++  ){
        if (*it < min) {
            min = *it;
        }

    }
    return min;

}

template<class Iterator>
typename Iterator::value_type promedioIter(const Iterator& desde, const Iterator& hasta ) {

    typename Iterator::value_type suma = 0;
    int cant = 0;
    for (auto it = desde ; it != hasta ; it ++  ){
        cant++;
        suma = suma + *it;
    }


    return suma/cant;


}


template<class Contenedor>
void filtrar(Contenedor &c, const typename Contenedor::value_type& elem){
    typename Contenedor::iterator it  = c.begin();

    for (auto x = it ; x != c.end() ; x++){
        if(*x == elem){
            x = c.erase(x);
            x--;
        }
    }
}

template<class Contenedor>
bool ordenado(Contenedor &c) {
    bool res = true;
    for (auto it = c.begin();it != c.end()--;it++) {
        auto a = *it;
        it++;
        auto b = *it;
        res = (a<=b) && res;
    }
    return res; //raro
}


template<class Contenedor>
std::pair<Contenedor, Contenedor>
split(const Contenedor & c,
      const typename Contenedor::value_type& elem){
    std :: pair<Contenedor, Contenedor> res;
    typename Contenedor :: iterator a = (res.first).begin();
    typename Contenedor :: iterator b = (res.second).begin();
    for (auto it = c.begin();it!=c.end();it++) {
        if (*it<elem) {
            a = (res.first).insert(a,*it);
            a++;
        }
        else {
            b= (res.second).insert(b,*it);
            b++;
        }
    }
    return res;
}


template <class Contenedor>
void merge(const Contenedor& c1, const Contenedor & c2, Contenedor & res){

    auto in1 = c1.begin();
    auto in2 = c2.begin();
    auto resin = res.begin();


    while (in1!=c1.end() && in2!=c2.end()) {
        if (*in1<=*in2) {
            resin = res.insert(resin,*in1);
            in1++;
            resin++;
        }
        else {
            resin = res.insert(resin,*in2);
            in2++;
            resin++;
        }
    }

    if (in1==c1.end()) {
        while (in2 != c2.end()) {
            resin = res.insert(resin,*in2);
            in2++;
            resin++;
        }
    }
    if (in2==c2.end()) {
        while (in1 != c1.end()) {
            resin = res.insert(resin,*in1);
            in1++;
            resin++;
        }
    }

}



#endif //ALGO2_LABO_CLASE5_ALGORITMOS_H
