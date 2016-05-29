//
// Created by kindas on 29/05/16.
//

#ifndef POO_DISCIPLINA_H
#define POO_DISCIPLINA_H

#include <string>
#include "list.h"
#include "turma.h"

using std::string;

class Turma;

class Disciplina {

    private:
    string descricao;
    List<Turma> *turmas;

    public:
    Disciplina();

    Disciplina(string descricao);

    string getDescricao();

    void setDescricao(string descricao);

    List<Turma> *getTurmas();

};


#endif //POO_DISCIPLINA_H
