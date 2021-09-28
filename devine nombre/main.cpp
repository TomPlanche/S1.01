/**
  * @file main.cpp
  * @author Tom PLANCHE / Mathis HÉRIVEAU
  * @brief Jeu du Devine Nombre (pack 13) - S1.01 TD2 TP4 - IUT Bayonne
  * @date 08-09-2021
 **/

// Importation des bibliothèques nécessaires
#include <iostream>
#include <random>
#include <sstream>
#include <limits>
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

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(borneBasse, borneHaute);

    if ((int(distrib(gen))) == 0) { // La variable nombreSaisie étant initiée à 0, cela évite que le programme dise que le joueur à gagné sans même jouer.
        return randomTrouveInternet(borneBasse, borneHaute);
    }
    return int(distrib(gen));
}

int main(void)
{
    /**
     *  Programme : main
     *  But :  L'utilisateur doit trouver un nombre à partir des aides énoncées
     *  Date de dernière modification : 8 septembre 2021
     *  Auteur : T. Planche / M. Hériveau
     *  Remarques : Le programme commence le jeu, le nombre 0 est exclu.
     *  @param borneBasse entier demandé à l'utilisateur définissant la borne basse de la recherche
     *  @param borneHaute entier demandé à l'utilisateur définissant la borne haute de la recherche
     *  @param nombreDeTentative entier demandé à l'utilisateur définissant le nombre de tentatives qu'il souhaite avoir
     *  @param tentativeActuelle entier qui sera incrémentéà chaques tentatives
     *  @param nombreSaisie entier qui prendra la valeur entrée par l'utilisateur à chaques boucle
     *  @param nb_a_deviner entier qui sera aléatoirement généré entre les bornes choisies
    **/

    // INITIALISATION
    int borneBasse;
    int borneHaute;
    int nombreDeTentative;
    int tentativeActuelle = 0;
    int nombreSaisie;
    int nb_a_deviner;
    bool statutJoueur;

    // Affichage du nom et des règles.
    std::cout << "----- DEVINE NOMBRE -----" << std::endl;
    std::cout << "Le joueur doit essayer de deviner le nombre genere aleatoirement entre les bornes saisies.\n" << std::endl;

    std::cout << "Veuillez entrer des valeurs valides (bornes differentes de 0 ou borne basse < borne haute)" << std::endl;
    // Demande à l'utilisateur la saisie de la borne basse.
    std::cout << "Saisissez la borne basse : ";
    std::cin >> borneBasse;

    // Idem pour la borne haute.
    std::cout << "Saisissez la borne haute : ";
    std::cin >> borneHaute;

    // Génère un nombre aléatoire entre les deux bornes choisies
    nb_a_deviner = randomTrouveInternet(borneBasse, borneHaute);

    // Demande à l'utilisateur le nombre de nombreSaisies qu'il souhaite avoir
    do {
        std::cout << "Combien de tentative voulez vous avoir (minimum 1) ? : ";
        std::cin >> nombreDeTentative;
    } while (nombreDeTentative < 1);

    // TRAITEMENT - DÉBUT DU JEU

    // Boucle qui tourne tant que la nombreSaisie de l'utilisateur n'est pas la bonne
    while (nombreSaisie != nb_a_deviner) {
        // Incrémente le nombre de tentatives à chaques passages de la boucle
        tentativeActuelle++;

        std::cout << "\nSaisissez un nombre entre " << borneBasse << " et " << borneHaute << ". Tentative numero " << tentativeActuelle << "/" << nombreDeTentative << " : ";
        std::cin >> nombreSaisie;

        // Boucle qui vérifie certaines conditions
        if (tentativeActuelle == nombreDeTentative && nombreSaisie != nb_a_deviner) { // Si l'utilisateur est a court de tentatives
            statutJoueur=false;
            break;
        } else if (nombreSaisie < nb_a_deviner) { // Si la nombreSaisie est trop petite
            std::cout << "Nombre trop petit !" << std::endl;
        } else if (nombreSaisie > nb_a_deviner) { // Si la nombreSaisie est trop grande
            std::cout << "Nombre trop grand !" << std::endl;
        } else {
            statutJoueur=true;
            break;
        }
    }
    // Si on sort de cette boucle c'est que l'utilisateur à trouvé le bon nombre, on le félicite alors

    if (statutJoueur==false) {
        std::cout << "\nF I N I : toutes les tentatives ont ete consommees." << std::endl;  
    } else {
        std::cout << "\n GAGNE! il vous a fallu " << tentativeActuelle << " tentatives." << std::endl;
    }

    return 0;
}
