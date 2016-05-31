//
// Created by kindas on 29/05/16.
//

#ifndef POO_LIST_H
#define POO_LIST_H

#include "cstdlib"
#include "../sources/nodelist.cpp"

template<class type>
class List {
    private:
    NodeList<type> *first;
    NodeList<type> *last;
    int size;

    public:
    List();

    void add(type *object);

    void remove(int index);

    void remove(type *object);

    type *get(int index);

    int getSize();

    bool contains(type *object);
};

#endif //POO_LIST_H