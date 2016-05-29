//
// Created by kindas on 29/05/16.
//

#ifndef POO_NODELIST_H
#define POO_NODELIST_H

#include "cstdlib"

template<class type>
class NodeList {
    private:
    type *object;
    int index;
    NodeList *previous;
    NodeList *next;

    public:
    NodeList(type *object, int index);

    type *getObject();

    int getIndex();

    NodeList *getNext();

    void setNext(NodeList<type> *node);

    NodeList *getPrevious();

    void setPrevious(NodeList<type> *node);

    void setIndex(int index);
};


#endif //POO_NODELIST_H
