#include <iostream>
#include "../include/Objet.h"
#include "../include/Moteur.h"

using namespace std;

Objet::Objet(Image img, string nom, Dictionnaire dico, int x, int y)
{
    dico.recherche(_tuile,nom);
    _img = img;
    _x = x*TAILLE_CASE;
    _y = y*TAILLE_CASE;
}

void Objet::dessiner()const
{
   _img.dessiner(_x,_y,_tuile.getX()*TAILLE_CASE,_tuile.getY()*TAILLE_CASE,TAILLE_CASE,TAILLE_CASE);
}

Tuile Objet::getTuile()const
{
    return _tuile;
}

int Objet::getX()const
{
    return _x;
}

int Objet::getY()const
{
    return _y;
}

void Objet::cacher()
{
    _tuile.setPropriete("cache");
}

