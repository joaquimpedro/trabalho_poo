//
// Created by kindas on 29/05/16.
//

#include "../headers/nodelist.h"

template<class type>
NodeList<type>::NodeList(type *object, int index) {
    this->object = object;
    this->index = index;
    this->previous = NULL;
    this->next = NULL;
}

template<class type>
type *NodeList<type>::getObject() {
    return this->object;
}

template<class type>
int NodeList<type>::getIndex() {
    return this->index;
}

template<class type>
NodeList<type> *NodeList<type>::getNext() {
    return this->next;
}

template<class type>
void NodeList<type>::setNext(NodeList<type> *node) {
    this->next = node;
}

template<class type>
NodeList<type> *NodeList<type>::getPrevious() {
    return this->previous;
}

template<class type>
void NodeList<type>::setPrevious(NodeList<type> *node) {
    this->previous = node;
}

template<class type>
void NodeList<type>::setIndex(int index) {
    this->index = index;
}