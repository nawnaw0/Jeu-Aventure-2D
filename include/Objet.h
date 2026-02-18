#ifndef OBJET_H_INCLUDED
#define OBJET_H_INCLUDED
#include "Image.h"
#include "Tuile.h"
#include "Dictionnaire.h"
#include <fstream>

class Objet
{
    Image _img;
    int _x;
    int _y;
    Tuile _tuile;

public:
    Objet(Image img, string nom, Dictionnaire dico, int x, int y);
    void dessiner()const;
    Tuile getTuile()const;
    int getX()const;
    int getY()const;
    void cacher();
};


#endif // OBJET_H_INCLUDED
