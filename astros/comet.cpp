#include "comet.hpp"

bool SaveComet(const vector<Comet> &v_comet){
    ofstream filewriter("comet.txt");
    if(!filewriter.is_open()) return false;

    for(size_t i=0; i < v_comet.size(); i++){
        Comet comet = v_comet.at(i);
        filewriter << comet.GetId() << endl 
            << comet.GetName() << endl  
            << comet.GetEccentricity() << endl
            << comet.GetPeriod() << endl
            << comet.GetPerihelion() << endl
            << comet.GetAphelion() << endl;
    }
    filewriter.close();
    return true;
}

void LoadComets(vector<Comet> &v_comet){
    ifstream filereader("comet.txt");
    v_comet.clear();
    string tmp;
    while(getline(filereader, tmp)){
        if(tmp == "0" || tmp == "") break;
        Comet comet;
        comet.SetId(stol(tmp));
        getline(filereader, tmp);
        comet.SetName(tmp);
        getline(filereader, tmp);
        comet.SetEccentricity(stod(tmp));
        getline(filereader, tmp);
        comet.SetPeriod(stol(tmp));
        getline(filereader, tmp);
        comet.SetPerihelion(stod(tmp));
        getline(filereader, tmp);
        comet.SetAphelion(stod(tmp));

        v_comet.push_back(comet);
    }
    filereader.close();
}

bool DeleteComet(vector<Comet> &v_comet, size_t id){
    for(int i = 0; i < v_comet.size(); i++){
        if(id == v_comet.at(i).GetId()){
            v_comet.erase(v_comet.begin()+i);
            return true;
        }
    }
    return false;
}

Comet* FindComet(size_t idComet, const vector<Comet> &v_comets){
    for(size_t i = 0; i < v_comets.size(); i++){
        if(idComet == v_comets.at(i).GetId()){
            Comet *star = new Comet(v_comets.at(i));
            return star;
        }
    }
    return NULL;
}
