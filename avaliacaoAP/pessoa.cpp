#include "pessoa.hpp"

bool SavePessoas(const vector<Pessoa*> &v_pessoas){
    ofstream filewriter("pessoa.txt");
    if(!filewriter.is_open()) return false;

    for(size_t i = 0; i < v_pessoas.size(); i++){
        Pessoa* pessoa = v_pessoas.at(i);
        filewriter << pessoa->GetNome() << endl 
            << pessoa->GetApelido() << endl 
            << pessoa->GetContrato() << endl 
            << (pessoa->GetAtivo()? "Sim" : "Nao") << endl;
    }
    filewriter.close();
    return true;
}

void LoadPessoas(vector<Pessoa*> &v_pessoas){
    ifstream filereader("pessoa.txt");
    for(int i = 0; i < v_pessoas.size(); i++){
        delete v_pessoas.at(i);
    }
    v_pessoas.clear();
    string tmp;
    while(getline(filereader, tmp)){
        if(tmp == "0" || tmp == "") break;
        Pessoa* pessoa =  new Pessoa();
        pessoa->SetNome(tmp);
        getline(filereader, tmp);
        pessoa->SetApelido(tmp);
        getline(filereader, tmp);
        pessoa->SetContrato(stoi(tmp));
        getline(filereader, tmp);
        
        if(tmp == "Sim"){
            pessoa->SetAtivo(true);
        } else
            pessoa->SetAtivo(false);

        v_pessoas.push_back(pessoa);
    }
    filereader.close();
}

bool AcharPessoa(string nomePessoa, Pessoa* &pessoaDesativada, const vector<Pessoa*> &v_pessoas){
    string find;
    int pos;

    for (int i = 0; i < v_pessoas.size(); i++){
        find = v_pessoas.at(i)->GetNome();
        pos = find.find(nomePessoa);
        if(pos < find.length()){
            pessoaDesativada = v_pessoas.at(i);
            return true;
        }
    }
    return false;
}