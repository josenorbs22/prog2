#ifndef CLUBE_HPP
#define CLUBE_HPP

#include "pessoa.hpp"

class Clube{
    private:
        Pessoa m_presidente;
        int m_registro;
        string m_endereco;
        string m_nome;
    public:
        Clube(){};
        Clube(Pessoa presidente, int registro, string endereco, string nome) : m_presidente(presidente), m_registro(registro), m_endereco(endereco), m_nome(nome){};
        ~Clube(){};

        Pessoa GetPresidente() const { return m_presidente; };
        void SetPresidente(Pessoa presidente) { m_presidente = presidente; };
        int GetRegistro() const { return m_registro; };
        void SetRegistro(int registro) { m_registro = registro; };
        string GetEndereco() const { return m_endereco; };
        void SetEndereco(string endereco) { m_endereco = endereco; };
        string GetNome() const { return m_nome; };
        void SetNome(string nome) { m_nome = nome; };
};

#endif