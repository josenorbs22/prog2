#include "astro.hpp"

bool SaveAstro(const vector<Astro> &v_astro){
    ofstream filewriter("astro.txt");
    if(!filewriter.is_open()) return false;

    for(size_t i=0; i < v_astro.size(); i++){
        Astro astro = v_astro.at(i);
        filewriter << astro.GetId() << endl 
            << astro.GetName() << endl 
            << astro.GetDec().at(0) << endl 
            << astro.GetDec().at(1) << endl 
            << astro.GetDec().at(2) << endl 
            << astro.GetRA().at(0) << endl 
            << astro.GetRA().at(1) << endl 
            << astro.GetRA().at(2) << endl
            << astro.GetDistance() << endl;
    }
    filewriter.close();
    return true;
}

void LoadAstros(vector<Astro> &v_astro){
    ifstream filereader("astro.txt");
    v_astro.clear();
    string tmp;
    while(getline(filereader, tmp)){
        if(tmp == "0" || tmp == "") break;
        Astro astro;
        vector<int> dec, ra;
        astro.SetId(stol(tmp));
        getline(filereader, tmp);
        astro.SetName(tmp);
        getline(filereader, tmp);
        dec.push_back(stoi(tmp));
        getline(filereader, tmp);
        dec.push_back(stoi(tmp));
        getline(filereader, tmp);
        dec.push_back(stoi(tmp));
        astro.SetDec(dec);
        getline(filereader, tmp);
        ra.push_back(stoi(tmp));
        getline(filereader, tmp);
        ra.push_back(stoi(tmp));
        getline(filereader, tmp);
        ra.push_back(stoi(tmp));
        astro.SetRA(ra);
        getline(filereader, tmp);
        astro.SetDistance(stof(tmp));

        v_astro.push_back(astro);
    }
    filereader.close();
}

bool DeleteAstro(vector<Astro> &v_astro, size_t id){
    bool done = false;
    for(int i = 0; i < v_astro.size(); i++){
        if(id == v_astro.at(i).GetId()){
            v_astro.erase(v_astro.begin()+i);
            done = true;
        }
    }
    return done;
}

size_t FindLastId(const vector<Astro> &v_astro){
    size_t id = 0;
    for (size_t i = 0; i < v_astro.size(); i++){
        if(id < v_astro.at(i).GetId()){
            id =v_astro.at(i).GetId();
        }
    }
    return id;
}