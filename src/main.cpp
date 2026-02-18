#include <vector>
#include <fstream>

#include "../include/Moteur.h"
#include "../include/Image.h"
#include "../include/Personnage.h"
#include "../include/Avatar.h"
#include "../include/Ennemi.h"
#include "../include/Dictionnaire.h"
#include "../include/Objet.h"
#include "../include/Niveau.h"

using namespace std;

int main(int, char**) // Version special du main, ne pas modifier
{
    // Initialisation du jeu
    Moteur moteur("Mon super jeu vidéo",6);

    // TODO: charger images, creer personnages, etc.
    Image image(moteur, "assets/fond.png");
    //Image coffreF(moteur, "assets/coffre_ferme.png");
    //Image coffreO(moteur, "assets/coffre_ouvert.png");
    Image skin(moteur, "assets/personnages.png");
    Image objet(moteur, "assets/objets.png");
    Image perdue(moteur, "assets/gameover.png");
    Image gagne(moteur, "assets/bravo.png");

    Avatar Chevalier(skin,4,0,1,2);
    Ennemi Ennemie1(skin,10,0,5,2);
    Ennemi Ennemie2(skin,7,4,1,5,DROITE);

    Dictionnaire dictionnaire("assets/dictionnaire.txt");
    dictionnaire.afficher();

    Niveau niv1(objet,"assets/niveau.txt",dictionnaire);
    /*
    dictionnaire.recherche(test, "Patate");
    test.afficher();
    */


    bool quitter = false;
    bool Mort = false;
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
                //Chevalier.regarderGauche();
                Chevalier.allerGauche(niv1);
                break;

            case DROITE_APPUYE:
                //Chevalier.regarderDroite();
                Chevalier.allerDroite(niv1);
                break;

            case HAUT_APPUYE:
                //Chevalier.regarderHaut();
                Chevalier.allerHaut(niv1);
                break;

            case BAS_APPUYE:
                //Chevalier.regarderBas();
                Chevalier.allerBas(niv1);
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
        if(moteur.animationsAmettreAjour())
        {
            Ennemie1.avancer(niv1);
            Ennemie2.avancer(niv1);
            Chevalier.mettreAjourAnimation();
            Ennemie1.mettreAjourAnimation();
            Ennemie2.mettreAjourAnimation();
        }

        Mort=(Chevalier.touche(Ennemie1)||Chevalier.touche(Ennemie2));

        if(Mort)
        {
            moteur.initialiserRendu();
            perdue.dessiner(LARGEUR_FENETRE/6, HAUTEUR_FENETRE/6);
            moteur.finaliserRendu();
            moteur.attendre(2);
            quitter = true;
        }
        if(niv1.gagne())
        {
            moteur.initialiserRendu();
            gagne.dessiner(LARGEUR_FENETRE/6, HAUTEUR_FENETRE/6);
            moteur.finaliserRendu();
            moteur.attendre(2);
            quitter = true;
        }


        // III. Generation de l'image à afficher

        moteur.initialiserRendu(); // efface ce qui avait ete affiche precedemment et reinitalise en ecran noir

        niv1.dessiner();
        Chevalier.dessiner();
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
