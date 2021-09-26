// IMPORTS
#include <random>
#include <iostream>
#include <cstdlib>
#include <sstream>

#include "game-tools.h"

#ifdef __APPLE__
    #include <unistd.h>
    #include <stdlib.h>
#endif

#ifdef _WIN32
    //#include "game-tools.h"
#endif

// ESPACE DE NOM
using std::cout;
using std::cin;
using std::endl;
using std::vector;

// DEFINITIONS
#define RESET "\e[0m"
#define ROUGE "\e[0;31m"
#define VERT "\e[0;32m"
#define JAUNE "\e[0;33m"
#define BLEU "\e[0;34m"
#define VIOLET "\e[0;35m"
#define CYAN "\e[0;36m"
#define BLANC "\e[0;37m"

namespace OS
{
    void clear()
    {
        #ifdef _WIN32
            system("cls");
        #elif __APPLE__
            system("clear");
        #endif
    }

    void sleep(int secondes)
    {
        #ifdef _WIN32
            _sleep(secondes * 1000); // cette fonction prends des micro-secondes
        #elif __APPLE__
            usleep(secondes * 1000000); // cette fonction prends des nano-secondes
        #endif
    }
}


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

string getCodeCouleur (Couleur couleur)
{
    string codeCouleur;
    switch (couleur)
    {
    case bleu:
        codeCouleur = BLEU;
        break;

    case vert:
        codeCouleur = VERT;
        break;

    case cyan:
        codeCouleur = CYAN;
        break;

    case rouge:
        codeCouleur = ROUGE;
        break;

    case violet:
        codeCouleur = VIOLET;
        break;

    case jaune:
        codeCouleur = JAUNE;
        break;

    case blanc:
        codeCouleur = BLANC;
        break;

    default:
        codeCouleur = RESET;
        break;
    }

    return codeCouleur;
}

class listeCouleurs {
    public:
        vector<char> liste;

        void ajouterCouleur() {
            int i = randomTrouveInternet(1, 4);
            switch(i) {
                case 1:
                    liste.push_back('j');
                    break;
                case 2:
                    liste.push_back('r');
                    break;
                case 3:
                    liste.push_back('v');
                    break;
                case 4:
                    liste.push_back('b');
                    break;
                default:
                    break;
            }
        }
};




void afficherTexteEnCouleur(string chaine, Couleur couleur, bool retourALaLigne)
{
    string codeCouleur = getCodeCouleur(couleur);
    cout << codeCouleur << chaine << RESET << flush;
    if (retourALaLigne)
    {
        cout << endl;
    }
}

void afficherTexteEnCouleur(char caractere, Couleur couleur, bool retourALaLigne)
{
    string codeCouleur = getCodeCouleur(couleur);
    cout << codeCouleur << caractere << RESET << flush;
    if (retourALaLigne)
    {
        cout << endl;
    }
}


int main() {
    bool gagne;
    const char* INTRO_JEU = "** Jeu du Simon **\n";
    const char* REGLES = "[v -> vert, r -> rouge, b -> bleu, j -> jaune]";
    char couleursGeneres;
    unsigned short int nouvelleCouleurRandom;
    listeCouleurs listeCouleurs;
    unsigned short int numeroManche = 0;

    int cpt = 0;


    while (cpt!=5) {
        OS::clear();
        cout << INTRO_JEU;
        listeCouleurs.ajouterCouleur();


        for (int i = 0 ; i < listeCouleurs.liste.size() ; i++) {
            afficherTexteCouleur(listeCouleurs.liste[i], listeCouleurs.liste[i], false);
            OS::sleep(1);

        }

        cpt++;
    }
    
    return 0;
}
