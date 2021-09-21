
/**
  * @file main.cpp
  * @author T.Planche and M.Heriveau
  * @brief fichier du jeu du simon
  * @date 10 septembre 2021
  **/



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

int main()
{
    //INITITIALISATION DES VARIABLES
    bool perdu = false;
    int short nouvelleCouleurRandom;
    std::string suiteDesCouleurDuSimon;
    int numeroDeLaLettre;
    int nombreDeLettreDansLaSuiteDuSimon;
    char caractere;
    int short tour=0;
    int nombreDeCouleur=0;
    std::string suiteDesCouleurDuJoueur;
    char choixDeLaNouvelleCouleur;
    int short scoreOfficiel;
    int ajout=0;


    //Tant que le joueur n'a pas perdu
    while (perdu == false){
        
        //*********************************************************************************************************
        // Affichage interface Simon
        std::cout << "** Jeu du Simon **" << std::endl << std::endl;
        std::cout << "Simon : " ;

        //Le Simon choisie une couleurs entre Vert=1, rouge=2, bleu=3, jaune=4 a rajouter a chaque partie
        nouvelleCouleurRandom = random(1, 3); //Le rdm bug, il choisit bien entre 1 à 4
        switch (nouvelleCouleurRandom){
            case 1 : 
                suiteDesCouleurDuSimon = suiteDesCouleurDuSimon + "v";
                break; //Si rdm = 1 => vert
            case 2 :
                suiteDesCouleurDuSimon = suiteDesCouleurDuSimon + "r";
                break;
            case 3 :
                suiteDesCouleurDuSimon = suiteDesCouleurDuSimon + "b";
                break;
            case 4 : 
                suiteDesCouleurDuSimon = suiteDesCouleurDuSimon + "j";
                break;
            default :
                nouvelleCouleurRandom = random(1, 3);
                break;       //Si il fait de la merde on redemmande un nombre
        }

        //Affichage de toutes les couleurs du simon :
        //Decomposition de la succession des couleurs pour les affichers avec la couleur correspondante
        //Tant que le mot est pas entierement decomposer, on continue a le decomposer
        numeroDeLaLettre=0;
        tour++;
        while (numeroDeLaLettre <= tour)
            {
                caractere=suiteDesCouleurDuSimon[numeroDeLaLettre];
                switch (caractere) {
                case 'v' :
                    afficherTexteEnCouleur("v ", vert, false);
                    _sleep(1000);
                    break; //Si le caractere est vert on affiche v en vert
                case 'r' :
                    afficherTexteEnCouleur("r ", rouge, false);
                    _sleep(1000);
                    break; //ect...
                case 'b' :
                    afficherTexteEnCouleur("b ", bleu, false);
                    _sleep(1000);
                    break;
                case 'j' :
                    afficherTexteEnCouleur("j ", jaune, false);
                    _sleep(1000);
                    break;
                                }
                numeroDeLaLettre++;
            }
            
            //decompte avant que le joueur saisie la suite des couleurs
            std::cout << std::endl << "3... ";
            _sleep(1000);
            std::cout << "2... ";
            _sleep(1000);
            std::cout << "1... " ;
            OS::clear();

        
            //Fin de l'interface de jeu du Simon 
        //*********************************************************************************************************

        //Au tour du joueur
        
        
        //initialisation a chaque debut de partie de la saisie du joueur
        ajout=0;
        nombreDeCouleur=0;
        scoreOfficiel=0;

        //Tant que le joueur n'a pas fini la saisie de toute les couleurs
        while (nombreDeCouleur != tour)
        {
            
            //On refresh la page avec toutes les dernieres couleurs deja affiché si il y en a
            OS::clear();
            //interface du joueur
            std::cout << "** Jeu du Simon **" << std::endl;
            std::cout << "[v -> vert, r -> rouge, b -> bleu, j -> jaune]" << std::endl << std::endl;
            std::cout << "Joueur : ";
            
            //On affiche les couleurs deja instauré
            numeroDeLaLettre=0;
            caractere=0;
            while (numeroDeLaLettre != tour)
            {
                caractere=suiteDesCouleurDuJoueur[numeroDeLaLettre];
                switch (caractere) {
                case 'v' :
                    afficherTexteEnCouleur("v ", vert, false);
                    _sleep(1000);
                    break; //Si le caractere est vert on affiche v en vert
                case 'r' :
                    afficherTexteEnCouleur("r ", rouge, false);
                    _sleep(1000);
                    break; //ect...
                case 'b' :
                    afficherTexteEnCouleur("b ", bleu, false);
                    _sleep(1000);
                    break;
                case 'j' :
                    afficherTexteEnCouleur("j ", jaune, false);
                    _sleep(1000);
                    break;
                                }
                numeroDeLaLettre++;
                caractere=0;
            }
            
        
            //On demande une nouvelle saisie des couleurs

            cin >> choixDeLaNouvelleCouleur;

            //Verification de la saisie, si elle est bonne, on l'implemente dans la suiteDesCouleurDuJoueur
            //Sinon il a perdu
            numeroDeLaLettre=ajout;
            if (choixDeLaNouvelleCouleur==suiteDesCouleurDuSimon[numeroDeLaLettre])
            {
                scoreOfficiel++;
                nombreDeCouleur++;
                ajout++;
                switch (choixDeLaNouvelleCouleur){
                case 'v' : 
                suiteDesCouleurDuJoueur=suiteDesCouleurDuJoueur+'v';
                break;
                case 'r' :
                suiteDesCouleurDuJoueur=suiteDesCouleurDuJoueur+'r';
                break;
                case 'b' :
                suiteDesCouleurDuJoueur=suiteDesCouleurDuJoueur+'b';
                break;
                case 'j' : 
                suiteDesCouleurDuJoueur=suiteDesCouleurDuJoueur+'j';
                break;
            
                }
            

            }else { 
                //On prend la derniere lettre saisie pour l'afficher lors du resultat
                
                switch (choixDeLaNouvelleCouleur){
                case 'v' : 
                suiteDesCouleurDuJoueur=suiteDesCouleurDuJoueur+'v';
                break;
                case 'r' :
                suiteDesCouleurDuJoueur=suiteDesCouleurDuJoueur+'r';
                break;
                case 'b' :
                suiteDesCouleurDuJoueur=suiteDesCouleurDuJoueur+'b';
                break;
                case 'j' : 
                suiteDesCouleurDuJoueur=suiteDesCouleurDuJoueur+'j';
                break;
                default : perdu = true ; break ;
                }
                nombreDeCouleur=tour;
                perdu = true;
            }
            




            //fin de la boucle (tant que le joueur n'a pas saisie toute les couleurs
            
        }
        suiteDesCouleurDuJoueur="";
        OS::clear();
        
        //Fin de la boucle (tant que le joueur n'a pas perdu)
        
    }
//*********************************************************************************************************
    //En cas de mauvaise saisie: le joueur a perdu, on affcihe donc le score

OS::clear();
cout << "** Jeu du Simon **" << std::endl ;
cout << "Erreur de la saisie de la couleur " << (scoreOfficiel+1) << endl << endl;
cout << "Simon : " ;

//AFFICHAGE DE LA SAISIE DU SIMON
numeroDeLaLettre=0;

while (numeroDeLaLettre <= tour)
    {
caractere=suiteDesCouleurDuSimon[numeroDeLaLettre];
switch (caractere) {
    case 'v' :
        afficherTexteEnCouleur("v ", vert, false);
        _sleep(1000);
    break; //Si le caractere est vert on affiche v en vert
    case 'r' :
        afficherTexteEnCouleur("r ", rouge, false);
        _sleep(1000);
    break; //ect...
    case 'b' :
        afficherTexteEnCouleur("b ", bleu, false);
        _sleep(1000);
    break;
    case 'j' :
        afficherTexteEnCouleur("j ", jaune, false);
        _sleep(1000);
    break;
        }
        numeroDeLaLettre++;
    }
//*********************************************************************************************************
//AFFICHAGE DE LA SAISIE DU JOUEUR
    cout << endl << "Vous : " ;
    
    numeroDeLaLettre=0;
    caractere=0;
    while (numeroDeLaLettre != tour)
    {
    caractere=suiteDesCouleurDuJoueur[numeroDeLaLettre];
    switch (caractere) {
        case 'v' :
            afficherTexteEnCouleur("v ", vert, false);
            _sleep(1000);
        break; //Si le caractere est vert on affiche v en vert
        case 'r' :
            afficherTexteEnCouleur("r ", rouge, false);
            _sleep(1000);
        break; //ect...
        case 'b' :
            afficherTexteEnCouleur("b ", bleu, false);
            _sleep(1000);
        break;
        case 'j' :
            afficherTexteEnCouleur("j ", jaune, false);
            _sleep(1000);
        break;
                                }
                numeroDeLaLettre++;
            }
    cout << "\nVous avez un score de " << scoreOfficiel << ".";
        

    return 0;
}