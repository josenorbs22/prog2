#ifndef TIME_HPP
#define TIME_HPP

#include "pessoa.hpp"
#include "clube.hpp"

class TimeFutebol : public Clube{
    private:
        Pessoa m_diretor;
        vector< pair<string, Pessoa> > m_jogadores;
        int m_nTitulos;
    public:
        TimeFutebol() : m_diretor(Pessoa()), m_jogadores({}), m_nTitulos(0){};
        TimeFutebol(Pessoa diretor, vector< pair<string, Pessoa> > jogadores, int nTitulos) : m_diretor(diretor), m_jogadores(jogadores), m_nTitulos(nTitulos){};
        ~TimeFutebol(){};

        Pessoa GetDiretor() const { return m_diretor; };
        void SetDiretor(Pessoa diretor) { m_diretor = diretor; };
        vector<pair<string, Pessoa>> GetJogadores() const { return m_jogadores; };
        void SetJogadores(vector<pair<string, Pessoa>> jogadores) { m_jogadores = jogadores; };
        int GetNTitulos() const { return m_nTitulos; };
        void SetNTitulos(int nTitulos) { m_nTitulos = nTitulos; };
};

class TimeESport : public Clube{
    private:
        string m_nomeJogo;
        Pessoa m_manager;
        vector< pair<string, Pessoa> > m_jogadores;
        bool m_gHO;
    public:
        TimeESport() : m_nomeJogo(""), m_manager(Pessoa()), m_jogadores({}), m_gHO(false) {};
        TimeESport(string nomeJogo, Pessoa manager, vector< pair<string, Pessoa> > jogadores, bool gHO) : m_nomeJogo(nomeJogo), m_manager(manager), m_jogadores(jogadores), m_gHO(gHO){};
        ~TimeESport(){};

        string GetNomeJogo() const { return m_nomeJogo; };
        void SetNomeJogo(string nomeJogo) { m_nomeJogo = nomeJogo; };
        Pessoa GetManager() const { return m_manager; };
        void SetManager(Pessoa manager) { m_manager = manager; };
        vector<pair<string, Pessoa>> GetJogadores() const { return m_jogadores; };
        void SetJogadores(vector<pair<string, Pessoa>> jogadores) { m_jogadores = jogadores; };
        bool GetGHO() const { return m_gHO; };
        void SetGHO(int gHO) { m_gHO = gHO; };
};

bool SaveClubes( const vector< tuple<Clube*, TimeFutebol*, TimeESport*> > &v_clubes);
void LoadClubes( vector< tuple<Clube*, TimeFutebol*, TimeESport*> > &v_clubes, vector<Pessoa*> &v_pessoas);
bool DeleteClube(size_t id, vector< tuple<Clube*, TimeFutebol*, TimeESport*> > &v_clubes);
bool DeleteClube(string nomeClube, vector< tuple<Clube*, TimeFutebol*, TimeESport*> > &v_clubes);

#endif