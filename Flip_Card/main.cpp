#include <QApplication>
#include "Grille.hpp"
int main(int argc, char *argv[])
{
    //Lancement du jeu
    QApplication a(argc, argv);
    Grille jeu;
    return a.exec();
}

