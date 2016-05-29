//
// Created by kindas on 29/05/16.
//

#include "../headers/setor.h"

Setor::Setor() {
    this->funcionarios = new List<Funcionario>();
}

Setor::Setor(string descricao) {
    this->descricao = descricao;
    this->funcionarios = new List<Funcionario>();
}

string Setor::getDescricao() {
    return this->descricao;
}

void Setor::setDescricao(string descricao) {
    this->descricao = descricao;
}

List<Funcionario> *Setor::getFuncionarios() {
    return this->funcionarios;
}
