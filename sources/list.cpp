//
// Created by kindas on 29/05/16.
//

#include "../headers/list.h"
#include "../headers/aluno.h"
#include "../headers/funcionario.h"

template<class type>
List<type>::List() {
    this->size = 0;
    this->first = NULL;
    this->last = NULL;
}

template<class type>
void List<type>::add(type *object) {
    if (this->first == NULL) {
        NodeList<type> *node = new NodeList<type>(object, 0);
        this->first = node;
        this->last = node;
    } else {
        NodeList<type> *node = new NodeList<type>(object, this->last->getIndex() + 1);
        node->setPrevious(this->last);
        this->last->setNext(node);
        this->last = node;
    }
    
    this->size = this->last->getIndex() + 1;
}

template<class type>
void List<type>::remove(int index) {
    NodeList<type> *node = first;
    while (node->getIndex() != index && node->getIndex() < this->size - 1) {
        node = node->getNext();
    }

    if (node->getObject() == first->getObject()) {

        if (node->getNext() == NULL) {
            this->first = NULL;
            this->last = NULL;
            return;
        }

        first = node->getNext();
        first->setIndex(0);
    } else if (node->getObject() == last->getObject()) {
        last = node->getPrevious();
        last->setNext(NULL);
    } else {
        node->getPrevious()->setNext(node->getNext());
    }

    delete node;
    this->size--;

    node = first;
    while (node->getNext() != NULL) {
        node->getNext()->setIndex(node->getIndex() + 1);
        node = node->getNext();
    }
}


template<class type>
void List<type>::remove(type *object) {
    NodeList<type> *node = this->first;
    int indexCount = 0;
    while (indexCount < this->size) {
        if (node->getObject() == object) {
            remove(node->getIndex());
            return;
        }
        node = node->getNext();
        indexCount++;
    }
}

template<class type>
type *List<type>::get(int index) {
    if (index < 0 || index >= this->getSize()) {
        return NULL;
    }
    
    NodeList<type> *node = this->first;
    while (node->getIndex() != index && node->getNext() != NULL) {
        node = node->getNext();
    }
    
    if (node->getIndex() == index) {
        return node->getObject();
    } else {
        return NULL;
    }
}

template<class type>
int List<type>::getSize() {
    return this->size;
}

template<class type>
bool List<type>::contains(type *object) {
    NodeList<type> *node = this->first;
    int indexCount = 0;
    while (indexCount < this->size) {
        if (node->getObject() == object) {
            return true;
        }
        node = node->getNext();
        indexCount++;
    }
    return false;
}

class Aluno;

class Curso;

class Disciplina;

class Funcionario;

class Setor;

class Turma;

template
class List<Aluno>;

template
class List<Curso>;

template
class List<Disciplina>;

template
class List<Funcionario>;

template
class List<Setor>;

template
class List<Turma>;

