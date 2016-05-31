//
// Created by kindas on 29/05/16.
//

#include "../headers/aluno.h"

Aluno::Aluno() {
    this->turmas = new List<Turma>();
}

Aluno::Aluno(string nome, int idade, string matricula) {
    this->setNome(nome);
    this->setIdade(idade);
    this->matricula = matricula;
    this->turmas = new List<Turma>();
}

string Aluno::getMatricula() {
    return this->matricula;
}

void Aluno::setMatricula(string matricula) {
    this->matricula = matricula;
}

Curso *Aluno::getCurso() {
    return this->curso;
}

void Aluno::setCurso(Curso *curso) {
    this->curso = curso;
}

List<Turma> *Aluno::getTurmas() {
    return this->turmas;
}
