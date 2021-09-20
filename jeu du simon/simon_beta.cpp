
/**
  * @file main.cpp
  * @author T.Planche and M.Heriveau
  * @brief fichier du jeu du simon
  * @date 10 septembre 2021
  **/


#include <random>

#include "game-tools.h"
#include <iostream>
#ifdef __APPLE__
#include <unistd.h>
#endif

#ifdef _WIN32
#include <cstdlib>
#endif

namespace OS
{
    void clear() {
        #ifdef _WIN32
            system("cls");
        #elif __APPLE__
            system("clear");
        #endif
    }
}



int main(void) {
    /*
        Programme : main
        But :  Lance le jeu
        Date de dernière modification : 10 septembre 2021
        Auteur : T. Planche
        Remarques : pas commencé
    */


   //INITIALISATION
    char choixUtilisateur;
    std::string saisieDeLutilisateur;
    int tentative = 1;
    std::string saisieDuSimon;
    int score = 1;
    int rdm;
    char caractere;
    int boucle=0;
    int perdu=0;
    int scoreOfficiel=0;
    
  
//Temps qu'on a pas perdu :
    while(tentative == 1)
    {

    // Affichage interface Simon
        std::cout << "** Jeu du Simon **" << std::endl << std::endl;
        std::cout << "Simon : " ; 

     //Le simon choisie une couleurs entre Vert=1, rouge=2, bleu=3, jaune=4 a rajouter a chaque partie
        rdm=random(1, 3); //Le rdm bug, il choisit bien entre 1 à 4
        switch (rdm){
            case 1 : 
            saisieDuSimon=saisieDuSimon+"v"; break; //Si rdm = 1 => vert
            case 2 :
            saisieDuSimon=saisieDuSimon+"r"; break;
            case 3 :
            saisieDuSimon=saisieDuSimon+"b"; break;
            case 4 : 
            saisieDuSimon=saisieDuSimon+"j"; break;
            default : rdm=random(1, 4); break;       //Si il fait de la merde on redemande un nombre
        }


        //Le simon montre la succession de couleur 
        
        //decomposition de la succession des couleurs pour les affichers avec la couleur correspondante
        //Tant que le mot est pas entierement decomposer, on continue a le decomposer
        while(boucle<(score+1))
        {
             
        caractere=saisieDuSimon[boucle]; // On prend le caractere de la n'eme(boucle) lettre de la succession de couleur
        switch (caractere){
            case 'v' : afficherTexteEnCouleur("v ", vert, false); _sleep(1000);  break; //Si le caractere est vert on affiche v en vert
            case 'r' : afficherTexteEnCouleur("r ", rouge, false); _sleep(1000); break; //ect...
            case 'b' : afficherTexteEnCouleur("b ", bleu, false); _sleep(1000); break;
            case 'j' : afficherTexteEnCouleur("j ", jaune, false); _sleep(1000); break;
            }
            boucle++;//On va au n+1'eme caractere (boucle+1)
            
        }
        // Augmentation du score / rinitialisation des paramettres
        
        boucle=0;

        //decompte avant que le joueur saisie la suite des couleurs
        std::cout << std::endl << "3... ";
        _sleep(1000);
        std::cout << "2... ";
        _sleep(1000);
        std::cout << "1... " << std::endl;
        OS::clear();


        // Au tour du joueur 
        
        //interface du joueur
        
        std::cout << "** Jeu du Simon **" << std::endl;
        std::cout << "[v -> vert, r -> rouge, b -> bleu, j -> jaune]" << std::endl << std::endl;
        std::cout << "Joueur : ";

        //Tant que la boucle n'est pas fini
        while (boucle<score){
            

            //Saisie des couleurs 

            cin >> choixUtilisateur;


            //Si la saisie correpond, on continue
        
            if (choixUtilisateur==saisieDuSimon[boucle])
             {
                scoreOfficiel++;
                boucle++; 
                switch (choixUtilisateur){
                case 'v' : 
                saisieDeLutilisateur=saisieDeLutilisateur+'v';
                case 'r' :
                saisieDeLutilisateur=saisieDeLutilisateur+'r';
                case 'b' :
                saisieDeLutilisateur=saisieDeLutilisateur+'b';
                case 'j' : 
                saisieDeLutilisateur=saisieDeLutilisateur+'j';
                 }
             }

             //sinon fini la boucle, on dit que il a perdu, et on recupere la derniere donné
            else {boucle=score+1; perdu=1;

                switch (choixUtilisateur){
                    case 'v' : 
                    saisieDeLutilisateur=saisieDeLutilisateur+'v'; break; //Si rdm = 1 => vert
                    case 'r' :
                    saisieDeLutilisateur=saisieDeLutilisateur+'r'; break;
                    case 'b' :
                    saisieDeLutilisateur=saisieDeLutilisateur+'b'; break;
                    case 'j' : 
                    saisieDeLutilisateur=saisieDeLutilisateur+'j'; break;
                        }
                }
                }
           //Peu importe le resultat, on refresh la page pour avoir la saisie en couleur :
            OS::clear();

            //interface du joueur
        
            std::cout << "** Jeu du Simon **" << std::endl;
            std::cout << "[v -> vert, r -> rouge, b -> bleu, j -> jaune]" << std::endl << std::endl;
            std::cout << "Joueur : ";
            
            
            //AFFICHAGE DE LA SAISIE DU JOUEUR
            boucle=0;
            while(boucle<score)
            {
             
            caractere=saisieDeLutilisateur[boucle]; // On prend le caractere de la n'eme(boucle) lettre de la succession de couleur
            switch (caractere){
            case 'v' : afficherTexteEnCouleur("v ", vert, false);  break; //Si le caractere est vert on affiche v en vert
            case 'r' : afficherTexteEnCouleur("r ", rouge, false); break; //ect...
            case 'b' : afficherTexteEnCouleur("b ", bleu, false); break;
            case 'j' : afficherTexteEnCouleur("j ", jaune, false); break;}
            boucle++;//On va au n+1'eme caractere (boucle+1)
            }
            caractere=0;
            
    
        //Affichage de la fin
        if (perdu==1)
        {
            _sleep(1000); 
            OS::clear();
            cout << "** Jeu du Simon **" << std::endl ;
            cout << "Erreur de la saisie de la couleur " << (scoreOfficiel+1) << endl << endl;
            cout << "Simon : " ;
            boucle = 0;
            //AFFICHAGE DE LA SAISIE DU SIMON
            while(boucle<(score+1))
            {
             
            caractere=saisieDuSimon[boucle]; // On prend le caractere de la n'eme(boucle) lettre de la succession de couleur
            switch (caractere){
            case 'v' : afficherTexteEnCouleur("v ", vert, false);  break; //Si le caractere est vert on affiche v en vert
            case 'r' : afficherTexteEnCouleur("r ", rouge, false); break; //ect...
            case 'b' : afficherTexteEnCouleur("b ", bleu, false); break;
            case 'j' : afficherTexteEnCouleur("j ", jaune, false); break;
            }
            caractere=0;
            boucle++;//On va au n+1'eme caractere (boucle+1)
            
            }
            boucle=0;
            //AFFICHAGE DE LA SAISIE DU JOUEUR
            cout << endl << "Vous : " ;
            while(boucle<score)
            {
             
            caractere=saisieDeLutilisateur[boucle]; // On prend le caractere de la n'eme(boucle) lettre de la succession de couleur
            switch (caractere){
            case 'v' : afficherTexteEnCouleur("v ", vert, false); _sleep(1000);  break; //Si le caractere est vert on affiche v en vert
            case 'r' : afficherTexteEnCouleur("r ", rouge, false); _sleep(1000); break; //ect...
            case 'b' : afficherTexteEnCouleur("b ", bleu, false); _sleep(1000); break;
            case 'j' : afficherTexteEnCouleur("j ", jaune, false); _sleep(1000); break;}
            boucle++;//On va au n+1'eme caractere (boucle+1)
            }
            caractere=0;
            cout << endl << "Vous avez fait " << scoreOfficiel << " de score.";
            return 0;
        }

        // Attente entre les 2 interfaces (Simon/joueur)
        _sleep(1000); 
        OS::clear();
        score++;
        saisieDeLutilisateur="";
        boucle=0;
        scoreOfficiel=0;
    

    }

}
