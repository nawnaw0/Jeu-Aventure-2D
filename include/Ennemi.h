#ifndef ENNEMI_H_INCLUDED
#define ENNEMI_H_INCLUDED

#include "Personnage.h"

class Ennemi
{
    Personnage _perso;

public:
    Ennemi(Image skin,int skin_x,int skin_y, int x,int y, Direction d = BAS, int Pos = 1);
    void dessiner()const;
    void avancer(Niveau niv);
    int getX()const;
    int getY()const;
    void mettreAjourAnimation();
};


#endif // ENNEMI_H_INCLUDED
