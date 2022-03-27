#ifndef GRILLE_HPP
#define GRILLE_HPP
#include"Carte.hpp"
#include"Window.hpp"
#include <QGridLayout>
#include <QWidget>
/*
    Nous avons ici la définition de la grille de jeu. Nous définirons ici le fonctionnement de notre jeu:
    Nous stockerons les 6 differentes cartes présent dans le jeu dans un tableau listeCarte de Carte
    Nous aurons également le gridLayout layout qui permettra de placer les 12 cartes réparties en 2 lignes et 6 colonnes
*/
class Grille : public Window{
    Q_OBJECT
    private:
        Carte* listeCarte[2][6];
        QGridLayout* layout;
        QWidget* centralWidget;
        //Nombre d'essai :
        int nombreEssai;
        bool finDeLaPartie;
        //la derniere carte selectionnée:
        Carte* lastSelectedCard;
        //La carte actuellemenent selectionnée:
        Carte* selectedCard;
        //Un booléen qui comparera si lastSelectedCard et selectedCard sont pareil
        bool pair;
    public:
        Grille();
        //melange la grille;
        void melangerCarte();
        //place les cartes dans la grille
        void distribuerCarte();
        //destructeur, il detruira les éléments du tableau listeCarte alloués dynamiquement au cours du programme
        ~Grille();
        //check si la partie est finie ou non
        void isOver() ;
        //Si la partie est finie, cela fera apparaître une boîte de dialogue
        void endGame();
public slots:
        void onClic();
};

#endif //GRILLE_HPP
