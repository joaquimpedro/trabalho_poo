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
        cout << (i + 1) << " - " << universidade->getSetores()->get(i)->getDescricao() << endl;
    }
    cout << "0 - Cancelar" << endl;
    cin >> escolha;
    if (escolha == 0) {
        return;
    }

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
        cout << (i + 1) << " - " << universidade->getSetores()->get(i)->getDescricao() << endl;
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
        cout << " - " << funcionario->getNome() << " - " << funcionario->getIdade() << endl;
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
        cout << (i + 1) << " - " << universidade->getDisciplinas()->get(i)->getDescricao() << endl;
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
        Curso *curso = universidade->getCursos()->get(i);
        bool vinculada = curso->getDisciplinas()->contains(disciplina);
        cout << (i + 1) << (vinculada ? " - (Já Vinculada) " : " - ") << curso->getDescricao() << endl;
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
        cout << (i + 1) << " - " << universidade->getCursos()->get(i)->getDescricao() << endl;
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
        cout << (i + 1) << " - " << curso->getDisciplinas()->get(i)->getDescricao() << endl;
    }
    cout << "0 - Cancelar" << endl;
    cin >> escolha;
    if (escolha == 0) {
        return;
    }

    string nome;
    cout << "Descricao da Turma: " << endl;
    cin >> nome;

    Disciplina *disciplina = curso->getDisciplinas()->get(escolha - 1);

    disciplina->getTurmas()->add(new Turma(nome, disciplina));
}

void criarAluno(Universidade *universidade) {
    cout << "Qual Curso: " << endl;
    int escolha = -1;
    for (int i = 0; i < universidade->getCursos()->getSize(); i++) {
        cout << (i + 1) << " - " << universidade->getCursos()->get(i)->getDescricao() << endl;
    }

    cout << "0 - Cancelar" << endl;
    cin >> escolha;
    if (escolha == 0) {
        return;
    }

    Curso *curso = universidade->getCursos()->get(escolha - 1);

    string nome;
    cout << "Nome: " << endl;
    cin >> nome;

    int idade;
    cout << "Idade: " << endl;
    cin >> idade;

    string matricula;
    cout << "Matricula: " << endl;
    cin >> matricula;

    Aluno *aluno = new Aluno(nome, idade, matricula);
    aluno->setCurso(curso);
    curso->getAlunos()->add(aluno);
    universidade->getAlunos()->add(aluno);
}

void vincularAlunoATurma(Universidade *universidade) {

    cout << "Qual Aluno: " << endl;
    int escolha = -1;
    for (int i = 0; i < universidade->getAlunos()->getSize(); i++) {
        Aluno *aluno = universidade->getAlunos()->get(i);
        cout << (i + 1) << " ( " << aluno->getCurso()->getDescricao() << " ) " << aluno->getNome() << endl;
    }

    cout << "0 - Cancelar" << endl;
    cin >> escolha;
    if (escolha == 0) {
        return;
    }

    Aluno *aluno = universidade->getAlunos()->get(escolha - 1);

    cout << "Qual Disciplina: " << endl;
    escolha = -1;
    for (int i = 0; i < aluno->getCurso()->getDisciplinas()->getSize(); i++) {
        bool vinculado = false;
        Disciplina *disciplina = aluno->getCurso()->getDisciplinas()->get(i);
        for (int j = 0; j < aluno->getTurmas()->getSize(); j++) {
            vinculado = aluno->getTurmas()->get(j)->getDisciplina() == disciplina;
            if (vinculado) {
                break;
            }
        }
        cout << (i + 1) << (vinculado ? " - (Já Vinculado) " : " - ") << disciplina->getDescricao() << endl;
    }

    cout << "0 - Cancelar" << endl;
    cin >> escolha;
    if (escolha == 0) {
        return;
    }

    Disciplina *disciplina = aluno->getCurso()->getDisciplinas()->get(escolha - 1);

    cout << "Qual Turma: " << endl;
    escolha = -1;
    for (int i = 0; i < disciplina->getTurmas()->getSize(); i++) {
        cout << (i + 1) << " - " << disciplina->getTurmas()->get(i)->getDescricao() << endl;
    }

    cout << "0 - Cancelar" << endl;
    cin >> escolha;
    if (escolha == 0) {
        return;
    }

    Turma *turma = disciplina->getTurmas()->get(escolha - 1);
    turma->getAlunos()->add(aluno);
    aluno->getTurmas()->add(turma);
}

void desvincularAlunoATurma(Universidade *universidade) {

    cout << "Qual Aluno: " << endl;
    int escolha = -1;
    for (int i = 0; i < universidade->getAlunos()->getSize(); i++) {
        Aluno *aluno = universidade->getAlunos()->get(i);
        cout << (i + 1) << " ( " << aluno->getCurso()->getDescricao() << " ) " << aluno->getNome() << endl;
    }

    cout << "0 - Cancelar" << endl;
    cin >> escolha;
    if (escolha == 0) {
        return;
    }

    Aluno *aluno = universidade->getAlunos()->get(escolha - 1);

    cout << "Qual Turma: " << endl;
    escolha = -1;
    for (int i = 0; i < aluno->getTurmas()->getSize(); i++) {
        cout << (i + 1) << " - " << aluno->getTurmas()->get(i)->getDescricao() << endl;
    }

    cout << "0 - Cancelar" << endl;
    cin >> escolha;
    if (escolha == 0) {
        return;
    }

    Turma *turma = aluno->getTurmas()->get(escolha - 1);
    aluno->getTurmas()->remove(turma);
    turma->getAlunos()->remove(aluno);
}

void listarDadosDoAluno(Universidade *universidade) {
    cout << "Qual Aluno: " << endl;
    int escolha = -1;
    for (int i = 0; i < universidade->getAlunos()->getSize(); i++) {
        Aluno *aluno = universidade->getAlunos()->get(i);
        cout << (i + 1) << " ( " << aluno->getCurso()->getDescricao() << " ) " << aluno->getNome() << endl;
    }

    cout << "0 - Cancelar" << endl;
    cin >> escolha;
    if (escolha == 0) {
        return;
    }

    Aluno *aluno = universidade->getAlunos()->get(escolha - 1);

    cout << "O " << aluno->getNome() << " está matriculado no curso " << aluno->getCurso()->getDescricao() << endl;

    if (aluno->getTurmas()->getSize() > 0) {

        cout << "O aluno está nas seguintes turmas: ";

        for (int i = 0; i < aluno->getTurmas()->getSize(); i++) {
            cout << ", " << aluno->getTurmas()->get(i)->getDescricao();
        }
        cout << endl;
    } else {
        cout << "O aluno não está vinculado a nenhuma turma: ";
    }
}

void listarAlunosDoCurso(Universidade *universidade) {
    cout << "Qual Curso: " << endl;
    int escolha = -1;
    for (int i = 0; i < universidade->getCursos()->getSize(); i++) {
        cout << (i + 1) << " - " << universidade->getCursos()->get(i)->getDescricao() << endl;
    }

    cout << "0 - Cancelar" << endl;
    cin >> escolha;
    if (escolha == 0) {
        return;
    }

    Curso *curso = universidade->getCursos()->get(escolha - 1);

    if (curso->getAlunos()->getSize() == 0) {
        cout << "Não há alunos no curso: " << curso->getDescricao() << endl;
        return;
    }

    cout << "O curso " << curso->getDescricao() << " possui os seguintes alunos:" << endl;
    for (int i = 0; i < curso->getAlunos()->getSize(); i++) {
        Aluno *aluno = curso->getAlunos()->get(i);
        cout << "Nome: " << aluno->getNome() << " - Matricula: " << aluno->getMatricula() << endl;
    }
}

void listarCursos(Universidade *universidade) {
    if (universidade->getCursos()->getSize() == 0) {
        cout << "A " << universidade->getDescricao() << " não possui cursos" << endl;
        return;
    }
    cout << "A " << universidade->getDescricao() << " possui os seguintes cursos" << endl;
    for (int i = 0; i < universidade->getCursos()->getSize(); i++) {
        cout << universidade->getCursos()->get(i)->getDescricao() << endl;
    }
}

void listarAlunosQueCursamUmaDisciplina(Universidade *universidade) {
    if (universidade->getDisciplinas()->getSize() == 0) {
        cout << "A " << universidade->getDescricao() << " não possui disciplinas" << endl;
        return;
    }

    cout << "Qual Disciplina: " << endl;
    int escolha = -1;
    for (int i = 0; i < universidade->getDisciplinas()->getSize(); i++) {
        cout << (i + 1) << " - " << universidade->getDisciplinas()->get(i)->getDescricao() << endl;
    }

    cout << "0 - Cancelar" << endl;
    cin >> escolha;
    if (escolha == 0) {
        return;
    }

    Disciplina *disciplina = universidade->getDisciplinas()->get(escolha - 1);

    if (disciplina->getTurmas()->getSize() == 0) {
        cout << "A " << disciplina->getDescricao() << " não possui turmas" << endl;
        return;
    }

    cout << "Os alunos de " << disciplina->getDescricao() << " são:" << endl;

    for (int i = 0; i < disciplina->getTurmas()->getSize(); i++) {
        Turma *turma = disciplina->getTurmas()->get(i);
        for (int j = 0; j < turma->getAlunos()->getSize(); j++) {
            Aluno *aluno = turma->getAlunos()->get(j);
            cout << " ( " << aluno->getCurso()->getDescricao() << " ) " << aluno->getNome() << endl;
        }
    }
}

void mokarDados(Universidade *universidade) {
    Setor *nati = new Setor("NATI");
    Setor *nami = new Setor("NAMI");
    Setor *cozinha = new Setor("COZINHA");

    Funcionario *joao = new Funcionario("João", 1, 1);
    Funcionario *joana = new Funcionario("joana", 1, 1);
    Funcionario *dark = new Funcionario("dark", 1, 1);
    Funcionario *zezim = new Funcionario("Zezim", 1, 1);
    Funcionario *tiririca = new Funcionario("Tiririca", 1, 1);
    Funcionario *dilma = new Funcionario("Dilma", 1, 1);

    nati->getFuncionarios()->add(joana);
    nati->getFuncionarios()->add(zezim);
    nami->getFuncionarios()->add(dark);
    nami->getFuncionarios()->add(joao);
    nami->getFuncionarios()->add(tiririca);
    cozinha->getFuncionarios()->add(dilma);

    Curso *curso_eng = new Curso("ENG_COMPUTAÇÃO");
    Curso *curso_ciencia = new Curso("CIÊNCIA_COMPUTAÇÃO");

    Disciplina *disciplina_calculo = new Disciplina("Calculo");
    Disciplina *disciplina_poo = new Disciplina("POO");
    Disciplina *disciplina_micro = new Disciplina("Microcontroladores");

    Turma *calculo_eng_turma = new Turma("CALCULO_ENG_TURMA_1", disciplina_calculo);
    Turma *poo_eng_turma = new Turma("POO_ENG_TURMA_1", disciplina_poo);
    Turma *micro_eng_turma = new Turma("MICRO_ENG_TURMA_1", disciplina_micro);
    Turma *calculo_ciencia_turma = new Turma("CALCULO_CIENCIA_TURMA_1", disciplina_calculo);
    Turma *poo_ciencia_turma = new Turma("POO_CIENCIA_TURMA_1", disciplina_poo);

    disciplina_calculo->getTurmas()->add(calculo_ciencia_turma);
    disciplina_calculo->getTurmas()->add(calculo_eng_turma);
    disciplina_poo->getTurmas()->add(poo_ciencia_turma);
    disciplina_poo->getTurmas()->add(poo_eng_turma);
    disciplina_micro->getTurmas()->add(micro_eng_turma);

    curso_eng->getDisciplinas()->add(disciplina_calculo);
    curso_eng->getDisciplinas()->add(disciplina_poo);
    curso_eng->getDisciplinas()->add(disciplina_micro);

    curso_ciencia->getDisciplinas()->add(disciplina_calculo);
    curso_ciencia->getDisciplinas()->add(disciplina_poo);

    Aluno *aluno_joao = new Aluno("João", 1, "12101");
    Aluno *aluno_maria = new Aluno("Maria", 1, "12101");
    Aluno *aluno_xico = new Aluno("Xico", 1, "12101");

    aluno_joao->setCurso(curso_eng);
    aluno_maria->setCurso(curso_eng);
    aluno_xico->setCurso(curso_ciencia);

    curso_eng->getAlunos()->add(aluno_joao);
    curso_eng->getAlunos()->add(aluno_maria);
    curso_ciencia->getAlunos()->add(aluno_xico);

    calculo_ciencia_turma->getAlunos()->add(aluno_xico);
    poo_ciencia_turma->getAlunos()->add(aluno_xico);
    aluno_xico->getTurmas()->add(calculo_ciencia_turma);
    aluno_xico->getTurmas()->add(poo_ciencia_turma);

    calculo_eng_turma->getAlunos()->add(aluno_joao);
    poo_eng_turma->getAlunos()->add(aluno_joao);
    aluno_joao->getTurmas()->add(calculo_eng_turma);
    aluno_joao->getTurmas()->add(poo_eng_turma);

    calculo_eng_turma->getAlunos()->add(aluno_maria);
    poo_eng_turma->getAlunos()->add(aluno_maria);
    micro_eng_turma->getAlunos()->add(aluno_maria);
    aluno_maria->getTurmas()->add(calculo_eng_turma);
    aluno_maria->getTurmas()->add(poo_eng_turma);
    aluno_maria->getTurmas()->add(micro_eng_turma);

    universidade->getSetores()->add(nati);
    universidade->getSetores()->add(nami);
    universidade->getSetores()->add(cozinha);

    universidade->getCursos()->add(curso_eng);
    universidade->getCursos()->add(curso_ciencia);

    universidade->getDisciplinas()->add(disciplina_calculo);
    universidade->getDisciplinas()->add(disciplina_poo);
    universidade->getDisciplinas()->add(disciplina_micro);

    universidade->getAlunos()->add(aluno_joao);
    universidade->getAlunos()->add(aluno_maria);
    universidade->getAlunos()->add(aluno_xico);
}

int main() {

    Universidade *universidade = new Universidade;
    universidade->setDescricao("Unifor");
    universidade->setCnpj("0101/12121-0001-01");

    int escolhaMenuPrincipal = -1;
    while (escolhaMenuPrincipal != 0) {
        system("clear");

        cout << "1  - Criar setor" << endl;
        cout << "2  - Criar Funcionario" << endl;
        cout << "3  - Criar Curso" << endl;
        cout << "4  - Criar Disciplina" << endl;
        cout << "5  - Vincular Disciplina ao curso" << endl;
        cout << "6  - Criar Turma" << endl;
        cout << "7  - Criar Aluno" << endl;
        cout << "8  - Vincular Aluno a Turma" << endl;
        cout << "9  - Desvincular Aluno da Turma" << endl;
        cout << "10 - Exibir Informações do Aluno" << endl;
        cout << "11 - Listar Setores" << endl;
        cout << "12 - Listar Funcionarios de um setor" << endl;
        cout << "13 - Listar Cursos" << endl;
        cout << "14 - Listar Alunos do Curso" << endl;
        cout << "15 - Listar Alunos que Cursam Uma Disciplina" << endl;
        cout << "99 - Mokar dados" << endl;
        cout << "0  - Sair" << endl;

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
                vincularDisciplinaAoCurso(universidade);
                break;
            case 6:
                criarTurma(universidade);
                break;
            case 7:
                criarAluno(universidade);
                break;
            case 8:
                vincularAlunoATurma(universidade);
                break;
            case 9:
                desvincularAlunoATurma(universidade);
                break;
            case 10:
                listarDadosDoAluno(universidade);
                break;
            case 11: {
                cout << "A universidade tem os seguintes setores: " << endl;
                for (int i = 0; i < universidade->getSetores()->getSize(); i++) {
                    cout << universidade->getSetores()->get(i)->getDescricao() << endl;
                }
                break;
            }
            case 12:
                listarFuncionariosDoSetor(universidade);
                break;
            case 13:
                listarCursos(universidade);
                break;
            case 14:
                listarAlunosDoCurso(universidade);
                break;
            case 15:
                listarAlunosQueCursamUmaDisciplina(universidade);
                break;
            case 99: {
                mokarDados(universidade);
                break;
            }
        }
    }


    return 0;
}
