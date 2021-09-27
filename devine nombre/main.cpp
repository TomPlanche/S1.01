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
#include "game-tools-linux.h"

using std::cout;
using std::cin;
using std::endl;


int insererNombre(signed short int borneBasse, signed short int borneHaute)
{
    /**
     *  Programme : insererNombre
     *  But :  Demandez, avec une phrase spéciale, à l'utilisateur de saisir un nombre
     *  Date de dernière modification : 10 septembre 2021
     *  Auteur : T. Planche / M. Hériveau
     *  Remarques : L'utilisateur doit saisir un entier
     *  @param nombre entier demandé à l'utilisateur
     *  @param borneBasse entier avec signe - borne basse
     *  @param borneBasse entier avec signe - borne haute
    **/
    signed short int nombre;

    while (true) // Tant que l'input n'est pas bon
    {
        cout << "Saisissez un nombre entre " << borneBasse << " et " << borneHaute << " : ";
        cin >> nombre;

        break;
    }

    return nombre;
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
     *  @param choixTentatives entier demandé à l'utilisateur définissant le nombre de tentatives qu'il souhaite avoir
     *  @param nbDeTentatives entier qui sera incrémentéà chaques tentatives
     *  @param tentative entier qui prendra la valeur entrée par l'utilisateur à chaques boucle
     *  @param nb_a_deviner entier qui sera aléatoirement généré entre les bornes choisies
    **/

    // INITIALISATION
    signed short int borneBasse;
    signed short int borneHaute;
    signed short int choixTentatives;
    unsigned short int nbDeTentatives = 0;
    signed short int tentative = 0;
    signed short int nb_a_deviner;


    // Affichage du nom et des règles.
    cout << "----- DEVINE NOMBRE -----" << endl;
    cout << "Le joueur doit essayer de deviner le nombre généré aléatoirement entre les bornes saisies.\n" << endl;

    do {
        cout << "\nVeuillez entrer des valeurs valides pour les bornes (bornes différentes et borne basse < borne haute)" << endl;

        borneBasse = insererNombre("Saisissez la borne basse : ");
        borneHaute = insererNombre("Saisissez la borne haute : ");
    
    } while (borneBasse == borneHaute || borneBasse > borneHaute);

    // Génère un nombre aléatoire entre les deux bornes choisies
    nb_a_deviner = random(borneBasse, borneHaute);

    // Demande à l'utilisateur le nombre de tentatives qu'il souhaite avoir
    choixTentatives = insererNombre("\nCombien de vies voulez vous avoir (minimum 1) ? : ");

    // TRAITEMENT - DÉBUT DU JEU

    // Boucle qui tourne tant que la tentative de l'utilisateur n'est pas la bonne
    while (tentative != nb_a_deviner)
    {   
        // Incrémente le nombre de tentatives à chaques passages de la boucle
        nbDeTentatives++;

        // Demande à l'utilisateur de saisir sa tentative
        tentative = insererNombre(borneBasse, borneHaute);

        // Boucle qui vérifie certaines conditions
        if (nbDeTentatives == choixTentatives && tentative != nb_a_deviner) // Si l'utilisateur est a court de tentatives
        {
            cout << "\nPerdu :( le nombre était " << nb_a_deviner << "." << endl;
            return 0;
        } else if (tentative < nb_a_deviner) // Si la tentative est trop petite
        {
            cout << "Nombre trop petit !" << endl;
        } else if (tentative > nb_a_deviner)// Si la tentative est trop grande
        {
            cout << "Nombre trop grand !" << endl;
        }

    }
    // Si on sort de cette boucle c'est que l'utilisateur à trouvé le bon nombre, on le félicite alors
    cout << "\n GAGNÉ ! il vous a fallu " << nbDeTentatives << " tentatives." << endl;

    return 0;
}
