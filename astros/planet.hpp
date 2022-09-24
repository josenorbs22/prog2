#ifndef PLANET_HPP
#define PLANET_HPP

#include "astro.hpp"

using namespace std;

class Planet : public Astro {
    private:
      //Tamanho diametro (kilometros)
        double m_size;
        //Se tem potencial ou não de conter vida
        bool m_exoplanet;
        //Nome do sistema solar
        string m_SSName;
        //Posição em ordem em relação aos outros planetas do sistema solar
        int m_pos;
        //Principais materiais do planeta
        string m_materials;
    protected:
    public:
        Planet(){};
        Planet(size_t id, string name, vector<int> &dec, vector<int> &ra, double &distance, double size, bool exoplanet, string SSName, int pos, string materials) :
          Astro(id, name, dec, ra, distance), m_size(size), m_exoplanet(exoplanet), m_SSName(SSName), m_pos(pos), m_materials(materials) {};
        ~Planet(){};

        //Getters/Setters
        size_t GetSize() const { return m_size; };
        void SetSize(double size) { m_size = size; };
        bool GetExoplanet() const { return m_exoplanet; };
        void SetExoplanet(bool exoplanet) { m_exoplanet = exoplanet; };
        string GetSSName() const { return m_SSName; };
        void SetSSName(string SSName) { m_SSName = SSName; };
        int GetPos() const { return m_pos; };
        void SetPos(int pos) { m_pos = pos; };
        string GetMaterials() const { return m_materials; };
        void SetMaterials(string materials) { m_materials = materials; };

        
};

Planet* FindPlanet(size_t idPlanet, const vector<Planet> &v_planets);
bool SavePlanet(const vector<Planet> &v_planet);
void LoadPlanets(vector<Planet> &v_planet);
bool DeletePlanet(vector<Planet> &v_planet, size_t id);

#endif
