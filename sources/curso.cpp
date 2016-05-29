//
// Created by kindas on 29/05/16.
//

#include "../headers/curso.h"

Curso::Curso() {
    this->disciplinas = new List<Disciplina>();
}

Curso::Curso(string descricao) {
    this->descricao = descricao;
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