#ifndef ASTRO_HPP
#define ASTRO_HPP

#include <iostream>
#include <vector>
#include <fstream>
#include <QFile>

using namespace std;

class Astro {
    private:
    protected:
        size_t m_id;
        //Nome
        string m_name;
        //Declinação (coodernadas equatoriais celestes)
        vector<int> m_dec;
        //Ascenção Reta (coordenadas equatoriais celestes)
        vector<int> m_rA;
        //Distância (anos luz)
        float m_distance;
    public:
        Astro() : m_id(0), m_name("") {};
        Astro(size_t id, string name) : m_id(id), m_name(name) {};
        Astro(size_t id, string name, vector<int> &dec, vector<int> &ra, float &distance) : m_id(id), m_name(name), m_dec(dec), m_rA(ra), m_distance(distance) {};
        ~Astro(){};

        //Getters/Setters
        size_t GetId() const { return m_id; };
        void SetId(size_t id) { m_id = id; };
        string GetName() const { return m_name; };
        void SetName(string name) { m_name = name; };
        vector<int> GetDec() const { return m_dec; };
        void SetDec(vector<int> dec) { m_dec = dec; };
        vector<int> GetRA() const { return m_rA; };
        void SetRA(vector<int> ra) { m_rA = ra; };
        float GetDistance() const { return m_distance; };
        void SetDistance(float distance) { m_distance = distance; };
};

bool SaveAstro(const vector<Astro> &v_astro);
void LoadAstros(vector<Astro> &v_astro);
bool DeleteAstro(vector<Astro> &v_astro, size_t id);
size_t FindLastId(const vector<Astro> &v_astro);

#endif