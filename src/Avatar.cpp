#include <iostream>

#include "Avatar.h"

using namespace std;

Avatar::Avatar(Image skin,int skin_x,int skin_y, int x,int y, Direction d, int Pos):_perso(skin, skin_x, skin_y, x*TAILLE_CASE, y*TAILLE_CASE, d, Pos)
{}

void Avatar::dessiner()const
{
    _perso.dessiner();
}

void Avatar::allerDroite(Niveau& niv)
{
    if(_perso.peutBougerVers(DROITE,niv))
    {
        _perso.deplacer(TAILLE_CASE,0);
        niv.testerBonusEtPrendre(_perso.getX(), _perso.getY());
    }
    _perso.regarderDroite();
}

void Avatar::allerGauche(Niveau& niv)
{
    if(_perso.peutBougerVers(GAUCHE,niv))
    {
        _perso.deplacer(-TAILLE_CASE,0);
        niv.testerBonusEtPrendre(_perso.getX(), _perso.getY());
    }
    _perso.regarderGauche();
}

void Avatar::allerHaut(Niveau& niv)
{
    if(_perso.peutBougerVers(HAUT, niv))
    {
        _perso.deplacer(0,-TAILLE_CASE);
        niv.testerBonusEtPrendre(_perso.getX(), _perso.getY());
    }
    _perso.regarderHaut();
}

void Avatar::allerBas(Niveau& niv)
{
    if(_perso.peutBougerVers(BAS,niv))
    {
        _perso.deplacer(0,TAILLE_CASE);
        niv.testerBonusEtPrendre(_perso.getX(), _perso.getY());
    }
    _perso.regarderBas();
}

bool Avatar::touche(Ennemi e)const
{
    return(_perso.getX()==e.getX()&&_perso.getY()==e.getY());
}

void Avatar::mettreAjourAnimation()
{
    _perso.mettreAjourAnimation();
}
