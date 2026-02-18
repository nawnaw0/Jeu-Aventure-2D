#ifndef NIVEAU_H_INCLUDED
#define NIVEAU_H_INCLUDED

#include "Image.h"
#include "Objet.h"
#include "Dictionnaire.h"
#include <vector>

class Niveau{

    vector<Objet> _objets;
    int _nbBonus;

public:

    Niveau(Image img, string nomF, Dictionnaire dico);
    void dessiner()const;
    int indiceObjet(int x, int y, string prop)const;
    bool caseEstLibre(int x, int y)const;
    void testerBonusEtPrendre(int x, int y);
    bool gagne()const;
};

#endif // NIVEAU_H_INCLUDED
