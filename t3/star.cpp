#include "star.hpp"

Star* FindStar(size_t idSol, const vector<Star> &v_stars){
    for(size_t i = 0; i < v_stars.size(); i++){
        if(idSol == v_stars.at(i).GetId()){
            Star *star = new Star(v_stars.at(i));
            return star;
        }
    }
    return NULL;
    /* Star star;
    vector<int> dec, rA;

    star.SetId(idSol);
    star.SetName("Teste");
    dec.push_back(13);
    dec.push_back(14);
    dec.push_back(15);
    star.SetDec(dec);
    rA.push_back(16);
    rA.push_back(73);
    rA.push_back(18);
    star.SetRA(rA);
    star.SetDistance(6334.07);
    star.SetStarType("Gigante teste vermelha");
    star.SetMass(44.6);
    star.SetRadius(67);
    star.SetAppaMag(579);
    star.SetAbsMag(2);

    return star; */
}

bool SaveStar(const vector<Star> &v_star){
    ofstream filewriter("star.txt");
    if(!filewriter.is_open()) return false;

    for(size_t i=0; i < v_star.size(); i++){
        Star star = v_star.at(i);
        filewriter << star.GetId() << endl 
            << star.GetName() << endl 
            << star.GetDec().at(0) << endl 
            << star.GetDec().at(1) << endl 
            << star.GetDec().at(2) << endl 
            << star.GetRA().at(0) << endl 
            << star.GetRA().at(1) << endl 
            << star.GetRA().at(2) << endl
            << star.GetDistance() << endl 
            << star.GetStarType() << endl
            << star.GetMass() << endl
            << star.GetRadius() << endl
            << star.GetAppaMag() << endl
            << star.GetAbsMag() << endl;
    }
    filewriter.close();
    return true;
}

void LoadStars(vector<Star> &v_star){
    ifstream filereader("star.txt");
    v_star.clear();
    string tmp;
    while(getline(filereader, tmp)){
        if(tmp == "0" || tmp == "") break;
        Star star;
        vector<int> dec, ra;
        star.SetId(stol(tmp));
        getline(filereader, tmp);
        star.SetName(tmp);
        getline(filereader, tmp);
        dec.push_back(stoi(tmp));
        getline(filereader, tmp);
        dec.push_back(stoi(tmp));
        getline(filereader, tmp);
        dec.push_back(stoi(tmp));
        star.SetDec(dec);
        getline(filereader, tmp);
        ra.push_back(stoi(tmp));
        getline(filereader, tmp);
        ra.push_back(stoi(tmp));
        getline(filereader, tmp);
        ra.push_back(stoi(tmp));
        star.SetRA(ra);
        getline(filereader, tmp);
        star.SetDistance(stof(tmp));
        getline(filereader, tmp);
        star.SetStarType(tmp);
        getline(filereader, tmp);
        star.SetMass(stof(tmp));
        getline(filereader, tmp);
        star.SetRadius(stol(tmp));
        getline(filereader, tmp);
        star.SetAppaMag(stof(tmp));
        getline(filereader, tmp);
        star.SetAbsMag(stof(tmp));

        v_star.push_back(star);
    }
    filereader.close();
}

bool DeleteStar(vector<Star> &v_star, size_t id){
    for(int i = 0; i < v_star.size(); i++){
        if(id == v_star.at(i).GetId()){
            v_star.erase(v_star.begin()+i);
            return true;
        }
    }
    return false;
}