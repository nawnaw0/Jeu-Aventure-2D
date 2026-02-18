#include <iostream>
#include "../include/Moteur.h"

#include "Ennemi.h"

using namespace std;

Ennemi::Ennemi(Image skin,int skin_x,int skin_y, int x,int y, Direction d, int Pos):_perso(skin, skin_x, skin_y, x*TAILLE_CASE, y*TAILLE_CASE, d, Pos)
{}

void Ennemi::dessiner()const
{
    _perso.dessiner();
}

void Ennemi::avancer(Niveau niv){
    int nombre = rand()%4;
    switch(nombre)
    {
    case(0):
        if(_perso.peutBougerVers(HAUT,niv))
        {
            _perso.deplacer(0,-TAILLE_CASE);
            _perso.regarderHaut();
        }
        break;

    case(1):
        if(_perso.peutBougerVers(BAS,niv))
        {
            _perso.deplacer(0,TAILLE_CASE);
            _perso.regarderBas();
        }
        break;

    case(2):
        if(_perso.peutBougerVers(GAUCHE,niv))
        {
            _perso.deplacer(-TAILLE_CASE,0);
            _perso.regarderGauche();
        }
        break;

    case(3):
        if(_perso.peutBougerVers(DROITE,niv))
        {
            _perso.deplacer(TAILLE_CASE,0);
            _perso.regarderDroite();
        }
        break;
    }
    /*
    if(_perso.peutBougerVers(_perso.getDirection()))
    {
        switch(_perso.getDirection())
        {
        case(HAUT):
            _perso.deplacer(0,-16);
            _perso.regarderHaut();
            break;

        case(BAS):
            _perso.deplacer(0,16);
            _perso.regarderBas();
            break;

        case(GAUCHE):
            _perso.deplacer(-16,0);
            _perso.regarderGauche();
            break;

        case(DROITE):
            _perso.deplacer(16,0);
            _perso.regarderDroite();
            break;
        }
    }
    else
        _perso.inverserDirection();
    */
}

int Ennemi::getX()const
{
    return _perso.getX();
}

int Ennemi::getY()const
{
    return _perso.getY();
}

void Ennemi::mettreAjourAnimation()
{
    _perso.mettreAjourAnimation();
}


