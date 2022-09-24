#ifndef PESSOA_HPP
#define PESSOA_HPP

#include <iostream>
#include <vector>
#include <tuple>
#include <fstream>

using namespace std;

class Pessoa{
    private:
        string m_nome;
        string m_apelido;
        int m_contrato;
        bool m_ativo;
    public:
        Pessoa() : m_nome(""), m_apelido(""), m_contrato(0), m_ativo(false){};
        Pessoa(string nome, string apelido, int contrato, bool ativo) : m_nome(nome), m_apelido(apelido), m_contrato(contrato), m_ativo(ativo) {};
        ~Pessoa(){};

        string GetNome() const { return m_nome; };
        void SetNome(string nome) { m_nome = nome; };
        string GetApelido() const { return m_apelido; };
        void SetApelido(string apelido) { m_apelido = apelido; };
        int GetContrato() { return m_contrato; };
        void SetContrato(int contrato) { m_contrato = contrato; };
        bool GetAtivo() const { return m_ativo; };
        void SetAtivo(bool ativo) { m_ativo = ativo; };
};

bool SavePessoas(const vector<Pessoa*> &v_pessoas);
void LoadPessoas(vector<Pessoa*> &v_pessoas);
bool AcharPessoa(string nomePessoa, Pessoa* &pessoaDesativada, const vector<Pessoa*> &v_pessoas);

#endif