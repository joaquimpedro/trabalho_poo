//
// Created by kindas on 29/05/16.
//

#include "../headers/turma.h"

Turma::Turma() {
    this->alunos = new List<Aluno>();
}

Turma::Turma(string descricao, Disciplina *disciplina) {
    this->descricao = descricao;
    this->disciplina = disciplina;
    this->alunos = new List<Aluno>();
}

string Turma::getDescricao() {
    return this->descricao;
}

void Turma::setDescricao(string descricao) {
    this->descricao = descricao;
}

List<Aluno> *Turma::getAlunos() {
    return this->alunos;
}

Disciplina *Turma::getDisciplina() {
    return this->disciplina;
}