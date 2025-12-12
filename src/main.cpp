#include <vector>

#include "Moteur.h"
#include "Image.h"
#include "Personnage.h"

using namespace std;

int main(int, char**) // Version special du main, ne pas modifier
{
    // Initialisation du jeu
    Moteur moteur("Mon super jeu vidéo");

    // TODO: charger images, creer personnages, etc.
    int y=0, x=0;

    Image image(moteur, "assets/fond.png");
    //Image coffreF(moteur, "assets/coffre_ferme.png");
    //Image coffreO(moteur, "assets/coffre_ouvert.png");
    Image skin(moteur, "assets/personnages.png");

    Personnage Hero(skin,4,0,0,0);
    Personnage Ennemie1(skin,10,0,5*TAILLE_CASE,TAILLE_CASE);
    Personnage Ennemie2(skin,7,4,TAILLE_CASE,5*TAILLE_CASE);

    bool quitter = false;
    //bool coffre = false;
    //bool monte = false;
    //bool cote = false;


    // Boucle de jeu, appelee a chaque fois que l'ecran doit etre mis a jour
    // (en general, 60 fois par seconde)
    while (!quitter)
    {
        // I. Gestion des evenements
        Evenement evenement = moteur.evenementRecu();
        while (evenement != AUCUN)
        {
            switch (evenement)
            {
            // QUITTER = croix de la fenetre ou Echap
            case QUITTER_APPUYE:
                quitter = true;
                break;

            // TODO: gerer les autres evenements
            case ESPACE_APPUYE:
                /*
                coffre = true;
                break;
                */

            case ESPACE_RELACHE:
                /*
                coffre = false;
                break;
                */

            case GAUCHE_APPUYE:
                Hero.regarderGauche();
                break;

            case DROITE_APPUYE:
                Hero.regarderDroite();
                break;

            case HAUT_APPUYE:
                Hero.regarderHaut();
                break;

            case BAS_APPUYE:
                Hero.regarderBas();
                break;


            default:
                break;
            }

            evenement = moteur.evenementRecu();
        }

        // II. Mise à jour de l'état du jeu

        // TODO: faire bouger vos personnages, etc.
        /*
        if(monte)
            y-=1;
        else
            y+=1;
        if(cote)
            x-=1;
        else
            x+=1;
        if(y==HAUTEUR_FENETRE-16)
            monte = true;
        if(y<0)
            monte = false;
        if(x==LARGEUR_FENETRE-16)
            cote = true;
        if(x<0)
            cote = false;
        */


        // III. Generation de l'image à afficher

        moteur.initialiserRendu(); // efface ce qui avait ete affiche precedemment et reinitalise en ecran noir

        image.dessiner(0,0);
        Hero.dessiner();
        Ennemie1.dessiner();
        Ennemie2.dessiner();
        /*
        if(coffre)
        {
            coffreO.dessiner(x,y);
        }
        else
        {
            coffreF.dessiner(x,y);
        }
        */

        // TODO: afficher vos personnages, objets, etc.

        /*
          Affiche l'image en se cadencant sur la frequence de
          rafraichissement de l'ecran (donc va en general mettre le
          programme en pause jusqu'a ce que l'ecran soit rafraichi). En
          general, 60 images fois par seconde, mais ca peut dependre du
          materiel
        */
        moteur.finaliserRendu();
    }

    return 0;
}
