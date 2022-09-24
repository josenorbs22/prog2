#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

vector<string> openDictionary(string name){
    vector<string> words;
    ifstream fileReader(name);
    fileReader.open(name);
    if(fileReader.is_open()){
        string a;
        while(getline(fileReader, a)){
            words.push_back(a);
        }
    }
    return words;
}

vector<string> searchWords(const vector<vector<string>> &dict, string query){
    vector<string> subList;
    string find;
    int pos;

    for (int i = 0; i < dict.size(); i++){
        for (int j = 0; j < dict.at(i).size(); j++){
            find = dict.at(i).at(j);
            pos = find.find(query);
            if(pos < find.length()){
                subList.push_back(find);
            }
        }
    }
    return subList;
}

void deleteWords(vector<vector<string>> &dict, string query){
    string find;
    int pos;
    int j = 0;

    for (int i = 0; i < dict.size(); i++){
        while(j < dict.at(i).size()){
            find = dict.at(i).at(j);
            pos = find.find(query);
            if(pos < find.length()){
                dict.at(i).erase(dict.at(i).begin()+j);
                j = 0;
            }
            j++;
        }
    }
}

int main(){
    int option;
    bool cancel = true;
    string word;
    vector<vector<string>> dictionaries;
    vector<string> list, names;

    while(cancel){

        cout << "Select an option: " << endl;
        cout << "1 - Open dictionary " << endl;
        cout << "2 - Search substrings " << endl;
        cout << "3 - Remove words containing substring " << endl;
        cout << "4 - Show statistics " << endl;
        cout << "5 - Exit " << endl << endl;

        cout << "Option: ";
        cin >> option;

        vector<string> dict;

        switch (option){
            case 1:
                cout << "Enter a dictionary file: ";
                cin >> word;
                dict = openDictionary(word);
                if(dict.size() == 0){
                    cout << "File not found!" << endl;
                } else {
                    dict.erase(dict.begin()+0);
                    dictionaries.push_back(dict);
                    names.push_back(word);
                }

            case 2:
                cout << "Enter a substring to search: ";
                cin >> word;
                list = searchWords(dictionaries, word);
                if(list.size() == 0){
                    cout << "Word not found!" << endl;
                } else {
                    for (int i = 0; i < list.size(); i++){
                        cout << list.at(i) << endl;
                    }
                }

            case 3:
                cout << "Enter a substring to remove all occurrences: ";
                cin >> word;
                deleteWords(dictionaries, word);

            case 4:
                cout << "Statistics:" << endl;
                for(int i = 0; i < names.size(); i++){
                    for(int j = 0; j < dictionaries.at(i).size(); j++){
                        cout << names.at(i) << ": " << dictionaries.at(i).size();
                    }
                }

            case 5: 
                cancel = false;
                break;
            default:
                cout << "Invalid option..." << endl;
        }
    }

    return 0;
}