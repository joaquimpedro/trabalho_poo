//
// Created by kindas on 29/05/16.
//

#ifndef POO_FUNCIONARIO_H
#define POO_FUNCIONARIO_H


#include "setor.h"
#include "pessoa.h"
#include <string>

using std::string;

class Funcionario : public Pessoa {

    private:
    float salario;

    public:
    Funcionario();

    Funcionario(string nome, int idade, float salario);

    float getSalario();

    void setSalario(float salario);


};


#endif //POO_FUNCIONARIO_H
