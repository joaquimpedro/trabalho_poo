//
// Created by kindas on 29/05/16.
//

#include "../headers/aluno.h"

Aluno::Aluno() {

}

Aluno::Aluno(string nome, int idade, string matricula) {
    this->setNome(nome);
    this->setIdade(idade);
    this->matricula = matricula;
}

string Aluno::getMatricula() {
    this->matricula;
}

void Aluno::setMatricula(string matricula) {
    this->matricula = matricula;
}