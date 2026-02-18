#include <iostream>
#include <fstream>
#include "../include/Tuile.h"

using namespace std;

Tuile::Tuile(string nom, int x, int y, string prop)
{
    _nom = nom;
    _x = x;
    _y = y;
    _prop = prop;
}

Tuile::Tuile(ifstream& entree)
{
    entree >> _nom;
    entree >> _x;
    entree >> _y;
    entree >> _prop;
}

void Tuile::afficher()const
{
    cout << _nom << ": x=" << _x << ", y=" << _y << ", objet " << _prop << endl;
}

string Tuile::getNom()const
{
    return _nom;
}

int Tuile::getX()const
{
    return _x;
}

int Tuile::getY()const
{
    return _y;
}

string Tuile::getProp()const
{
    return _prop;
}

void Tuile::setPropriete(const string& NewProp)
{
    _prop = NewProp;
}
