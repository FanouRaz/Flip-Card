#include"Grille.hpp"
#include<QDebug>
#include<QMessageBox>
    Grille::Grille(){
        //Initialisation
        lastSelectedCard = nullptr;
        nombreEssai=0;
        centralWidget = new QWidget();
        srand(time(nullptr));
        layout = new QGridLayout(centralWidget);
        for(int i(0);i<2;i++){
            for(int j(0);j<6;j++){
              listeCarte[i][j] =new Carte(j);
              //Evenement associé au clic des cartes
              connect(listeCarte[i][j],SIGNAL(clicked()),this,SLOT(onClic()));
            }

        }
        //mélange des cartes
        melangerCarte();
        //Placement des cartes dans le gridlayout
        for(int i(0);i<2;i++){
            for(int j(0);j<6;j++){
                   layout->addWidget(listeCarte[i][j],i,j);
            }
        }

        centralWidget->setLayout(layout);
        setCentralWidget(centralWidget);
        show();
    }

    void Grille::melangerCarte(){
        for(int i(0);i<2;i++){
            for(int j(0);j<6;j++){
            //génere deux nombre aléatoire compris entre 0 et 5
            int random1(rand()%2);
            int random2(rand()%6);
            //permutation aléatoire des éléments de la matrice des cartes
            Carte* temp;
            temp=listeCarte[i][j];
            listeCarte[i][j]=listeCarte[random1][random2];
            listeCarte[random1][random2]=temp;
        }
    }
 }
    Grille::~Grille(){
        for(int i=0;i<2;i++){
            for(int j(0);j<6;j++){
                delete listeCarte[i][j];
            }
        }
     }
    //Vérifie si la partie est achevée
    void Grille::isOver(){
        int i,j;
        for(i=0;i<2;i++){
            for(j=0;j<6;j++){
                if(!listeCarte[i][j]->isRecto()){
                    finDeLaPartie=false;
                    break;
                }
                if(j!=5 && !listeCarte[i][5]->isRecto()){
                    break;
                }
            }
        }
        if(i==1 && j==5 && !listeCarte[1][5]->isRecto()){
            finDeLaPartie=true;
            endGame();
        }
    }
    void Grille::flipCard(int i,int j){
        listeCarte[i][j]->flip();
        }
    //Evenement provoqué après chaque clic d'image^
    void Grille::onClic(){
        isOver();
        if(!((Carte*)sender())->isRecto()){
            ((Carte*)sender())->flip();
            nombreEssai++;
            //Si c'est le premier clic ou si les 2 derniers clics ont permis d'identifier une pair
            if(lastSelectedCard == nullptr){
                        lastSelectedCard = ((Carte*)sender());
                    }
            //Si la carte du dernier clic n'est pas semblable à celle du clic actuel
            else if(lastSelectedCard->getId() != ((Carte*)sender())->getId() && lastSelectedCard != nullptr){
                    lastSelectedCard->flip();
                    ((Carte*)sender())->flip();
                    lastSelectedCard=nullptr;
               }
            //Si la carte du dernier clic est semblable à celle du clic actuel
            else if(lastSelectedCard->getId() == ((Carte*)sender())->getId()){
                lastSelectedCard = nullptr;
            }
            qDebug() <<"Carte cliquer carte " <<((Carte*)sender())->getId() << "\n";
            //A chaque clic on vérifie si le jeu est achevé//
        }
        isOver();
    }
    void Grille::endGame(){
        //Affichera une boite de confirmation si l'on souhaite quitter ou non
        int reponse = QMessageBox::question(this, "Fin de la partie!",
        "Fin de la partie. Vous avez effectué "+QString::number(nombreEssai)+" essai. Voulez-vous rejouer?", QMessageBox ::Yes | QMessageBox::No);
        if (reponse == QMessageBox::Yes)
            {
                //Si le joueur souhaite rejouer, on retourne toute les cartes en face verso puis on mélange le tout
                for(int i(0);i<2;i++){
                    for(int j(0);j<6;j++){
                        this->listeCarte[i][j]->flip();
                    }
                }
                this->melangerCarte();
            }
    }


