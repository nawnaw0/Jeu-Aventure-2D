#include <iostream>
#include <fstream>
#include <vector>

#include "../include/Objet.h"
#include "../include/Dictionnaire.h"
#include "../include/Image.h"
#include "../include/Niveau.h"

using namespace std;

Niveau::Niveau(Image img, string nomF, Dictionnaire dico)
{
    ifstream entree;
    int ligne, x, y;
    string nom;
    _nbBonus = 0;
    entree.open(nomF);
    entree>>ligne;
    for(int i = 0;i<ligne;i++)
    {
        entree >> nom;
        entree >> x;
        entree >> y;
        _objets.push_back(Objet(img, nom, dico, x, y));
        if(_objets.back().getTuile().getProp() == "bonus")
        {
            _nbBonus++;
        }
    }
    entree.close();
    cout << "Niveau charge :  " << _nbBonus << " bonus" << endl;
}

void Niveau::dessiner()const
{
    for(int i = 0; i<_objets.size();i++)
    {
        if(_objets[i].getTuile().getProp() != "cache")
        {
            _objets[i].dessiner();
        }
    }
}

int Niveau::indiceObjet(int x, int y, string prop)const
{
    for(int i = 0;i < _objets.size();i++)
    {
        if(_objets[i].getTuile().getProp() == prop && _objets[i].getX() == x && _objets[i].getY() == y)
        {
            return i;
        }
    }
    return -1;
}

bool Niveau::caseEstLibre(int x, int y)const
{
    if(indiceObjet(x, y, "solide") == -1)
    {
        return true;
    }
    return false;
}

void Niveau::testerBonusEtPrendre(int x, int y)
{
    int ind = indiceObjet(x, y, "bonus");


    if(ind != -1)
    {
        _objets[ind].cacher();
        _nbBonus--;
        cout << "Objet collecte ! Bonus restants : " << _nbBonus << endl;
    }
}

bool Niveau::gagne()const
{
    return _nbBonus==0;
}
