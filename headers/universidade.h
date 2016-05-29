#ifndef POO_UNIVERSIDADE_H
#define POO_UNIVERSIDADE_H

#include <string>
#include "list.h"
#include "setor.h"
#include "curso.h"
#include "aluno.h"

using std::string;


class Universidade {

    private:
    string descricao;
    string cnpj;
    List<Setor> *setores;
    List<Curso> *cursos;
    List<Disciplina> *disciplinas;
    List<Aluno> *alunos;

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

    List<Aluno> *getAlunos();


};


#endif //POO_UNIVERSIDADE_H
