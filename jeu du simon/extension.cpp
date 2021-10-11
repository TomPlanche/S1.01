
/**
  * @file main.cpp
  * @author T.Planche and M.Heriveau
  * @brief fichier du jeu du simon
  * @date 10 septembre 2021
  **/

//!-------------------------------Importation des bibliotheque-------------------------------
#include <iostream>
#include <cstdlib>
#include <random>

#ifdef __APPLE__
#include <unistd.h>
#include <stdlib.h>
#endif

#ifdef _WIN32
#include "game-tools.h"
#endif

//!-----------------------------Fonction OS pour WIN32 ou APPLE------------------------------
namespace OS
{
    //Clear
    void clear()
    {
#ifdef _WIN32
        system("cls");

#elif __APPLE__
        system("clear");

#endif
    }

    //Pause
    void sleep(unsigned short int seconde)
    {
#ifdef _WIN32
        _sleep(seconde * 1000); // cette fonction prends des micro-secondes

#elif __APPLE__
        _sleep(seconde * 1000000); // cette fonction prends des nano-secondes

#endif
    }
}

//!-----------------------Demarrage de la fonction main.cpp--------------------

int main()
{

    //VARIABLE
    bool statutDuJoueur;                           //Statut du joueur lors du deroulement du jeu (= perdu ou gagner)
    std::string suiteDesCouleurDuSimon;            //Variables constitué de toutes la suite des couleurs du simon
    std::string suiteDesCouleurDuJoueur;           //Variables constitué de toutes la suite des couleurs du joueur
    char caractere;                                //Caractere appeler lors des switch d'affichages
    char choixDeLaNouvelleCouleur;                 //Nouvelle couleur saisie par le joueur
    unsigned short int nouvelleCouleurRandom;      //Appelé dans la fonction random pour que le simon choisit une couleur au hasard
    unsigned short int nombreDeCouleur;            //Le nombre de couleur affiché lors de la partie. Une partie commence à 1 couleur
    unsigned short int score;                      //Le score du joueur qui augmente a chaque bonne reponse
    unsigned short int numeroDeLaCouleurAVerifier; //Le numero de lz couleur a verifier pour gagner ou pas
    unsigned short int joker;                      //Extension joker permetant de mettre une etoile(*) a la place de la couleur 

    //&------------------Initialisation--------------------------

    nombreDeCouleur = 1;
    statutDuJoueur = true;

    //&-----------------Deroulement du jeu-----------------------

    do
    {

        // Tour du Simon
        // Affichage interface Simon

        std::cout << "** Jeu du Simon **\n"
                  << std::endl;
        std::cout << "Simon : ";

        //Création d'une couleur et implémentation dans la liste des couleurs (Vert=1, rouge=2, bleu=3, jaune=4)

        nouvelleCouleurRandom = random(1, 3); //Le rdm bug, il choisit bien de 1 à 4

        switch (nouvelleCouleurRandom)
        {
        case 1:
            suiteDesCouleurDuSimon += 'v'; //On rajoute a la suite la nouvelle couleur : verte
            break;
        case 2:
            suiteDesCouleurDuSimon += 'r'; //                                            rouge
            break;
        case 3:
            suiteDesCouleurDuSimon += 'b'; //                                            bleu
            break;
        case 4:
            suiteDesCouleurDuSimon += 'j'; //                                            jaune
            break;
        }

        //Afficher la liste des couleurs du Simon

        for (int i = 0; i != nombreDeCouleur; i++)
        {

            caractere = suiteDesCouleurDuSimon[i];          //On prende
            switch (caractere)
            {
            case 'v':
                afficherTexteEnCouleur("v ", vert, false);  //Si le caractere est vert on affiche v en vert
                break;
            case 'r':
                afficherTexteEnCouleur("r ", rouge, false); //Si le caractere est rouge on affiche r en rouge
                break; 
            case 'b':
                afficherTexteEnCouleur("b ", bleu, false);  //Si le caractere est bleu on affiche b en bleu
                break;
            case 'j':
                afficherTexteEnCouleur("j ", jaune, false); //Si le caractere est jaune on affiche j en jaune
                break;
            }

            //Pause de 1s
            OS::sleep(1);

        }


        //*****************************************************************
        //Decompte et remise en page
        
        //Decompte (3... 2... 1...)
        std::cout << std::endl
                  << "3... ";
        OS::sleep(1);
        std::cout << "2... ";
        OS::sleep(1);
        std::cout << "1... ";
        //Efface le terminal
        OS::clear();

        //*****************************************************************
        //Tour du joueur
        
        //Initialisation / rénitialisation des variables

        joker = 0;                      
        score = 0;                      //On remet a 0 a chaque debut de partie
        suiteDesCouleurDuJoueur = "";   //On vide la suite de couleur du joueur
        numeroDeLaCouleurAVerifier = 0;

        //interface du joueur

        std::cout << "** Jeu du Simon **" << std::endl;
        std::cout << "[v -> vert, r -> rouge, b -> bleu, j -> jaune]\n" << std::endl;        
        std::cout << "Joueur : ";

        
        //Jeu

        //Le joueur joue jusqu'a temps que il est saisie toute les couleurs
        for (int k = 0; k != nombreDeCouleur; k++)
        {
            //Ensuite le joueur saisie une nouvelle couleur

            cin >> choixDeLaNouvelleCouleur;

            if (choixDeLaNouvelleCouleur == '*')
            {
                if (joker > 0)
                {
                    cout << "Joker deja utilise. Veuillez ressayez : ";
                    cin >> choixDeLaNouvelleCouleur;
                }
                else
                {
                    choixDeLaNouvelleCouleur = suiteDesCouleurDuSimon[numeroDeLaCouleurAVerifier];
                    joker++;
                }
            }

            //On la rajoute a la suiteDesCouleurDuJoueur
            switch (choixDeLaNouvelleCouleur)
            {
            case 'v':
                suiteDesCouleurDuJoueur += 'v';
                break;
            case 'r':
                suiteDesCouleurDuJoueur += 'r';
                break;
            case 'b':
                suiteDesCouleurDuJoueur += 'b';
                break;
            case 'j':
                suiteDesCouleurDuJoueur += 'j';
                break;
            }

            //Si cette nouvelle couleur correspond bien a la couleur du simon de meme rang, le jeu continue
            if (choixDeLaNouvelleCouleur == suiteDesCouleurDuSimon[numeroDeLaCouleurAVerifier])
            {

                //On refresh et on remet l'interface du joueur
                //interface du joueur
                OS::clear();
                std::cout << "** Jeu du Simon **" << std::endl;
                std::cout << "[v -> vert, r -> rouge, b -> bleu, j -> jaune]\n"
                          << std::endl;
                std::cout << "Joueur : ";

                //On affiche les caracteres precedent en couleur
                for (int r = 0; r != (score + 1); r++)
                {
                    caractere = suiteDesCouleurDuJoueur[r];

                    switch (caractere)
                    {
                    case 'v':
                        afficherTexteEnCouleur("v ", vert, false); //Si le caractere est vert on affiche v en vert
                        break;
                    case 'r':
                        afficherTexteEnCouleur("r ", rouge, false); //ect...
                        break;
                    case 'b':
                        afficherTexteEnCouleur("b ", bleu, false);
                        break;
                    case 'j':
                        afficherTexteEnCouleur("j ", jaune, false);
                        break;
                    }
                }
                numeroDeLaCouleurAVerifier++;
                score++; //Le score augmente
            }
            else //Sinon le joueur a perdu la manche
            {

                statutDuJoueur = false; //Le joueur perd
                break;
            }
        }

        //A chaque fin de partie : remise en page
        OS::clear();
        nombreDeCouleur++; //Il y a une couleur supplementaire
    } while (statutDuJoueur != false);

    //&-----------------Le joueur a fini la partie -----------------------

    //Si le joueur a perdu
    std::cout << "** Jeu du Simon **" << std::endl;
    std::cout << "Erreur de la saisie de la couleur " << (score + 1) << "\n\n";
    std::cout << "Simon : ";

    //AFFICHAGE DE LA SAISIE DU SIMON
    for (int i = 0; i != nombreDeCouleur; i++)
    {

        caractere = suiteDesCouleurDuSimon[i];
        switch (caractere)
        {
        case 'v':
            afficherTexteEnCouleur("v ", vert, false);
            OS::sleep(1);
            break; //Si le caractere est vert on affiche v en vert
        case 'r':
            afficherTexteEnCouleur("r ", rouge, false);
            OS::sleep(1);
            break; //ect...
        case 'b':
            afficherTexteEnCouleur("b ", bleu, false);
            OS::sleep(1);
            break;
        case 'j':
            afficherTexteEnCouleur("j ", jaune, false);
            OS::sleep(1);
            break;
        }
    }
    //*********************************************************************************************************
    //AFFICHAGE DE LA SAISIE DU JOUEUR
    std::cout << endl
              << "Vous : ";

    for (int r = 0; r != (score + 1); r++)
    {

        caractere = suiteDesCouleurDuJoueur[r];
        switch (caractere)
        {
        case 'v':
            afficherTexteEnCouleur("v ", vert, false);
            break; //Si le caractere est vert on affiche v en vert
        case 'r':
            afficherTexteEnCouleur("r ", rouge, false);
            break; //ect...
        case 'b':
            afficherTexteEnCouleur("b ", bleu, false);
            break;
        case 'j':
            afficherTexteEnCouleur("j ", jaune, false);
            break;
        default:
            break;
        }
    }

    std::cout << "\nVous avez un score de " << score << ".";

    return 0;
}
