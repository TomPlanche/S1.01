#include <random>
#include <iostream>
#include <cstdlib>
#include <sstream>

#ifdef __APPLE__
    #include <unistd.h>
    #include <stdlib.h>
#endif

#ifdef _WIN32
    //#include "game-tools.h"
#endif

using std::cout;
using std::cin;
using std::endl;
using std::vector;

namespace OS
{
    void clear()
    {
        #ifdef _WIN32
            system("cls");
        #elif __APPLE__
            system("clear");
        #endif

        cout << "** Jeu du Simon **" << endl;
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

void afficherTexteCouleur(const char* phraseEntree, char couleur, bool retourALaLigne) {
    std::ostringstream phrase;
    std::string phraseString;

    switch (couleur) {
        case 'r':
            phrase << "\x1B[31m" << phraseEntree << "\033[0m";
            break;
        
        case 'v':
            phrase << "\x1B[32m" << phraseEntree << "\033[0m";
            break;
        
        case 'j':
            phrase << "\x1B[33m" << phraseEntree << "\033[0m";
            break;
        
        case 'b':
            phrase << "\x1B[34m" << phraseEntree << "\033[0m";
            break;
        
        default:
            phrase << phraseEntree;
    }

    phraseString = phrase.str();

    if (retourALaLigne) {
        phraseString += "\n";
    }

    cout << phraseString;
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


vector<char> couleurRandom(vector<char> listeCouleurs) {
    char listeToutesCouleurs[4] = {'v', 'r', 'b', 'j'};
    int numeroAleatoire = randomTrouveInternet(1, 4);
    listeCouleurs.push_back(listeCouleurs[numeroAleatoire]);
    
    return listeCouleurs;
}


int main() {
    bool gagne;
    const char* regles = "[v -> vert, r -> rouge, b -> bleu, j -> jaune]";
    char couleursGeneres;
    int nouvelleCouleurRandom;
    vector <char> listeCouleursDefinies;

    // OS::clear();

    // while (! gagne)
    // {
    //     OS::clear();
    //     nouvelleCouleurRandom = randomTrouveInternet(1, 3);
    // }

    listeCouleursDefinies = couleurRandom(listeCouleursDefinies);


    
    return 0;
}
