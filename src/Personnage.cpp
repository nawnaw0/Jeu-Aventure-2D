#include <iostream>
#include "Personnage.h"

using namespace std;

Personnage::Personnage(Image skin,int skin_x, int skin_y, int x,int y, Direction direction){
    _skin=skin;
    _skin_x = skin_x;
    _skin_y = skin_y;
    _x=x;
    _y=y;
    _direction = direction;
}

void Personnage::dessiner()const
{
    switch(_direction)
    {
    case(BAS):
        _skin.dessiner(_x,_y,_skin_x*16,_skin_y*16,16,16);
        break;

    case(HAUT):
        _skin.dessiner(_x,_y,_skin_x*16,(_skin_y+3)*16,16,16);
        break;

    case(DROITE):
        _skin.dessiner(_x,_y,_skin_x*16,(_skin_y+2)*16,16,16);
        break;

    case(GAUCHE):
        _skin.dessiner(_x,_y,_skin_x*16,(_skin_y+1)*16,16,16);
        break;
    }
}

void Personnage::regarderBas()
{
    _direction = BAS;
}

void Personnage::regarderDroite()
{
    _direction = DROITE;
}

void Personnage::regarderGauche()
{
    _direction = GAUCHE;
}

void Personnage::regarderHaut()
{
    _direction = HAUT;
}
