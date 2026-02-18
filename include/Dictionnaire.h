#ifndef DICTIONNAIRE_H_INCLUDED
#define DICTIONNAIRE_H_INCLUDED
#include <vector>
#include "Tuile.h"

class Dictionnaire
{
    vector<Tuile> _tuiles;

public:
    Dictionnaire(string nomFichier);
    void afficher()const;
    bool recherche(Tuile& tuile,string nom)const;
};

#endif // DICTIONNAIRE_H_INCLUDED
