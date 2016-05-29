//
// Created by kindas on 29/05/16.
//

#ifndef POO_SETOR_H
#define POO_SETOR_H

#include "funcionario.h"
#include "list.h"
#include <string>

using std::string;

class Funcionario;

class Setor {

    private:
    string descricao;
    List<Funcionario> *funcionarios;

    public:
    Setor();

    Setor(string descricao);

    string getDescricao();

    void setDescricao(string descricao);

    List<Funcionario> *getFuncionarios();

};


#endif //POO_SETOR_H