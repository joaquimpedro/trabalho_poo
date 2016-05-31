//
// Created by kindas on 29/05/16.
//

#ifndef POO_TURMA_H
#define POO_TURMA_H

#include <string>
#include "list.h"
#include "aluno.h"
#include "disciplina.h"

using std::string;

class Aluno;

class Disciplina;

class Turma {

    private:
    string descricao;
    List<Aluno> *alunos;
    Disciplina *disciplina;

    public:
    Turma();

    Turma(string descricao, Disciplina *disciplina);

    string getDescricao();

    void setDescricao(string descricao);

    List<Aluno> *getAlunos();

    Disciplina *getDisciplina();

};


#endif //POO_TURMA_H
