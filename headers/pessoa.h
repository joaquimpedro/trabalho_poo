#ifndef POO_PESSOA_H
#define POO_PESSOA_H

#include <string>

using std::string;

class Pessoa {

    private:
    string nome;
    string documento;
    int idade;


    public:
    string getNome();

    void setNome(string nome);

    int getIdade();

    void setIdade(int idade);
};

#endif //POO_PESSOA_H
