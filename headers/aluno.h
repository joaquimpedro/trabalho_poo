//
// Created by kindas on 29/05/16.
//

#ifndef POO_ALUNO_H
#define POO_ALUNO_H


#include "pessoa.h"
#include "curso.h"
#include "list.h"
#include "turma.h"

class Curso;

class Turma;

class Aluno : public Pessoa {

    private:
    string matricula;
    Curso *curso;
    List<Turma> *turmas;

    public:
    Aluno();

    Aluno(string nome, int idade, string matricula);

    string getMatricula();

    void setMatricula(string matricula);

    Curso *getCurso();

    void setCurso(Curso *curso);

    List<Turma> *getTurmas();

};


#endif //POO_ALUNO_H
