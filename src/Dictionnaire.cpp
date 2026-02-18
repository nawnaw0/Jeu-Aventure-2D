#include <iostream>
#include <fstream>
#include "../include/Tuile.h"
#include "../include/Dictionnaire.h"

using namespace std;

Dictionnaire::Dictionnaire(string nomFichier)
{
    ifstream entree;
    int ligne;
    entree.open(nomFichier);
    entree>>ligne;
    for(int i = 0;i<ligne;i++)
    {
        _tuiles.push_back(Tuile(entree));
    }
    entree.close();
}

void Dictionnaire::afficher()const
{
    for(int i = 0;i<_tuiles.size();i++)
    {
        _tuiles[i].afficher();
    }
}

bool Dictionnaire::recherche(Tuile& tuile, string nom)const     //Recherche Dichotomique
{
    int debut = 0, fin = _tuiles.size(), milieu,ind = -1;
    bool trouve = false;
    while (!trouve && debut <= fin)
    {
        milieu = (debut + fin)/2;
        trouve = (_tuiles[milieu].getNom()==nom);
        if(trouve)
        {
            ind = milieu;
            tuile = _tuiles[ind];
        }
        else
        {
            if(_tuiles[milieu].getNom()>nom)
            {
                fin = milieu - 1;
            }
            else
            {
                debut = milieu + 1;
            }
        }
    }
    return trouve;
}
