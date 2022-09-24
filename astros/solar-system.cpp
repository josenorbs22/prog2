#include "planet.hpp"
#include "star.hpp"
#include "solar-system.hpp"

bool SaveSolarSystem(const vector<SolarSystem> &v_ssystem){   
    ofstream filewriter("solar-system.txt");
    if(!filewriter.is_open()) return false;

    for(size_t i=0; i < v_ssystem.size(); i++){
        SolarSystem ssystem = v_ssystem.at(i);
    
        filewriter << ssystem.GetId() << endl << ssystem.GetName() << endl;

        for (size_t i = 0; i < ssystem.GetStars().size(); i++){
            filewriter << ssystem.GetStars().at(i)->GetId() << endl;
        }
        filewriter << "--" << endl;
        for (size_t i = 0; i < ssystem.GetPlanets().size(); i++){
            filewriter << ssystem.GetPlanets().at(i)->GetId() << endl;
        }
        filewriter << "--" << endl;
        
    }
    filewriter.close();
    return true;
}

void LoadSolarSystems(vector<SolarSystem> &v_ssystem, const vector<Star> &v_star, const vector<Planet> &v_planet){
    ifstream filereader("solar-system.txt");
    v_ssystem.clear();
    string tmp;
    while(getline(filereader, tmp)){
        if(tmp == "0" || tmp == "") break;
        vector<size_t> idsSol, idsPlanets;
        SolarSystem ssystem;
        vector<Star*> stars;
        vector<Planet*> planets;

        ssystem.SetId(stol(tmp));
        getline(filereader, tmp);
        ssystem.SetName(tmp);
        while(getline(filereader, tmp)){
            if(tmp != "--"){
                idsSol.push_back(stol(tmp));
                continue;
            } else
                break;
        }
        for(size_t i = 0; i < idsSol.size(); i++){
            Star *star = FindStar(idsSol.at(i), v_star);
            if(star != NULL)
                stars.push_back(star);
        }
        ssystem.SetStars(stars);

        while(getline(filereader, tmp)){
            if(tmp != "--"){
                idsPlanets.push_back(stol(tmp));
                continue;
            } else
                break;
        }
        for(size_t i = 0; i < idsPlanets.size(); i++){
            Planet *planet = FindPlanet(idsPlanets.at(i), v_planet);
            if(planet != NULL)
                planets.push_back(planet);
        }
        ssystem.SetPlanets(planets);

        v_ssystem.push_back(ssystem);
    }
    filereader.close();
}

bool DeleteSolarSystem(vector<SolarSystem> &v_ssystem, size_t id){
    for(int i = 0; i < v_ssystem.size(); i++){
        if(id == v_ssystem.at(i).GetId()){
            v_ssystem.erase(v_ssystem.begin()+i);
            return true;
        }
    }
    return false;
}

size_t FindLastId(const vector<SolarSystem> &v_ssystem){
    size_t id = 0;
    for (size_t i = 0; i < v_ssystem.size(); i++){
        if(id < v_ssystem.at(i).GetId()){
            id =v_ssystem.at(i).GetId();
        }
    }
    return id;
}
