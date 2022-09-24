#ifndef STAR_HPP
#define STAR_HPP

#include "astro.hpp"

using namespace std;

class Star : public Astro {
    private:
        //Tipo de estrela
        string m_starType;
        //Massa em massas solares
        double m_mass;
        //Raio solar
        size_t m_radius;
        //Magnitude aparente
        double m_appaMag;
        //Magnitude absoluta
        double m_absMag;
    protected:
    public:
        Star() {};
        Star(size_t id, string name, vector<int> &dec, vector<int> &ra, double &distance, string starType, double mass, size_t radius, double appaMag, double absMag) :
         Astro(id, name, dec, ra, distance), m_starType(starType), m_mass(mass), m_radius(radius), m_appaMag(appaMag), m_absMag(absMag) {};
        ~Star(){};

        //Getters/Setters
        string GetStarType() const { return m_starType; };
        void SetStarType(string starType) { m_starType = starType; };
        double GetMass() const { return m_mass; };
        void SetMass(double mass) { m_mass = mass; };
        size_t GetRadius() const { return m_radius; };
        void SetRadius(size_t radius) { m_radius = radius; };
        double GetAppaMag() const { return m_appaMag; };
        void SetAppaMag(double appaMag) { m_appaMag = appaMag; };
        double GetAbsMag() const { return m_absMag; };
        void SetAbsMag(double absMag) { m_absMag = absMag; };

        
};

Star* FindStar(size_t idSol, const vector<Star> &v_stars);
bool SaveStar(const vector<Star> &v_star);
void LoadStars(vector<Star> &v_star);
bool DeleteStar(vector<Star> &v_star, size_t id);

#endif
