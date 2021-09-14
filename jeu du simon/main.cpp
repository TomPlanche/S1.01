/**
  * @file main.cpp
  * @author T.Planche and M.Heriveau
  * @brief fichier du jeu du simon
  * @date 10 septembre 2021
  **/

#include <iostream>
#include <random>
#include <unistd.h>

using namespace std;





int randomTrouveInternet(int borneBasse, int borneHaute)
{
    /**
      * Programme : randomTrouveInternet
      * But : Générer un nombre aléatoire entre deux bornes entières. Trouvé sur internet car le random de Patrick Etcheverry ne fonctionne pas
      * @author Bill Lynch
      * Date de dernière modification :  08-09-21
      * Remarques : les deux nombres doivent être des entiers
      * @param borneBasse entier définissant la borne basse de génération
      * @param borneHaute entier définissant la borne haute de génération
      **/

    random_device rd; 
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(borneBasse, borneHaute);

    if ((int(distrib(gen))) == 0) { // La variable tentative étant initiée à 0, cela évite que le programme dise que le joueur à gagné sans même jouer.
        return randomTrouveInternet(borneBasse, borneHaute);
    }
    return int(distrib(gen));
}
  
int main(void) {
    /*
        Programme : main
        But :  Lance le jeu
        Date de dernière modification : 10 septembre 2021
        Auteur : T. Planche
        Remarques : pas commencé
    */
    char choixUtilisateur;
    string choixDisponibles = "pfc";
    int milliSecondes = 1000;

    // TODO : Commencer l'algo
    // ! : Trouver fonction sleep.


    cout << choixDisponibles[2] << endl;
    cout << choixDisponibles.find('p') << endl;

    cin >> choixUtilisateur;

    cout << (string("pfc").find(choixUtilisateur) != 0) << endl;

    system("clear");



    
    



    // INITIALISATION
    return 0;
}