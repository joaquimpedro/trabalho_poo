//
// Created by kindas on 29/05/16.
//

#include "../headers/disciplina.h"

Disciplina::Disciplina() {
    this->turmas = new List<Turma>();
}

Disciplina::Disciplina(string descricao) {
    this->descricao = descricao;
    this->turmas = new List<Turma>();
}

string Disciplina::getDescricao() {
    return this->descricao;
}

void Disciplina::setDescricao(string descricao) {
    this->descricao = descricao;
}

List<Turma> *Disciplina::getTurmas() {
    return this->turmas;
}

