/**
 * @file game-tools.cpp
 * @author Patrick Etcheverry
 * @brief Corps du module game-tools
 * @date 2021-09-16
 */
#include "game-tools.h"

#include <chrono>  // pour la fonction now() utilisée dans la fonction random()
#include <random>  // pour la fonction random
#include <unistd.h> // pour la fonction usleep

#define RESET "\e[0m"
#define ROUGE "\e[0;31m"
#define VERT "\e[0;32m"
#define JAUNE "\e[0;33m"
#define BLEU "\e[0;34m"
#define VIOLET "\e[0;35m"
#define CYAN "\e[0;36m"
#define BLANC "\e[0;37m"

int random(int min, int max)
{
    std::default_random_engine generateur;
    std::uniform_int_distribution<int> distributionNombres;
    unsigned int tempsActuel = static_cast<unsigned int>(chrono::steady_clock::now().time_since_epoch().count());
    generateur.seed(tempsActuel);

    return ((distributionNombres(generateur) % (max + 1)) + min);
}

void pause(unsigned int dureeEnSecondes)
{
    if (dureeEnSecondes == 0)
    {
        std::cin.ignore();
    }
    else
    {
        const unsigned int MICRO_SECONDE = 1000000;
        usleep(dureeEnSecondes * MICRO_SECONDE);
    }
}

void effacer (void)
{
    cout << "\033[2J\033[1;1H";
}

// Retourne le code couleur de la couleur passé en paramètre
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

void afficherNombreEnCouleur(double nombre, Couleur couleur, bool retourALaLigne)
{
    string codeCouleur = getCodeCouleur(couleur);

    cout << codeCouleur << nombre << RESET << flush;
    if (retourALaLigne)
    {
        cout << endl;
    }
}


int main(void)
{
    // Afficher des textes en couleur
    cout << "** Du texte en couleur **" << endl;

    /* Affiche le mot "Tous" en bleu SANS retour à la ligne
       (car utilisation de la valeur false en dernier paramètre) */
    afficherTexteEnCouleur("Tous ", bleu, false);
    pause(1);
    afficherTexteEnCouleur("les ", vert, false);
    pause(1);
    afficherTexteEnCouleur("programmeurs ", cyan, false);
    pause(1);
    afficherTexteEnCouleur("sont ", rouge, false);
    pause(1);
    afficherTexteEnCouleur("des ", violet, false);

    /* Affiche le mot "optimistes" en jaune AVEC retour à la ligne
       (car utilisation de la valeur true en dernier paramètre) */
    afficherTexteEnCouleur("optimistes", jaune, true);
    return 0;
}