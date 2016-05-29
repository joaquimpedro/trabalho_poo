//
// Created by kindas on 29/05/16.
//

#ifndef POO_TURMA_H
#define POO_TURMA_H

#include <string>
#include "list.h"
#include "aluno.h"

using std::string;

class Aluno;

class Turma {

    private:
    string descricao;
    List<Aluno> *alunos;

    public:
    Turma();

    Turma(string descricao);

    string getDescricao();

    void setDescricao(string descricao);

    List<Aluno> *getAlunos();

};


#endif //POO_TURMA_H
