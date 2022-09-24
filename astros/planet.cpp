#include "planet.hpp"

Planet* FindPlanet(size_t idPlaneta, const vector<Planet> &v_planets){
    for(size_t i = 0; i < v_planets.size(); i++){
        if(idPlaneta == v_planets.at(i).GetId()){
            Planet *planet = new Planet(v_planets.at(i));
            return planet;
        }
    }
    return NULL;

}

bool SavePlanet(const vector<Planet> &v_planet){
    ofstream filewriter("planet.txt");
    if(!filewriter.is_open()) return false;

    for(size_t i=0; i < v_planet.size(); i++){
        Planet planet = v_planet.at(i);
        string exo = (planet.GetExoplanet() ? "Sim": "Nao");
        filewriter << planet.GetId() << endl 
            << planet.GetName() << endl 
            << planet.GetDec().at(0) << endl 
            << planet.GetDec().at(1) << endl 
            << planet.GetDec().at(2) << endl 
            << planet.GetRA().at(0) << endl 
            << planet.GetRA().at(1) << endl 
            << planet.GetRA().at(2) << endl
            << planet.GetDistance() << endl 
            << planet.GetSize() << endl
            << exo << endl
            << planet.GetSSName() << endl
            << planet.GetPos() << endl
            << planet.GetMaterials() << endl;
    }
    filewriter.close();
    return true;
}

void LoadPlanets(vector<Planet> &v_planet){
    ifstream filereader("planet.txt");
    v_planet.clear();
    string tmp;
    while(getline(filereader, tmp)){
        if(tmp == "0" || tmp == "") break;
        Planet planet;
        vector<int> dec, ra;
        planet.SetId(stol(tmp));
        getline(filereader, tmp);
        planet.SetName(tmp);
        getline(filereader, tmp);
        dec.push_back(stoi(tmp));
        getline(filereader, tmp);
        dec.push_back(stoi(tmp));
        getline(filereader, tmp);
        dec.push_back(stoi(tmp));
        planet.SetDec(dec);
        getline(filereader, tmp);
        ra.push_back(stoi(tmp));
        getline(filereader, tmp);
        ra.push_back(stoi(tmp));
        getline(filereader, tmp);
        ra.push_back(stoi(tmp));
        planet.SetRA(ra);
        getline(filereader, tmp);
        planet.SetDistance(stof(tmp));
        getline(filereader, tmp);
        planet.SetSize(stof(tmp));
        getline(filereader, tmp);
        
        if(tmp == "Sim"){
            planet.SetExoplanet(true);
        } else
            planet.SetExoplanet(false);

        getline(filereader, tmp);
        planet.SetSSName(tmp);
        getline(filereader, tmp);
        planet.SetPos(stoi(tmp));
        getline(filereader, tmp);
        planet.SetMaterials(tmp);

        v_planet.push_back(planet);
    }
    filereader.close();
}

bool DeletePlanet(vector<Planet> &v_planet, size_t id){
    for(int i = 0; i < v_planet.size(); i++){
        if(id == v_planet.at(i).GetId()){
            v_planet.erase(v_planet.begin()+i);
            return true;
        }
    }
    return false;
}
