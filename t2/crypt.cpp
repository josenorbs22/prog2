#include "crypt.hpp"

string LoadMessage(string filename){
    string message;
    ifstream fileReader(filename);
    if(!fileReader.is_open())
        return "Could not find the message";
    getline(fileReader, message);

    return message;
}

string getTip(string filename){
    string tip;
    ifstream fileReader(filename);

    if(!fileReader.is_open())
        return "Could not find the file with that name";

    getline(fileReader, tip);
    
    return tip;
}

vector<pair<unsigned char, string>> EncodingTableMaker(stringstream &sst){
    vector<pair<string, size_t>> wordFreq;
    string word;

    vector<string> words;
    while (sst >> word) 
        words.push_back(word);

    for (int i = 0; i < words.size(); i++){
        pair<string, size_t> par;
        par.first = words.at(i);
        for (int j = 0 ; j < words.size(); j++){
            if(par.first == words.at(j)){
                par.second++;
            }
        }
        wordFreq.push_back(par);
    }

    int i = 0;
    while(i < wordFreq.size()){
        int j = 0;
        while(j < wordFreq.size()){
            if(wordFreq.at(i).first == wordFreq.at(j).first && i != j ){
                wordFreq.erase(wordFreq.begin()+j);
                j = 0;
                i = 0;
            }
            j++;
        }
        i++;
    } 
    
    stable_sort(wordFreq.begin(), wordFreq.end(), Compare);

    vector<pair<unsigned char, string>> encodingTable(256);
    for(size_t i=0; i < 256; i++)
    {
        encodingTable.at(i).first = i;
        encodingTable.at(i).second = wordFreq.at(i).first;
    }
    return encodingTable;
}

bool WriteMessage(string tip, string message){
    //remove("message_not_encrypted.txt");
    ofstream fileWriter("message_not_encrypted.txt");
    if(!fileWriter.is_open()){
        return false;
    }
    //system("attrib +R message_not_encrypted.txt");

    fileWriter << tip << endl << message;
    fileWriter.close();
    return true;
}

bool EncryptMessage(string operatorName){
    string tip, message, encoder;
    stringstream sst;
    ofstream fileWriter("encrypted_message.txt");
    char ch;
    vector< pair<unsigned char, size_t> > charFreq;
    ifstream fileReader("message_not_encrypted.txt");
    ifstream fileReaderEncoder(operatorName);

    if(!fileReader.is_open()){
        return false;
    }

    if(!fileReaderEncoder.is_open()){
        return false;
    }

    while(fileReaderEncoder.get(ch)){
        sst << ch;
    }

    vector<pair<unsigned char, string>> encodingTable = EncodingTableMaker(sst);

    getline(fileReader, tip);
    getline(fileReader, message);

    fileWriter << tip << endl;

    for(size_t i=0; i<message.size(); i++){
        char ch = message.at(i);
        for(size_t j=0; j<encodingTable.size(); j++){
            if(ch == encodingTable.at(j).first){
                fileWriter << encodingTable.at(j).second << " ";
                break;
            }
        }
    }
    fileWriter.close();

    return true;
}

string DecryptMessage(string filename, string operatorName){
    ifstream fileReaderMessage(filename);
    ifstream fileReaderEncoder(operatorName);
    if(!fileReaderEncoder.is_open() || !fileReaderMessage.is_open()){
        return "Could not open file";
    }
    string tip, message, word;
    stringstream sst1, sst2, sstF;
    char ch;

    getline(fileReaderMessage, tip);
    getline(fileReaderMessage, message);

    sst1 << message;

    while(fileReaderEncoder.get(ch)){
        sst2 << ch;
    }

    vector<pair<unsigned char, string>> encodingTable = EncodingTableMaker(sst2); 

    while(sst1 >> word){
        for (int i = 0; i < encodingTable.size(); i++){
            if (word == encodingTable.at(i).second){
                sstF << encodingTable.at(i).first;
            }
        }
    }
    return sstF.str();
}

bool Compare(pair<string, size_t> i, pair<string, size_t> j){
    return i.second > j.second;
}