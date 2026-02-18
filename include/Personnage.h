#ifndef PERSONNAGE_H_INCLUDED
#define PERSONNAGE_H_INCLUDED
#include "Image.h"
#include "Niveau.h"

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
    int _Pos;


public:

    Personnage(Image skin,int skin_x,int skin_y, int x,int y, Direction d = BAS,int Pos = 1);
    void dessiner()const;
    void regarderDroite();
    void regarderGauche();
    void regarderHaut();
    void regarderBas();
    void deplacer(int dx, int dy);
    bool peutBougerVers(Direction d, Niveau niv);
    Direction getDirection()const;
    void inverserDirection();
    int getX()const;
    int getY()const;
    void mettreAjourAnimation();
};


#endif // PERSONNAGE_H_INCLUDED
