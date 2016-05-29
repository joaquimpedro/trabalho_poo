//
// Created by kindas on 29/05/16.
//

#ifndef POO_CURSO_H
#define POO_CURSO_H

#include <string>
#include "list.h"
#include "disciplina.h"

using std::string;

class Disciplina;

class Curso {

    private:
    string descricao;
    List<Disciplina> *disciplinas;

    public:
    Curso();

    Curso(string descricao);

    string getDescricao();

    void setDescricao(string descricao);

    List<Disciplina> *getDisciplinas();

};


#endif //POO_CURSO_H
