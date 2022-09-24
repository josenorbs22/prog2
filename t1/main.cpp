#include "person.hpp"

int main (){
    vector<personPF> listPF;
    vector<personPJ> listPJ;
    vector<string> listaUnificada;
    int op;

    LoadDatabase("database.dat", listPF, listPJ);

    while(true){

        /* cout << endl << "MY PAPA'S COMPANY - SIG" << endl;
        cout << "1. Add PF..." << endl;
        cout << "2. Add PJ..." << endl;
        cout << "3. Remove PF by Index..." << endl;
        cout << "4. Remove PJ by Index..." << endl;
        cout << "5. Print Names in Ascending Order" << endl;
        cout << "6. Exit" << endl; */

        //cout << "Option: "; 
        cin >> op;
        cin.ignore();

        if(op == 1){
            personPF pF;
            //cout << endl << "Nome: ";
            getline(cin, pF.nome);
            //cout <<"Nome da mae: ";
            getline(cin, pF.nomeMae);
            ///cout << "CPF: ";
            cin >> pF.cpf;
            cin.ignore();
            ///cout << "Endereco: ";
            getline(cin, pF.endereco);
            //cout << "Telefone: ";
            cin >> pF.telefone;
            listPF.push_back(pF);
            if(SaveDatabase("database.dat", listPF, listPJ)){
                //cout << endl << "Salvo com sucesso" << endl;
            }
            continue;
        }

        if(op == 2){
            personPJ pJ;
            //cout << endl << "Razao Social: ";
            getline(cin, pJ.razaoSocial);
            //cout << "CNPJ: ";
            cin >> pJ.cnpj;
            cin.ignore();
            //cout << "Endereco: ";
            getline(cin, pJ.endereco);
            //cout << "Telefone: ";
            cin >> pJ.telefone;
            //cout << "Capital Social: ";
            cin >> pJ.capitalSocial;
            listPJ.push_back(pJ);
            if(SaveDatabase("database.dat", listPF, listPJ)){
                //cout << endl << "Salvo com sucesso" << endl;
            }
            continue;
        }

        if(op == 3){
            int pos;
            //cout << "Enter with a position to remove: ";
            cin >> pos;
            if(!DeletePF("database.dat", listPF, pos)){
                //cout << "Error, invalid index." << endl;
            } else{
                SaveDatabase("database.dat", listPF, listPJ);
                //cout << endl << "PF removida com sucesso!" << endl;
            }

            continue;
        }

        if(op == 4){
            int pos;
            //cout << "Enter with a position to remove: ";
            cin >> pos;
            if(!DeletePJ("database.dat", listPJ, pos)){
                //cout << "Error, invalid index." << endl;
            } else{
                SaveDatabase("database.dat", listPF, listPJ);
                //cout << endl << "PJ removida com sucesso!" << endl;
            }
            continue;
        }

        if(op == 5){
            cout << "Names in Ascending Order: " << endl;
            listaUnificada = SortNames(listPF, listPJ);
            
            for (int i = 0; i < listaUnificada.size(); i++){
                cout << listaUnificada.at(i) << endl;
            }
            continue;
        }

        if(op == 6){           
            break;
        }

        if(op > 6 || op < 1){
            //cout << "Invalid option" << endl;
            continue;
        }
    }

    return 0;
}