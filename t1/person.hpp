#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct personPF{
    string nome;
    string nomeMae;
    string cpf;
    string endereco;
    string telefone;
};

struct personPJ{
    string razaoSocial;
    string cnpj;
    string endereco;
    string telefone;
    size_t capitalSocial;
};

bool SaveDatabase(string filename, const vector<personPF> &listPF, const vector<personPJ> &listPJ);

bool LoadDatabase(string filename, vector<personPF> &listPF, vector<personPJ> &listPJ);

bool DeletePF(string filename, vector<personPF> &listPF, int pos);

bool DeletePJ(string filename, vector<personPJ> &listPJ, int pos);

vector<string> SortNames(const vector<personPF> &listPF, const vector<personPJ> &listPJ);

#endif