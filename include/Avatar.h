#ifndef AVATAR_H_INCLUDED
#define AVATAR_H_INCLUDED

#include "Personnage.h"
#include "Ennemi.h"

class Avatar
{
    Personnage _perso;

public:
    Avatar(Image skin,int skin_x,int skin_y, int x,int y, Direction d = BAS, int Pos = 1);
    void dessiner()const;
    void allerDroite(Niveau& niv);
    void allerBas(Niveau& niv);
    void allerHaut(Niveau& niv);
    void allerGauche(Niveau& niv);
    bool touche(Ennemi e)const;
    void mettreAjourAnimation();
};


#endif // AVATAR_H_INCLUDED
