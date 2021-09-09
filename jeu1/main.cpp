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


int randomTrouveInternet(int borneBasse, int borneHaute)
{
    random_device rd;  // Will be used to obtain a seed for the random number engine
    mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
    uniform_int_distribution<> distrib(borneBasse, borneHaute);

    return int(distrib(gen));
}


int insererNombre(const char* phrase)
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
     *  @param borneBasse entier demandé à l'utilisateur définissant la borne basse de la recherche
     *  @param borneHaute entier demandé à l'utilisateur définissant la borne haute de la recherche
     *  @param choixTentatives entier demandé à l'utilisateur définissant le nombre de tentatives qu'il souhaite avoir
     *  @param nbDeTentatives entier qui sera incrémentéà chaques tentatives
     *  @param tentative entier qui prendra la valeur entrée par l'utilisateur à chaques boucle
     *  @param nb_a_deviner entier qui sera aléatoirement généré entre les bornes choisies
    **/

    // INITIALISATION
    int borneBasse;
    int borneHaute;
    int choixTentatives;
    int nbDeTentatives = 0;
    int tentative;
    int nb_a_deviner;
    ostringstream phrase;
    string phraseString;
    const char* phraseChar;

    // TRAITEMENT

    // Affichage du nom et des règles.
    cout << "----- DEVINE NOMBRE -----" << endl;
    cout << "Le joueur doit essayer de deviner le nombre généré aléatoirement entre les bornes saisies.\n" << endl;

    // Demande à l'utilisateur la saisie de la borne basse.
    borneBasse = insererNombre("Saisissez la borne basse : ");

    // Idem pour la borne haute.
    borneHaute = insererNombre("Saisissez la borne haute : ");

    // Si la borne basse est plus grande que la borne haute
    while (borneBasse == borneHaute || borneBasse > borneHaute) {

        cout << "Veuillez entrer des valeurs valides (bornes différentes ou borne basse < borne haute)" << endl;

        borneBasse = insererNombre("Saisissez la borne basse : ");

        borneBasse = insererNombre("Saisissez la borne basse : ");
    }

    nb_a_deviner = randomTrouveInternet(borneBasse, borneHaute);


    tentative = borneBasse - 1;

    choixTentatives = insererNombre("\nCombien de vies voulez vous avoir (minimum 1) ? : ");

    // Ici, je convertis la phrase avec les variables des bornes en char, afin de le passer en argument dans ma fonction "insererNombre".
    phrase << "\nSaisissez un nombre entre " << borneBasse << " et " << borneHaute << ". Tentative n° " << nbDeTentatives << "/" << choixTentatives << " : ";
    phraseString = phrase.str();
    phraseChar = phraseString.c_str();




    while (tentative != nb_a_deviner)
    {
        nbDeTentatives++;

        tentative = insererNombre(phraseChar);

        if (nbDeTentatives == choixTentatives)
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

    cout << "\n GAGNÉ ! il vous a fallu " << nbDeTentatives << " tentatives." << endl;

    
    return 0;
}
