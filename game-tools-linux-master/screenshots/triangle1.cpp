/**
 * @file main.cpp
 * @author Patrick Etcheverry
 * @brief un petit programme de démonstration illustrant les fonctionnalités du module game-tools  
 * @date 2021-07-12
 */
#include "game-tools.h"
#include <iostream>
using namespace std;

int main(void)
{
 
    // Mettre en pause le programme
    pause();
    cout << endl;
    cout << "Appuyer sur Entree pour afficher progressivement un triangle en couleur...";
    pause();

    // Afficher un triangle coloré de manière progressive
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
cout << endl << endl;

    return 0;
}

