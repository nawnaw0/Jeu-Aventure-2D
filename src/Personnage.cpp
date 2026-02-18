#include <iostream>
#include "../include/Personnage.h"
#include "../include/Moteur.h"

using namespace std;

Personnage::Personnage(Image skin,int skin_x, int skin_y, int x,int y, Direction direction, int Pos){
    _skin=skin;
    _skin_x = skin_x;
    _skin_y = skin_y;
    _x=x;
    _y=y;
    _direction = direction;
    _Pos = Pos;
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

void Personnage::deplacer(int dx, int dy)
{
    _x += dx;
    _y += dy;
}

bool Personnage::peutBougerVers(Direction d, Niveau niv)
{
    switch(d)
    {
    case(HAUT):
        return (_y!=0 && niv.caseEstLibre(_x,_y-TAILLE_CASE));
        break;

    case(BAS):
        return (_y!=HAUTEUR_FENETRE-TAILLE_CASE && niv.caseEstLibre(_x,_y+TAILLE_CASE));
        break;

    case(GAUCHE):
        return (_x!=0 && niv.caseEstLibre(_x-TAILLE_CASE,_y));
        break;

    case(DROITE):
        return (_x!=LARGEUR_FENETRE-TAILLE_CASE && niv.caseEstLibre(_x+TAILLE_CASE,_y));
        break;
    }
}

Direction Personnage::getDirection()const
{
    return _direction;
}

void Personnage::inverserDirection()
{
    switch(_direction)
    {
    case(HAUT):
        _direction = BAS;
        break;

    case(BAS):
        _direction = HAUT;
        break;

    case(GAUCHE):
        _direction = DROITE;
        break;

    case(DROITE):
        _direction = GAUCHE;
    }
}

int Personnage::getX()const
{
    return _x;
}

int Personnage::getY()const
{
    return _y;
}

void Personnage::mettreAjourAnimation()
{
    _Pos = (_Pos+1)%4;
    switch(_Pos)
    {
    case(0):
        _skin_x-=1;
        break;

    case(1):
        _skin_x+=1;
        break;

    case(2):
        _skin_x+=1;
        break;

    case(3):
        _skin_x-=1;
        break;
    }
}
