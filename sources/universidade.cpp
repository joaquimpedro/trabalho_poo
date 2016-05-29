#include "../headers/universidade.h"

Universidade::Universidade() {
    this->setores = new List<Setor>;
    this->cursos = new List<Curso>;
    this->disciplinas = new List<Disciplina>();
    this->alunos = new List<Aluno>();
}

string Universidade::getDescricao() {
    return this->descricao;
}

void Universidade::setDescricao(string descricao) {
    this->descricao = descricao;
}

string Universidade::getCnpj() {
    return this->cnpj;
}

void Universidade::setCnpj(string cnpj) {
    this->cnpj = cnpj;
}

List<Setor> *Universidade::getSetores() {
    return this->setores;
}

Setor *Universidade::criarSetor(string descricao) {
    this->setores->add(new Setor(descricao));
}

void Universidade::addFuncionarioAoSetor(Funcionario *funcionario, int indexSetor) {
    this->setores->get(indexSetor)->getFuncionarios()->add(funcionario);
}

List<Curso> *Universidade::getCursos() {
    return this->cursos;
}

List<Disciplina> *Universidade::getDisciplinas() {
    return this->disciplinas;
}

List<Aluno> *Universidade::getAlunos() {
    return this->alunos;
}


