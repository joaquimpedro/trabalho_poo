#ifndef POO_UNIVERSIDADE_H
#define POO_UNIVERSIDADE_H

#include <string>
#include "list.h"
#include "setor.h"
#include "curso.h"

using std::string;


class Universidade {

    private:
    string descricao;
    string cnpj;
    List<Setor> *setores;
    List<Curso> *cursos;
    List<Disciplina> *disciplinas;

    public:
    Universidade();

    string getDescricao();

    void setDescricao(string descricao);

    string getCnpj();

    void setCnpj(string cnpj);

    List<Setor> *getSetores();

    Setor *criarSetor(string descricao);

    void addFuncionarioAoSetor(Funcionario *funcionario, int indexSetor);

    List<Curso> *getCursos();

    List<Disciplina> *getDisciplinas();


};


#endif //POO_UNIVERSIDADE_H
