/**\
  * @file main.cpp
  * @author Tom PLANCHE / Mathis HÉRIVEAU
  * @brief Jeu du Devine Nombre (pack 13) - S1.01 TD2 TP4 - IUT Bayonne
  * @date 08-09-2021
\**/

// Importation des bibliothèques nécessaires
#include <iostream>
#include <random>
#include <sstream>
#include <limits>

using std::cin;
using std::cout;
using std::endl;


int randomEtcheverry(int min, int max)
{
    /**
      * Programme :                      randomEtcheverry
      * But :                            Générer un nombre aléatoire entre min et max
      * @author :                        P.Etcheverry
      * @param                           min entier borne basse de l'intervalle dans laquelle générer un nombre aléatoire
      * @param                           max entier borne haute de l'intervalle dans laquelle générer un nombre aléatoire
      **/
    
    std::default_random_engine generateur;
    std::uniform_int_distribution<int> distributionNombres;
    unsigned int tempsActuel = static_cast<unsigned int>(std::chrono::steady_clock::now().time_since_epoch().count());
    generateur.seed(tempsActuel);

    return ((distributionNombres(generateur) % (max + 1)) + min);
}


int main(void)
{
    /**\
     *  Programme : main
     *  But :  L'utilisateur doit trouver un nombre à partir des aides énoncées
     *  Date de dernière modification : 28 septembre 2021
     *  Auteur : T. Planche / M. Hériveau
     *  Remarques : Le programme commence le jeu.
     *  @param borneBasse entier demandé à l'utilisateur définissant la borne basse de la recherche
     *  @param borneHaute entier demandé à l'utilisateur définissant la borne haute de la recherche
     *  @param nombreDeTentative entier demandé à l'utilisateur définissant le nombre de tentatives qu'il souhaite avoir
     *  @param tentativeActuelle entier qui sera incrémentéà chaques tentatives
     *  @param nombreSaisie entier qui prendra la valeur entrée par l'utilisateur à chaques boucle
     *  @param nbADeviner entier qui sera aléatoirement généré entre les bornes choisies
     *  @param statutJoueur booléen définissant si le joueur gagne ou non
    \**/


    // INITIALISATION VARIABLES
    int borneBasse;
    int borneHaute;
    int nombreDeTentative;
    int tentativeActuelle;
    int nombreSaisie;
    int nbADeviner;
    bool statutJoueur;

    tentativeActuelle = 0;



    // Affichage du nom et des règles.
    cout << "----- DEVINE NOMBRE -----" << std::endl;
    cout << "Le joueur doit essayer de deviner le nombre genere aleatoirement entre les bornes saisies.\n" << endl;


    // -------------------- SAISIES --------------------
    cout << "Veuillez entrer des valeurs valides (bornes differentes de 0 ou borne basse < borne haute)" << endl;
    
    // clavier >> SaisirIntervalleBasse >> borneBasse
    cout << "Saisissez la borne basse : ";
    cin >> borneBasse;

    // clavier >> SaisirIntervalleHaute >> borneHaute
    cout << "Saisissez la borne haute : ";
    cin >> borneHaute;

    // randomEcheverry >> nbADeviner
    nbADeviner = randomEtcheverry(borneBasse, borneHaute);

    // Demande à l'utilisateur le nombre de nombreSaisies qu'il souhaite avoir
    do {
        cout << "Combien de tentative voulez vous avoir (minimum 1) ? : ";
        cin >> nombreDeTentative;
    } while (nombreDeTentative < 0);

    
    // -------------------- TRAITEMENT - DÉBUT DU JEU --------------------

    // Boucle qui tourne tant que la nombreSaisie de l'utilisateur n'est pas la bonne
    while (nombreSaisie != nbADeviner) {
        // Incrémente le nombre de tentatives à chaques passages de la boucle
        tentativeActuelle++;

        cout << "\nSaisissez un nombre entre " << borneBasse << " et " << borneHaute << ". Tentative numero " << tentativeActuelle << "/" << nombreDeTentative << " : ";
        cin >> nombreSaisie;

        // Boucle qui vérifie certaines conditions
        if (tentativeActuelle == nombreDeTentative && nombreSaisie != nbADeviner) { // Si l'utilisateur est a court de tentatives
            statutJoueur=false;
            break;
        } else if (nombreSaisie < nbADeviner) { // Si la nombreSaisie est trop petite
            cout << "Nombre trop petit !" << endl;
        } else if (nombreSaisie > nbADeviner) { // Si la nombreSaisie est trop grande
            cout << "Nombre trop grand !" << endl;
        } else {
            statutJoueur=true;
            break;
        }
    }
    // Si on sort de cette boucle c'est que l'utilisateur à trouvé le bon nombre, on le félicite alors

    // -------------------- AFFICHAGE --------------------
    
    if (statutJoueur==false) {
        cout << "\nF I N I : toutes les tentatives ont ete consommees." << endl;  
    } else {
        cout << "\n GAGNÉ! il vous a fallu " << tentativeActuelle << " tentatives." << endl;
    }

    return 0;
}
