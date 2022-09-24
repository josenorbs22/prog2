#include "astro.hpp"
#include "star.hpp"
#include "planet.hpp"
#include "solar-system.hpp"
#include "comet.hpp"

int main(){
    string op; 
    size_t idAstro, idSSystem;
    
    vector<Star> v_stars;
    vector<Planet> v_planets;
    vector<Comet> v_comets;
    vector<Astro> v_astros;
    vector<SolarSystem> v_ssystems;

    while(true){
        LoadStars(v_stars);
        LoadPlanets(v_planets);
        LoadComets(v_comets);
        LoadAstros(v_astros);
        LoadSolarSystems(v_ssystems, v_stars, v_planets);
        idAstro = FindLastId(v_astros);
        idSSystem = FindLastId(v_ssystems);

        cout << "------------------------------------------" << endl;
        cout << "REPOSITORIO DE ASTROS:" << endl;
        cout << "1. Registrar novo astro;" << endl;
        cout << "2. Listar os astros cadastrados;" << endl;
        cout << "3. Excluir um astro;" << endl;
        cout << "4. Registrar um sistema solar;" << endl;
        cout << "5. Listar sistemas solares cadastrados;" << endl;
        cout << "6. Excluir um sistema solar;" << endl;
        cout << "7. Sair." << endl;
        cout << endl <<"Opcao: ";
        getline(cin, op);

        if (op == "1"){ 
            int tmp;
            string name;
            vector<int> dec, rA;
            float distance;
            cout << "Qual o tipo de astro?" << endl;
            cout << "1. Estrela;" << endl;
            cout << "2. Planeta;" << endl;
            cout << "3. Cometa;" << endl;
            cout << "4. Indeterminado." << endl;
            cout << "Opcao:" << endl;
            cin >> tmp;
            cin.ignore();
            
            if (tmp == 1){
                string starType;
                int num;
                float mass, appaMag, absMag;
                size_t radius;
                  
                idAstro++;
                cout << "Nome: ";
                getline(cin, name);
                cout << "Declinacao: " << endl;
                cout << "- Horas: ";
                cin >> num;
                dec.push_back(num);
                cout << "- Minutos: ";
                cin >> num;
                dec.push_back(num);
                cout << "- Segundos: ";
                cin >> num;
                dec.push_back(num);
                cout << "Ascencao Reta: " << endl;
                cout << "- Graus: ";
                cin >> num;
                rA.push_back(num);
                cout << "- Minutos: ";
                cin >> num;
                rA.push_back(num);
                cout << "- Segundos: ";
                cin >> num;
                rA.push_back(num);
                cout << "Distancia: ";
                cin >> distance;
                cout << "Tipo de estrela: ";
                cin.ignore();
                getline(cin, starType);
                cout << "Massa: ";
                cin >> mass;
                cout << "Raio estelar: ";
                cin >> radius;
                cout << "Magnitude aparente: ";
                cin >> appaMag;
                cout << "Magnitude absoluta: ";
                cin >> absMag;
                cin.ignore();

                Star star(idAstro, name, dec, rA, distance, starType, mass, radius, appaMag, absMag);
                v_stars.push_back(star);
                if(SaveStar(v_stars))
                    cout << "Salvo com sucesso" << endl;
                else
                    cout << "Algo deu errado" << endl;

            } else if(tmp == 2){
                string SSName, materials;
                int num, pos;
                float size;
                bool exoplanet;
                char exo;

                idAstro++;
                cout << "Nome: ";
                cin.ignore();
                getline(cin, name);
                cout << "Declinacao: " << endl;
                cout << "- Horas: ";
                cin >> num;
                dec.push_back(num);
                cout << "- Minutos: ";
                cin >> num;
                dec.push_back(num);
                cout << "- Segundos: ";
                cin >> num;
                dec.push_back(num);
                cout << "Ascencao Reta: " << endl;
                cout << "- Graus: ";
                cin >> num;
                rA.push_back(num);
                cout << "- Minutos: ";
                cin >> num;
                rA.push_back(num);
                cout << "- Segundos: ";
                cin >> num;
                rA.push_back(num);
                cout << "Distancia: ";
                cin >> distance;
                cout << "Tamanho (diametro): ";
                cin >> size;
                cout << "Exoplaneta? (s ou n): ";
                cin >> exo;
                if(exo == 's'){
                    exoplanet = true;
                } else{
                    exoplanet = false;
                }
                cout << "Nome do sistema solar ao qual ele pertence: ";
                cin.ignore();
                getline(cin, SSName);
                cout << "Posicao do planeta no sistema solar: ";
                cin >> pos;
                cout << "Principais materiais no planeta: ";
                cin.ignore();
                getline(cin, materials);

                Planet planet(idAstro, name, dec, rA, distance, size, exoplanet, SSName, pos, materials);
                v_planets.push_back(planet);
                if(SavePlanet(v_planets))
                    cout << "Salvo com sucesso" << endl;
                else
                    cout << "Algo deu errado" << endl;

            } else if(tmp == 3){
                size_t period;
                double eccentricity, perihelion, aphelion;

                dec = {0, 0, 0};
                rA = {0, 0, 0};
                distance = 0;

                idAstro++;
                cout << "Nome: ";
                cin.ignore();
                getline(cin, name);
                cout << "Excentricidade da orbita do cometa: ";
                cin >> eccentricity;
                cout << "Periodo da orbita (anos): ";
                cin >> period;
                cout << "Perielio: ";
                cin >> perihelion;
                cout << "Afelio: ";
                cin >> aphelion;
                cin.ignore();

                Comet comet(idAstro, name, eccentricity, period, perihelion, aphelion);
                v_comets.push_back(comet);
                if(SaveComet(v_comets))
                    cout << "Salvo com sucesso" << endl;
                else
                    cout << "Algo deu errado" << endl;

            } else{
                int num;
                idAstro++;
                cout << "Nome: ";
                getline(cin, name);
                cout << "Declinacao: " << endl;
                cout << "- Horas: ";
                cin >> num;
                dec.push_back(num);
                cout << "- Minutos: ";
                cin >> num;
                dec.push_back(num);
                cout << "- Segundos: ";
                cin >> num;
                dec.push_back(num);
                cout << "Ascencao Reta: " << endl;
                cout << "- Graus: ";
                cin >> num;
                rA.push_back(num);
                cout << "- Minutos: ";
                cin >> num;
                rA.push_back(num);
                cout << "- Segundos: ";
                cin >> num;
                rA.push_back(num);
                cout << "Distancia: ";
                cin >> distance;
                cin.ignore();
            }

            Astro astro(idAstro, name, dec, rA, distance);
            v_astros.push_back(astro);
            SaveAstro(v_astros);

            continue;
        }

        if (op == "2"){
            int tmp; 
            char resp;
            for(int i = 0; i < v_astros.size(); i++){
                cout << "-----------------------------" << endl;
                cout << "Id: " << v_astros.at(i).GetId() << endl;
                cout << "Nome: " << v_astros.at(i).GetName() << endl;
                cout << "Declinacao: " << v_astros.at(i).GetDec().at(0) << "° " << v_astros.at(i).GetDec().at(1) << "' " << v_astros.at(i).GetDec().at(2) << "\"" << endl;
                cout << "Ascensao Reta: " << v_astros.at(i).GetRA().at(0) << "h " << v_astros.at(i).GetRA().at(1) << "m " << v_astros.at(i).GetRA().at(2) << "s" << endl;
                cout << "Distancia: " << v_astros.at(i).GetDistance() << endl;
            }
            
            cout << "Voce quer listar os astros por tipo? (s or n): ";
            cin >> resp;
            if(resp == 's'){
                cout << "Qual o tipo de astro?" << endl;
                cout << "1. Estrela;" << endl;
                cout << "2. Planeta;" << endl;
                cout << "3. Cometa." << endl;
                cout << endl << "Opcao: ";
                cin >> tmp;
                cin.ignore();
                if(tmp == 1){
                    for(int i = 0; i < v_stars.size(); i++){
                        cout << "-----------------------------" << endl;
                        cout << "Id: " << v_stars.at(i).GetId() << endl;
                        cout << "Nome: " << v_stars.at(i).GetName() << endl;
                        cout << "Declinacao: " << v_stars.at(i).GetDec().at(0) << "° " << v_stars.at(i).GetDec().at(1) << "' " << v_stars.at(i).GetDec().at(2) << "\"" << endl;
                        cout << "Ascensao Reta: " << v_stars.at(i).GetRA().at(0) << "h " << v_stars.at(i).GetRA().at(1) << "m " << v_stars.at(i).GetRA().at(2) << "s" << endl;
                        cout << "Distancia: " << v_stars.at(i).GetDistance() << endl;
                        cout << "Tipo de estrela: " << v_stars.at(i).GetStarType() << endl;
                        cout << "Massa: " << v_stars.at(i).GetMass() << endl;
                        cout << "Raio estelar: " << v_stars.at(i).GetRadius() << endl;
                        cout << "Magnitude aparente: " << v_stars.at(i).GetAppaMag() << endl;
                        cout << "Magnitude absoluta: " << v_stars.at(i).GetAbsMag() << endl;
                    }
                } else if(tmp == 2){
                    for(int i = 0; i < v_planets.size(); i++){
                        cout << "-----------------------------" << endl;
                        cout << "Id: " << v_planets.at(i).GetId() << endl;
                        cout << "Nome: " << v_planets.at(i).GetName() << endl;
                        cout << "Declinacao: " << v_planets.at(i).GetDec().at(0) << "° " << v_planets.at(i).GetDec().at(1) << "' " << v_planets.at(i).GetDec().at(2) << "\"" << endl;
                        cout << "Ascensao Reta: " << v_planets.at(i).GetRA().at(0) << "h " << v_planets.at(i).GetRA().at(1) << "m " << v_planets.at(i).GetRA().at(2) << "s" << endl;
                        cout << "Distancia: " << v_planets.at(i).GetDistance() << endl;
                        cout << "Tamanho (diametro): " << v_planets.at(i).GetSize() << endl;
                        cout << "Exoplaneta?: " << (v_planets.at(i).GetExoplanet()? "Sim" : "Nao") << endl;
                        cout << "Sistema solar: " << v_planets.at(i).GetSSName() << endl;
                        cout << "Posicao do planeta no sistema solar: " << v_planets.at(i).GetPos() << endl;
                        cout << "Principais materiais no planeta: " << v_planets.at(i).GetMaterials() << endl;
                    }

                } else if(tmp == 3){
                    for(int i = 0; i < v_comets.size(); i++){
                        cout << "-----------------------------" << endl;
                        cout << "Id: " << v_comets.at(i).GetId() << endl;
                        cout << "Nome: " << v_comets.at(i).GetName() << endl;
                        cout << "Excentricidade de orbita: " << v_comets.at(i).GetEccentricity() << endl;
                        cout << "Periodo de orbita: " << v_comets.at(i).GetPeriod() << endl;
                        cout << "Perielio: " << v_comets.at(i).GetPerihelion() << endl;
                        cout << "Afelio: " << v_comets.at(i).GetAphelion() << endl;
                    }

                }
            }

            continue;
        }

        if (op == "3"){
            size_t id;

            cout << "Qual a id do astro a ser excluido?: ";
            cin >> id;
            cin.ignore();

            if(DeleteAstro(v_astros, id) || DeleteStar(v_stars, id) || DeletePlanet(v_planets, id) || DeleteComet(v_comets, id))
                cout << "Astro excluido com sucesso!" << endl;
            else    
                cout << "Astro com esta id nao encontrado" << endl;
            
            SaveAstro(v_astros);
            SaveComet(v_comets);
            SavePlanet(v_planets);
            SaveStar(v_stars);
            
            continue;
        }

        if (op == "4"){
            string ssName;
            Star *star;
            Planet *planet;
            vector<Star*> stars;
            vector<Planet*> planets;
            int i = 1;
            
            idSSystem++;
            cout << "Nome do sistema solar: ";
            getline(cin, ssName);
            cout << "Digite as IDs das estrelas deste sistema solar "<< endl;
            cout << "(digite um numero negativo quando nao houver mais estrelas a adicionar): " << endl;
            while(true){
                int idSol;

                cout << "- Sol " << i << ": ";
                cin >> idSol;
                if(idSol > 0){
                    star = FindStar(idSol, v_stars);
                    if(star == NULL){
                        cout << "Id invalida" << endl;
                    } else{
                        stars.push_back(star);
                        i++;
                    }
                    continue;
                } else 
                    break;
            }
            i = 1;
            cout << "Digite as IDs dos planetas deste sistema solar " << endl;
            cout << "(digite um numero negativo quando nao houver mais planetas a adicionar): " << endl;
            while(true){
                int idPlaneta;

                cout << "- Planeta " << i << ": ";
                cin >> idPlaneta;
                
                if(idPlaneta > 0){
                    planet = FindPlanet(idPlaneta, v_planets);
                    if(planet == NULL){
                        cout << "Id invalida" << endl;
                    } else{
                        planets.push_back(planet); 
                        i++;
                    } 
                    continue;
                } else 
                    break;
                
            }
            cin.ignore();
            
            SolarSystem solarSystem(idSSystem, stars, planets, ssName);
            v_ssystems.push_back(solarSystem);
            SaveSolarSystem(v_ssystems);
            for(int i = 0; i < stars.size(); i++)
                delete stars.at(i);

            for(int i = 0; i < planets.size(); i++)
                delete planets.at(i);

            continue;
        }

        if (op == "5"){
            for(int i = 0; i < v_ssystems.size(); i++){
                cout << "-----------------------------" << endl;
                cout << "Id: " << v_ssystems.at(i).GetId() << endl;
                cout << "Nome: " << v_ssystems.at(i).GetName() << endl;
                cout << "Estrela(s): " << endl;
                for(int j = 0; j < v_ssystems.at(i).GetStars().size(); j++){
                    cout << "- Nome do Sol " << (j + 1) << ": " << v_ssystems.at(i).GetStars().at(j)->GetName() << endl;
                }

                cout << "Planetas: " << endl;
                for(int j = 0; j < v_ssystems.at(i).GetPlanets().size(); j++){
                    cout << "- Nome do Planeta " << (j + 1) << ": " << v_ssystems.at(i).GetPlanets().at(j)->GetName() << endl;
                }
            }
            continue;
        }

        if (op == "6"){
            size_t id;

            cout << "Qual a id do sistema solar a ser excluido?: ";
            cin >> id;
            cin.ignore();

            if(DeleteSolarSystem(v_ssystems, id))
                cout << "Sistema solar excluido com sucesso!" << endl;
            else    
                cout << "Sistema solar com esta id nao encontrado" << endl;
            
            SaveSolarSystem(v_ssystems);
            continue;
        }

        if (op == "7"){
            break;
        }
    }

    return 0;
}