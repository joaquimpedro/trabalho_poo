//
// Created by kindas on 29/05/16.
//

#include "../headers/funcionario.h"


Funcionario::Funcionario() {
}

Funcionario::Funcionario(string nome, int idade, float salario) {
    this->setNome(nome);
    this->setIdade(idade);
    this->salario = salario;
}

float Funcionario::getSalario() {
    return this->salario;
}

void Funcionario::setSalario(float salario) {
    this->salario = salario;
}