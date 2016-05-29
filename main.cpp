#include <iostream>
#include "headers/universidade.h"

using namespace std;

void cadastrarSetor(Universidade *universidade) {
    string nome;
    cout << "Nome do Setor" << endl;
    cin >> nome;

    universidade->criarSetor(nome);
}

void cadastrarFuncionario(Universidade *universidade) {
    cout << "Qual setor: " << endl;
    int escolha = -1;
    for (int i = 0; i < universidade->getSetores()->getSize(); i++) {
        cout << (i + 1) << " " << universidade->getSetores()->get(i)->getDescricao() << endl;
    }
    cout << "0 - Cancelar" << endl;

    if (escolha == 0) {
        return;
    }

    cin >> escolha;
    string nome;
    int idade;
    float salario;
    cout << "Nome do Funcionario" << endl;
    cin >> nome;
    cout << "Idade do Funcionario" << endl;
    cin >> idade;
    cout << "Salario do Funcionario" << endl;
    cin >> salario;

    universidade->addFuncionarioAoSetor(new Funcionario(nome, idade, salario), escolha - 1);

}

void listarFuncionariosDoSetor(Universidade *universidade) {
    cout << "Qual setor: " << endl;
    int escolha = -1;
    for (int i = 0; i < universidade->getSetores()->getSize(); i++) {
        cout << (i + 1) << " " << universidade->getSetores()->get(i)->getDescricao() << endl;
    }
    cout << "0 - Cancelar" << endl;
    cin >> escolha;
    if (escolha == 0) {
        return;
    }

    Setor *setor = universidade->getSetores()->get(escolha - 1);
    cout << "O setor " << setor->getDescricao() << " tem os seguintes funcionários: " << endl;

    for (int i = 0; i < setor->getFuncionarios()->getSize(); i++) {
        Funcionario *funcionario = setor->getFuncionarios()->get(i);
        cout << " " << funcionario->getNome() << " - " << funcionario->getIdade() << endl;
    }

}

void criarCurso(Universidade *universidade) {
    string nome;
    cout << "Descricao do Curso: " << endl;
    cin >> nome;

    universidade->getCursos()->add(new Curso(nome));
}

void criarDisciplina(Universidade *universidade) {
    string nome;
    cout << "Descricao da Disciplina: " << endl;
    cin >> nome;

    universidade->getDisciplinas()->add(new Disciplina(nome));
}

void vincularDisciplinaAoCurso(Universidade *universidade) {
    cout << "Qual Disciplina: " << endl;
    int escolha = -1;
    for (int i = 0; i < universidade->getDisciplinas()->getSize(); i++) {
        cout << (i + 1) << " " << universidade->getDisciplinas()->get(i)->getDescricao() << endl;
    }
    cout << "0 - Cancelar" << endl;
    cin >> escolha;
    if (escolha == 0) {
        return;
    }

    Disciplina *disciplina = universidade->getDisciplinas()->get(escolha - 1);

    cout << "Qual Curso: " << endl;
    escolha = -1;
    for (int i = 0; i < universidade->getCursos()->getSize(); i++) {
        cout << (i + 1) << " " << universidade->getCursos()->get(i)->getDescricao() << endl;
    }

    cout << "0 - Cancelar" << endl;
    cin >> escolha;
    if (escolha == 0) {
        return;
    }
    Curso *curso = universidade->getCursos()->get(escolha - 1);
    curso->getDisciplinas()->add(disciplina);
}

void criarTurma(Universidade *universidade) {
    cout << "Qual Curso: " << endl;
    int escolha = -1;
    for (int i = 0; i < universidade->getCursos()->getSize(); i++) {
        cout << (i + 1) << " " << universidade->getCursos()->get(i)->getDescricao() << endl;
    }

    cout << "0 - Cancelar" << endl;
    cin >> escolha;
    if (escolha == 0) {
        return;
    }

    Curso *curso = universidade->getCursos()->get(escolha - 1);

    cout << "Qual Disciplina: " << endl;
    escolha = -1;
    for (int i = 0; i < curso->getDisciplinas()->getSize(); i++) {
        cout << (i + 1) << " " << curso->getDisciplinas()->get(i)->getDescricao() << endl;
    }
    cout << "0 - Cancelar" << endl;
    cin >> escolha;
    if (escolha == 0) {
        return;
    }

    string nome;
    cout << "Descricao da Turma: " << endl;
    cin >> nome;

    curso->getDisciplinas()->get(escolha - 1)->getTurmas()->add(new Turma(nome));
}


int main() {

    Universidade *universidade = new Universidade;
    universidade->setDescricao("Unifor");
    universidade->setCnpj("0101/12121-0001-01");

    int escolhaMenuPrincipal = -1;
    while (escolhaMenuPrincipal != 0) {
        system("clear");

        cout << "1 - Criar setor" << endl;
        cout << "2 - Criar Funcionario" << endl;
        cout << "3 - Criar Curso" << endl;
        cout << "4 - Criar Disciplina" << endl;
        cout << "5 - Criar Turma" << endl;
        cout << "6 - Criar Aluno" << endl;
        cout << "7 - Listar Setores" << endl;
        cout << "8 - Listar Funcionarios de um setor" << endl;
        cout << "0 - Sair" << endl;

        cin >> escolhaMenuPrincipal;

        system("clear");

        switch (escolhaMenuPrincipal) {
            case 1:
                cadastrarSetor(universidade);
                break;
            case 2:
                cadastrarFuncionario(universidade);
                break;
            case 3:
                criarCurso(universidade);
                break;
            case 4:
                criarDisciplina(universidade);
                break;
            case 5:
                criarTurma(universidade);
                break;
            case 6:
                vincularDisciplinaAoCurso(universidade);
                break;
            case 7:
                //criarAluno(universidade);
                break;
            case 8:
                //criarAluno(universidade);
                break;
            case 9: {
                cout << "A universidade tem os seguintes setores: " << endl;
                for (int i = 0; i < universidade->getSetores()->getSize(); i++) {
                    cout << universidade->getSetores()->get(i)->getDescricao() << endl;
                }
                break;
            }
            case 10:
                listarFuncionariosDoSetor(universidade);
                break;

        }

    }


    return 0;
}
