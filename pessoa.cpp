#include "pessoa.h"

string Pessoa::getNome() {
    return this->nome;
}

void Pessoa::setNome(string nome) {
    this->nome = nome;
}

int Pessoa::getIdade() {
    return this->idade;
}

void Pessoa::setIdade(int idade) {
    this->idade = idade;
}