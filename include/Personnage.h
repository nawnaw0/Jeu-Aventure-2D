#ifndef PERSONNAGE_H_INCLUDED
#define PERSONNAGE_H_INCLUDED
#include "Image.h"

enum Direction{GAUCHE,
                DROITE,
                HAUT,
                BAS};

class Personnage
{
    Image _skin;
    int _skin_x;
    int _skin_y;
    int _x;
    int _y;
    Direction _direction;


public:

    Personnage(Image skin,int skin_x,int skin_y, int x,int y, Direction d = BAS);
    void dessiner()const;
    void regarderDroite();
    void regarderGauche();
    void regarderHaut();
    void regarderBas();
};


#endif // PERSONNAGE_H_INCLUDED
