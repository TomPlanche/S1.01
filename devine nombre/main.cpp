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

    random_device rd; 
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(borneBasse, borneHaute);

    if ((int(distrib(gen))) == 0) {
        return randomTrouveInternet(borneBasse, borneHaute);
    }
    return int(distrib(gen));
}


int insererNombre(const char* phrase)
{
    /**
     *  Programme : insererNombre
     *  But :  Demandez, avec une phrase spéciale, à l'utilisateur de saisir un nombre
     *  Date de dernière modification : 10 septembre 2021
     *  Auteur : T. Planche / M. Hériveau
     *  Remarques : L'utilisateur doit saisir un entier
     *  @param nombre entier demandé à l'utilisateur
     *  @param phrase phrase à afficher lors de la saisie du nombre
    **/
    int nombre;

    while (true) // Tant que l'input n'est pas bon
    {
        cout << phrase;
        cin >> nombre;

        if (cin.fail()) // si aucune extraction n'a eu lieu / erreur saisie
        {
            cin.clear(); // réinitialise les bits d'état à goodbit pour pouvoir utiliser ignore()
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // efface les mauvaises entrées 
            continue;
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
     *  Remarques : Le programme commence le jeu, le nombre 0 est exclu.
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
    int tentative = 0;
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

    // Si la borne basse est plus grande que la borne haute ou que les deux bornes ont la même valeur
    while (borneBasse == borneHaute || borneBasse > borneHaute)
    {
        cout << "Veuillez entrer des valeurs valides (bornes différentes ou borne basse < borne haute)" << endl;

        borneBasse = insererNombre("Saisissez la borne basse : ");
        borneHaute = insererNombre("Saisissez la borne haute : ");
    }

    // Génère un nombre aléatoire entre les deux bornes choisies
    nb_a_deviner = randomTrouveInternet(borneBasse, borneHaute);

    // Demande à l'utilisateur le nombre de tentatives qu'il souhaite avoir
    choixTentatives = insererNombre("\nCombien de vies voulez vous avoir (minimum 1) ? : ");

    // Boucle qui tourne tant que la tentative de l'utilisateur n'est pas la bonne
    while (tentative != nb_a_deviner)
    {   
        // Incrémente le nombre de tentatives à chaques passages de la boucle
        nbDeTentatives++;

        // Ici, je convertis la phrase avec les variables des bornes en char, afin de le passer en argument dans ma fonction "insererNombre".
        ostringstream phrase; // Réinitialisation de la phrase pour chaques boucles
        phrase << "\nSaisissez un nombre entre " << borneBasse << " et " << borneHaute << ". Tentative n° " << nbDeTentatives << "/" << choixTentatives << " : ";
        phraseString = phrase.str();
        phraseChar = phraseString.c_str();

        // Demande à l'utilisateur de saisir sa tentative
        tentative = insererNombre(phraseChar);

        // Boucle qui vérifie certaines conditions
        if (nbDeTentatives == choixTentatives) // Si l'utilisateur est a court de tentatives
        {
            cout << "\nPerdu :( le nombre était " << nb_a_deviner << "." << endl;
            return 0;
        } else if (tentative < nb_a_deviner) // Si la tentative est trop petite
        {
            cout << "Nombre trop petit !" << endl;
        } else // Si la tentative est trop grande
        {
            cout << "Nombre trop grand !" << endl;
        }

    }
    // Si on sort de cette boucle c'est que l'utilisateur à trouvé le bon nombre, on le félicite alors
    cout << "\n GAGNÉ ! il vous a fallu " << nbDeTentatives << " tentatives." << endl;

    return 0;
}
