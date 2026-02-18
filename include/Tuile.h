#ifndef TUILE_H_INCLUDED
#define TUILE_H_INCLUDED
#include <fstream>

using namespace std;

class Tuile
{
    string _nom;
    int _x;
    int _y;
    string _prop;

public:
    Tuile(string nom = "null", int x = 0, int y = 0, string prop = "normale");
    Tuile(ifstream& entree);
    void afficher()const;
    string getNom()const;
    int getX()const;
    int getY()const;
    string getProp()const;
    void setPropriete(const string& NewProp);
};

#endif // TUILE_H_INCLUDED
