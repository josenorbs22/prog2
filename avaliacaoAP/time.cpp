#include "time.hpp"

bool SaveClubes( const vector< tuple<Clube*, TimeFutebol*, TimeESport*> > &v_clubes){
    ofstream filewriter("clube.txt");
    if(!filewriter.is_open()) return false;

    for(size_t i = 0; i < v_clubes.size(); i++){
        Clube* clube = get<0>(v_clubes.at(i));
        filewriter << clube->GetPresidente().GetNome() << endl 
            << clube->GetRegistro() << endl 
            << clube->GetEndereco() << endl 
            << clube->GetNome() << endl;
        TimeFutebol* timeF = get<1>(v_clubes.at(i));
        if(timeF == NULL){
            filewriter << "null" << endl;
        } else{
            filewriter << timeF->GetDiretor().GetNome() << endl;
            for(int j = 0; j < 25; j++){
                filewriter << timeF->GetJogadores().at(j).first << endl << timeF->GetJogadores().at(j).second.GetNome() << endl;
            }
            filewriter << timeF->GetNTitulos() << endl; 
        }
        TimeESport* timeE = get<2>(v_clubes.at(i));
        if(timeE == NULL){
            filewriter << "null" << endl;
        } else{
            filewriter << timeE->GetNomeJogo() << endl
                << timeE->GetManager().GetNome() << endl;
            for(int j = 0; j < 7; j++){
                filewriter << timeE->GetJogadores().at(j).first << endl << timeE->GetJogadores().at(j).second.GetNome() << endl;
            }
            filewriter << (timeE->GetGHO()? "Sim" : "Nao") << endl; 
        }
    }
    filewriter.close();
    return true;
}

void LoadClubes( vector<tuple<Clube*, TimeFutebol*, TimeESport*> > &v_clubes, vector<Pessoa*> &v_pessoas){
    ifstream filereader("clube.txt");
    for(int i = 0; i < v_clubes.size(); i++){
        delete get<0>(v_clubes.at(i));
        delete get<1>(v_clubes.at(i));
        delete get<2>(v_clubes.at(i));
    }
    v_clubes.clear();
    string tmp;
    while(getline(filereader, tmp)){
        if(tmp == "0" || tmp == "") break;
        Clube* clube =  new Clube();
        TimeFutebol* timeF = new TimeFutebol();
        TimeESport* timeE = new TimeESport();
        tuple<Clube*, TimeFutebol*, TimeESport*> t_clube;
        Pessoa* presidente = new Pessoa();
        AcharPessoa(tmp, presidente, v_pessoas);
        clube->SetPresidente(*presidente);
        getline(filereader, tmp);
        clube->SetRegistro(stoi(tmp));
        getline(filereader, tmp);
        clube->SetEndereco(tmp);
        getline(filereader, tmp);
        clube->SetNome(tmp);

        getline(filereader, tmp);
        if(!(tmp == "null")){
            pair<string, Pessoa> p_jogadores;
            vector<pair<string, Pessoa>> v_jogadores;
            Pessoa* diretor = new Pessoa();
            AcharPessoa(tmp, diretor, v_pessoas);
            timeF->SetDiretor(*diretor);
            for(int i = 0; i < 25; i++){
                Pessoa* jogador = new Pessoa();
                getline(filereader, tmp);
                p_jogadores.first = tmp;
                getline(filereader, tmp);
                AcharPessoa(tmp, jogador, v_pessoas);
                p_jogadores.second = *jogador;
                v_jogadores.push_back(p_jogadores);
            }
            timeF->SetJogadores(v_jogadores);
            getline(filereader, tmp);
            timeF->SetNTitulos(stoi(tmp));
        } else{
            timeF = NULL;
        }
        getline(filereader, tmp);
        if(!(tmp == "null")){
            pair<string, Pessoa> p_jogadores;
            vector<pair<string, Pessoa>> v_jogadores;
            timeE->SetNomeJogo(tmp);
            getline(filereader, tmp);
            Pessoa* manager = new Pessoa();
            AcharPessoa(tmp, manager, v_pessoas);
            timeE->SetManager(*manager);
            for(int i = 0; i < 7; i++){
                Pessoa* jogador = new Pessoa();
                getline(filereader, tmp);
                p_jogadores.first = tmp;
                getline(filereader, tmp);
                AcharPessoa(tmp, jogador, v_pessoas);
                p_jogadores.second = *jogador;
                v_jogadores.push_back(p_jogadores);
            }
            timeE->SetJogadores(v_jogadores);
            getline(filereader, tmp);
            if(tmp == "Sim"){
                timeE->SetGHO(true);
            } else
                timeE->SetGHO(false);

        
        } else{
            timeE = NULL;
        }

        get<0>(t_clube) = clube;
        get<1>(t_clube) = timeF;
        get<2>(t_clube) = timeE;

        v_clubes.push_back(t_clube);
        
    }
    filereader.close();
}

bool DeleteClube(size_t id, vector< tuple<Clube*, TimeFutebol*, TimeESport*> > &v_clubes){
    if(id >= v_clubes.size() || id < 0) return false;
    delete get<0>(v_clubes.at(id));
    delete get<1>(v_clubes.at(id));
    delete get<2>(v_clubes.at(id));
    v_clubes.erase(v_clubes.begin()+id);
    return true;
}
bool DeleteClube(string nomeClube, vector< tuple<Clube*, TimeFutebol*, TimeESport*> > &v_clubes){
    string find;
    int pos;

    for (int i = 0; i < v_clubes.size(); i++){
        find = get<0>(v_clubes.at(i))->GetNome();
        pos = find.find(nomeClube);
        if(pos < find.length()){
            delete get<0>(v_clubes.at(i));
            delete get<1>(v_clubes.at(i));
            delete get<2>(v_clubes.at(i));
            v_clubes.erase(v_clubes.begin()+i);
            return true;
        }
    }
    return false;
}