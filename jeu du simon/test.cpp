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

int main() {
    std::ostringstream phrase;
    std::string phraseString;
    const char* phraseChar;
    std::string phraseIntro = "** Jeu du Simon **\n[v -> vert, r -> rouge, b -> bleu, j -> jaune]";
    
    std::cout << phraseIntro << std::endl;


    return 0;
}
