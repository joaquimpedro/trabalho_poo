#include <iostream>
#include "pessoa.h"
#include "list.cpp"

using namespace std;

int main() {
    Pessoa *pedro = new Pessoa();
    pedro->setIdade(23);
    pedro->setNome("Joaquim Pedro");

    Pessoa *bea = new Pessoa();
    bea->setIdade(22);
    bea->setNome("B. Bottai");

    Pessoa *barbara = new Pessoa();
    barbara->setIdade(27);
    barbara->setNome("Babara");

    Pessoa *ismael = new Pessoa();
    ismael->setIdade(23);
    ismael->setNome("Ismael");

    List<Pessoa> *pessoas = new List<Pessoa>();
    pessoas->add(pedro);
    pessoas->add(bea);
    pessoas->add(ismael);
    pessoas->add(barbara);

    int count = 0;
    while (count < pessoas->getSize()) {
        Pessoa *p = pessoas->get(count);
        cout << "A pessoa " << p->getNome() << " tem " << p->getIdade() << " anos!" << endl;
        count++;
    }

    cout << "--------------------------------------------------------------" << endl;
    pessoas->remove(2);

    count = 0;
    while (count < pessoas->getSize()) {
        Pessoa *p = pessoas->get(count);
        cout << "A pessoa " << p->getNome() << " tem " << p->getIdade() << " anos!" << endl;
        count++;
    }

    if (pessoas->contains(pedro)) {
        cout << "A pessoa existe " << endl;
    } else {
        cout << "A pessoa não existe " << endl;
    }

    return 0;
}