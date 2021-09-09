/**
  * @file main.cpp
  * @author Tom PLANCHE / Mathis HÉRIVEAU
  * @brief Jeu du Devine Nombre
  * @date 08-09-2021
 **/

#include <iostream>
#include <random>
#include <sstream>
#include <limits>


using namespace std;


int random_trouve_internet(int borne_m, int borne_p)
{
    random_device rd;  // Will be used to obtain a seed for the random number engine
    mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
    uniform_int_distribution<> distrib(borne_m, borne_p);

    return int(distrib(gen));
}


int inserer_nombre(const char* phrase)
{
    int nombre;

    while (true)
    {
        cout << phrase;
        cin >> nombre;

        if (cin.fail()) // no extraction took place
        {
            cin.clear(); // reset the state bits back to goodbit so we can use ignore()
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear out the bad input from the stream
            continue; // try again
        }

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
     *  Remarques : 
     *  @param borne_basse entier demandé à l'utilisateur définissant la borne basse de la recherche
     *  @param borne_haute entier demandé à l'utilisateur définissant la borne haute de la recherche
     *  @param choix_tentatives entier demandé à l'utilisateur définissant le nombre de tentatives qu'il souhaite avoir
     *  @param nb_de_tentatives entier qui sera incrémentéà chaques tentatives
     *  @param tentative entier qui prendra la valeur entrée par l'utilisateur à chaques boucle
     *  @param nb_a_deviner entier qui sera aléatoirement généré entre les bornes choisies
    **/

    // INITIALISATION
    int borne_basse;
    int borne_haute;
    int choix_tentatives;
    int nb_de_tentatives = 0;
    int tentative;
    int nb_a_deviner;

    // TRAITEMENT

    // Affichage du nom et des règles.
    cout << "----- DEVINE NOMBRE -----" << endl;
    cout << "Le joueur doit essayer de deviner le nombre généré aléatoirement entre les bornes saisies.\n" << endl;

    // Demande à l'utilisateur la saisie de la borne basse.
    borne_basse = inserer_nombre("Saisissez la borne basse : ");

    // Idem pour la borne haute.
    borne_haute = inserer_nombre("Saisissez la borne haute : ");

    // Si la borne basse est plus grande que la borne haute
    while (borne_basse == borne_haute || borne_basse > borne_haute) {

        cout << "Veuillez entrer des valeurs valides (bornes différentes ou borne basse < borne haute)" << endl;

        borne_basse = inserer_nombre("Saisissez la borne basse : ");

        borne_basse = inserer_nombre("Saisissez la borne basse : ");
    }

    nb_a_deviner = random_trouve_internet(borne_basse, borne_haute);


    tentative = borne_basse - 1;

    choix_tentatives = inserer_nombre("\nCombien de vies voulez vous avoir (minimum 1) ? : ");

    while (tentative != nb_a_deviner)
    {
        nb_de_tentatives++;
        cout << "\nSaisissez un nombre entre " << borne_basse << " et " << borne_haute << ". Tentative n° " << nb_de_tentatives << "/" << choix_tentatives << " : ";
        
        cin >> tentative;

        if (nb_de_tentatives == choix_tentatives)
        {
            cout << "\nPerdu :( le nombre était " << nb_a_deviner << "." << endl;
            return 0;
        } else if (tentative < nb_a_deviner)
        {
            cout << "Nombre trop petit !" << endl;
        } else
        {
            cout << "Nombre trop grand !" << endl;
        }

    }

    cout << "\n GAGNÉ ! il vous a fallu " << nb_de_tentatives << " tentatives." << endl;

    
    return 0;
}
