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

    std::cout << phraseString;
}


int main() {
    afficherTexteCouleur("test", 'r', false);
    afficherTexteCouleur("test", 'b', true);
    afficherTexteCouleur("test", 'v', false);
    return 0;
}
