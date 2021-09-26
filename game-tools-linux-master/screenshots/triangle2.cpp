#include "game-tools.h"
#include <iostream>
using namespace std;

int main(void)
{
    // Afficher un triangle coloré de manière progressive
    pause();
    cout << "** Un triangle en couleur qui s'affiche progressivement **" << endl;
    afficherTexteEnCouleur("*", bleu, true);
    pause(1);
    afficherTexteEnCouleur("**", vert, true);
    pause(1);
    afficherTexteEnCouleur("***", cyan, true);
    pause(1);
    afficherTexteEnCouleur("****", rouge, true);
    pause(1);
    afficherTexteEnCouleur("******", jaune, true);

    // Mettre en pause le programme
    cout << endl;
    cout << "Appuyer sur Entree pour effacer l'ecran et afficher le triangle en sens inverse...";
    pause();

    effacer(); // <--- ON EFFACE LE CONTENU DU TERMINAL AVANT D'AFFICHER LE SECOND TRIANGLE

    // Afficher le triangle coloré de manière progressive et en sens inverse
    afficherTexteEnCouleur("******", jaune, true);
    pause(1);
    afficherTexteEnCouleur("****", rouge, true);
    pause(1);
    afficherTexteEnCouleur("***", cyan, true);
    pause(1);
    afficherTexteEnCouleur("**", vert, true);
    pause(1);
    afficherTexteEnCouleur("*", bleu, true);
    cout << endl << endl;


    return 0;
}

