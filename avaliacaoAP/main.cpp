#include "pessoa.hpp"
#include "clube.hpp"
#include "time.hpp"

int main(){
    string op;    
    vector<Pessoa*> v_pessoas;
    vector<tuple<Clube*, TimeFutebol*, TimeESport*>> v_clubes;

    while(true){
        LoadPessoas(v_pessoas);
        LoadClubes(v_clubes, v_pessoas);

        cout << "------------------------------------------" << endl;
        cout << "REGISTRO DE TIMES:" << endl;
        cout << "1. Registrar nova pessoa;" << endl;
        cout << "2. Listar as pessoas cadastradas;" << endl;
        cout << "3. Registrar novo clube e times;" << endl;
        cout << "4. Listar clubes e times cadastrados;" << endl;
        cout << "5. Inativar pessoa;" << endl;
        cout << "6. Excluir clube;" << endl;
        cout << "7. Sair." << endl;
        cout << endl <<"Opcao: ";
        getline(cin, op);

        if (op == "1"){ 
            string nome, apelido;
            int contrato;
            
            cout << "Nome: ";
            getline(cin, nome);
            cout << "Apelido: ";
            getline(cin, apelido);
            cout << "Numero de contrato: ";
            cin >> contrato;
            cin.ignore();

            Pessoa *pessoa = new Pessoa(nome, apelido, contrato, true);
            v_pessoas.push_back(pessoa);
            if(SavePessoas(v_pessoas))
                cout << "Salvo com sucesso" << endl;
            else
                cout << "Algo deu errado" << endl;

            continue;
        }

        if (op == "2"){
            for(int i = 0; i < v_pessoas.size(); i++){
                cout << "------------------------------------------" << endl;
                cout << "Nome: " << v_pessoas.at(i)->GetNome() << endl;
                cout << "Apelido: " << v_pessoas.at(i)->GetApelido() << endl;
                cout << "Numero de contrato: " << v_pessoas.at(i)->GetContrato() << endl;
            }
            
            continue;
        }

        if (op == "3"){
            string nomePresidente, endereco, nome;
            int registro;
            string s_registro;
            char resp;
            Pessoa* presidente;
            Clube* clube;
            TimeFutebol* timeFutebol;
            TimeESport* timeESport;
            tuple<Clube*, TimeFutebol*, TimeESport*> t_clube;

            while(true){
                cout << "Nome do presidente do clube: ";
                getline(cin, nomePresidente);
                if(AcharPessoa(nomePresidente, presidente, v_pessoas)){
                    break;
                }else{
                    cout << "Nome nao achado!" << endl;
                    continue;
                }
            }
            cout << "Numero de registro do clube: ";
            cin >> registro;
            cin.ignore();
            cout << "Endereco da sede do clube: ";
            getline(cin, endereco);
            cout << "Nome do clube: ";
            getline(cin, nome);

            clube = new Clube(*presidente, registro, endereco, nome);

            cout << endl << "Deseja registrar um time de futebol para este clube? (s ou n): ";
            cin >> resp;
            cin.ignore();

            if(resp == 's'){
                string nomeDiretor, funcao, nomeJogador;
                Pessoa* diretor, *jogador;
                pair<string, Pessoa> p_jogador;
                vector<pair<string, Pessoa>> v_jogadores;
                int nTitulos;
                timeFutebol = (TimeFutebol*) clube;

                while(true){
                    
                    cout << "Nome do diretor do time: ";
                    getline(cin, nomeDiretor);
                    if(AcharPessoa(nomeDiretor, diretor, v_pessoas)){
                        break;
                    }else{
                        cout << "Nome nao achado!" << endl;
                        continue;
                    }
                }

                cout << "Jogadores:" << endl;
                for(int i = 0; i < 25; i++){
                    cout << "Funcao do jogador " << (i + 1) << ": ";
                    getline(cin, funcao);
                    while(true){
                        cout << "Nome do jogador" << (i + 1) << ": ";
                        getline(cin, nomeJogador);
                        if(AcharPessoa(nomeJogador, jogador, v_pessoas)){
                            break;
                        }else{
                            cout << "Nome nao achado!" << endl;
                            continue;
                        }
                    } 
                    p_jogador.first = funcao;
                    p_jogador.second = *jogador;
                    v_jogadores.push_back(p_jogador);
                }

                cout << "Quantidade de titulos do time: ";
                cin >> nTitulos;
                cin.ignore(); 

                timeFutebol = new TimeFutebol(*diretor, v_jogadores, nTitulos);
            } else {
                timeFutebol = NULL;
            }

            cout << endl << "Deseja registrar um time de eSport para este clube? (s ou n): ";
            cin >> resp;
            cin.ignore();

            if(resp == 's'){
                string nomeJogo, nomeJogador, funcao, nomeManager;
                bool gHO;
                char tmp;
                Pessoa* manager, *jogador;
                pair<string, Pessoa> p_jogador;
                vector<pair<string, Pessoa>> v_jogadores;
                timeESport = (TimeESport*) clube;

                cout << "Qual o nome do jogo pelo qual este time compete: ";
                getline(cin, nomeJogo);

                while(true){
                    cout << "Nome do manager do time: ";
                    getline(cin, nomeManager);
                    if(AcharPessoa(nomeManager, manager, v_pessoas)){
                        break;
                    }else{
                        cout << "Nome nao achado!" << endl;
                        continue;
                    }
                }

                cout << "Jogadores:" << endl;
                for(int i = 0; i < 7; i++){
                    cout << "Funcao do jogador " << (i + 1) << ": ";
                    getline(cin, funcao);
                    while(true){
                        cout << "Nome do jogador" << (i + 1) << ": ";
                        getline(cin, nomeJogador);
                        if(AcharPessoa(nomeJogador, jogador, v_pessoas)){
                            break;
                        }else{
                            cout << "Nome nao achado!" << endl;
                            continue;
                        }
                        
                    } 
                    p_jogador.first = funcao;
                    p_jogador.second = *jogador;
                    v_jogadores.push_back(p_jogador);
                }
                cout << "O time possui gaming house ou gaming office? (s ou n): ";
                cin >> tmp;
                cin.ignore();
                if(tmp == 's')
                    gHO = true;
                else
                    gHO = false;

                timeESport = new TimeESport(nomeJogo, *manager, v_jogadores, gHO);
            } else {
                timeESport = NULL;
            }

            get<0>(t_clube) = clube;
            get<1>(t_clube) = timeFutebol;
            get<2>(t_clube) = timeESport;
            v_clubes.push_back(t_clube);
            SaveClubes(v_clubes);
            continue;
        }

        if (op == "4"){
            string tmp;
            for(int i = 0; i < v_clubes.size(); i++){
                cout << "-----------------------------" << endl;
                cout << "Indice - " << i << endl;
                cout << "Nome do presidente: " << get<0>(v_clubes.at(i))->GetPresidente().GetNome() << endl;
                cout << "Numero de registro do clube: " << get<0>(v_clubes.at(i))->GetRegistro() << endl;
                cout << "Endereco do clube: " << get<0>(v_clubes.at(i))->GetEndereco() << endl;
                cout << "Nome do clube: " << get<0>(v_clubes.at(i))->GetNome() << endl;
                if(get<1>(v_clubes.at(i)) != NULL){
                    cout << "Diretor do time de futebol: " << get<1>(v_clubes.at(i))->GetDiretor().GetNome() << endl;
                    cout << "Numero de titulos do time: "<< get<1>(v_clubes.at(i))->GetNTitulos() << endl;
                    cout << "Jogadores de futebol: " << endl;
                    for(int j = 0; j < 25; j++){
                        cout << " - " << tmp << " -> " << get<1>(v_clubes.at(i))->GetJogadores().at(j).second.GetNome() << endl;
                    }
                } else{
                    cout << "Clube sem time de futebol." << endl;
                }
                if(get<2>(v_clubes.at(i)) != NULL){
                    cout << "Nome do jogo no qual o time de eSports compete: " << get<2>(v_clubes.at(i))->GetNomeJogo() << endl;
                    cout << "Manager do time de eSports: " << get<2>(v_clubes.at(i))->GetManager().GetNome() << endl;
                    cout << "Possui gaming house ou gaming office?: " << (get<2>(v_clubes.at(i))->GetGHO()? "Sim" : "Nao") << endl;
                    cout << "Jogadores do time de eSports: " << endl;
                    for(int j = 0; j < 7; j++){
                        cout << " - " << get<2>(v_clubes.at(i))->GetJogadores().at(j).first << " -> " << get<2>(v_clubes.at(i))->GetJogadores().at(j).second.GetNome() << endl;
                    }
                } else{
                    cout << "Clube sem time de eSport." << endl;
                }
            }

            continue;
        }

        if (op == "5"){
            char resp;
            cout << "Inativar Pessoa por indice na lista(1) ou por nome(2)?: ";
            cin >> resp;
            cin.ignore();
            if(resp == '1'){
                size_t id;

                cout << "Qual o indice da lista da pessoa a ser desativada?: ";
                cin >> id;
                cin.ignore();

                v_pessoas.at(id)->SetAtivo(false);

            } else if(resp == '2'){
                string nomePessoa;
                Pessoa* pessoaDesativada;
                
                cout << "Nome da pessoa a ser desativada: ";
                getline(cin, nomePessoa);

                if(AcharPessoa(nomePessoa, pessoaDesativada, v_pessoas)){
                    pessoaDesativada->SetAtivo(false);
                }else{
                    cout << "Nome nao achado!" << endl;
                }
            }
            
            SavePessoas(v_pessoas);
            
            continue;
        }

        if (op == "6"){
            char resp;
            cout << "Inativar Clube por indice na lista(1) ou por nome(2)?: ";
            cin >> resp;
            cin.ignore();
            if(resp == '1'){
                size_t id;

                cout << "Qual o indice da lista do clube a ser excluido?: ";
                cin >> id;
                cin.ignore();

                if(DeleteClube(id, v_clubes)){
                    cout << "Deletado com sucesso." << endl;
                }else{
                    cout << "Indice invalido!" << endl;
                }

            } else if(resp == '2'){
                string nomeClube;
                
                cout << "Nome do clube a ser excluido: ";
                getline(cin, nomeClube);

                if(DeleteClube(nomeClube, v_clubes)){
                    cout << "Deletado com sucesso." << endl;
                }else{
                    cout << "Nome nao achado!" << endl;
                }
            }
            
            SaveClubes(v_clubes);
            
            continue;
        }

        if (op == "7"){
            for(int i = 0; i < v_pessoas.size(); i++){
                delete v_pessoas.at(i);
            }
            for(int i = 0; i < v_clubes.size(); i++){
                delete get<0>(v_clubes.at(i));
                delete get<1>(v_clubes.at(i));
                delete get<2>(v_clubes.at(i));
            }
            break;
        }
    }

    return 0;
}