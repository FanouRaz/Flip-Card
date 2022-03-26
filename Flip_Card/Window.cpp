#include "Window.hpp"
#include<QMenu>
#include<QMenuBar>
#include<QApplication>
#include<QMessageBox>
#include"Grille.hpp"
Window::Window()
{
    //Définition de la Barre de menu
    QMenu *menuJeu = menuBar()->addMenu("&Jeu");
    QAction *actionQuitter = new QAction("&Quitter", this);
    menuJeu->addAction(actionQuitter);
    QAction *actionAide = menuBar()->addAction("&Aide");
    setWindowTitle("Flip Card");
    setWindowIcon(QIcon("images/verso.jpg"));
    //Ajout de raccourci clavier associé aux éléments du menu
    actionQuitter->setShortcut(QKeySequence("Ctrl+Q"));
    actionAide->setShortcut(QKeySequence("Ctrl+H"));
    //Evenement associés au menu
    QObject::connect(actionQuitter, SIGNAL(triggered()), this, SLOT(quitter()));
    QObject::connect(actionAide,SIGNAL(triggered()),this,SLOT(aide()));
}
void Window::quitter(){
    //Affichera une boite de confirmation si l'on souhaite quitter ou non
    int reponse = QMessageBox::question(this, "Quitter la partie",
    "Voulez vous quitter la partie?", QMessageBox ::Yes | QMessageBox::No);
    if (reponse == QMessageBox::Yes)
        {
            this->close();
        }
    }
void Window::aide(){
    //Affiche une boite d'information contenant les règles du jeu
    QMessageBox::information(this, "Règle du jeu", "Les règles du jeu <strong>Flip card</strong> sont simples."
    "Nous voyons en premier lieu 12 cartes en verso disposées en 2 lignes et 6 colonnes. Lorsque le joueur clique"
    " sur une de ces cartes, elle est fliper et la face recto apparaît. Le joueur devra ensuite cliquer sur une autre"
    " carte en verso et elle se retourne à son tour: Si la face recto de cette seconde carte retournée est identique "
    " à celle de la première, les deux cartes resteront en face recto jusqu'à la fin du jeu, sinon les deux cartes seront flipper en face verso "
    "lorsque le joueur cliquera sur une autre carte pour la retourner. Le jeu s'arrête lorsque le joueur aura trouvé toute les 5 pairs de cartes.");
}




