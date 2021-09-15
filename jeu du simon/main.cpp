/**
  * @file main.cpp
  * @author T.Planche and M.Heriveau
  * @brief fichier du jeu du simon
  * @date 10 septembre 2021
  **/

namespace OS
{
  void clear() {
#ifdef _WIN32
    system("cls");
#elif __APPLE__
    system("clear");
#endif
  }
}

#include <iostream>
#include <random>
#include <unistd.h>


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

    std::random_device rd; 
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(borneBasse, borneHaute);

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


   //INITIALISATION
    char choixUtilisateur;
    int tentative = 1;
    std::string saisieDuSimon;
    int score = 0;
    
    /*std::string choixDisponibles = "vbrj";
    //int milliSecondes = 1000;

    // TODO : Commencer l'algo


    std::cout << choixDisponibles[2] << std::endl;
    std::cout << choixDisponibles.find('v') << std::endl;

    std::cin >> choixUtilisateur;

    std::cout << (std::string("pfc").find(choixUtilisateur) != 0) << std::endl;

	std::cout << "test" << std::endl;*/


    while(tentative != 0)
    {

        // Le Simon saisie la liste des couleurs par le Simon 
        std::cout << "** Jeu du Simon **" << std::endl << std::endl;
        std::cout << "Simon : " ; //Mettre la liste des couleurs
        usleep(1000000);
        std::cout << std::endl << "3... ";
        usleep(1000000);
        std::cout << "2... ";
        usleep(1000000);
        std::cout << "1... " << std::endl;
        OS::clear();

        // Au tour du joueur 
        std::cout << "** Jeu du Simon **" << std::endl;
        std::cout << "[v -> vert, r -> rouge, b -> bleu, j -> jaune]" << std::endl << std::endl;
        std::cout << "Joueur : ";
        std::cin >> saisieDuSimon;

        // Augmentation du score
        score++;
        // Attente entre les 2 interfaces (Simon/joueur)
        usleep(1000000); 
        OS::clear();
    }


    // INITIALISATION
    return 0;
}
