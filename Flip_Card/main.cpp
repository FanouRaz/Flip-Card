#include "Window.hpp"
#include <QApplication>
#include "Grille.hpp"
#include"Carte.hpp"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Grille jeu;
    return a.exec();
}

