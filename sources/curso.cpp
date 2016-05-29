//
// Created by kindas on 29/05/16.
//

#include "../headers/curso.h"

Curso::Curso() {
    this->disciplinas = new List<Disciplina>();
    this->alunos = new List<Aluno>();
}

Curso::Curso(string descricao) {
    this->descricao = descricao;
    this->alunos = new List<Aluno>();
    this->disciplinas = new List<Disciplina>();
}

string Curso::getDescricao() {
    return this->descricao;
}

void Curso::setDescricao(string descricao) {
    this->descricao = descricao;
}

List<Disciplina> *Curso::getDisciplinas() {
    return this->disciplinas;
}

List<Aluno> *Curso::getAlunos() {
    return this->alunos;
}