#include"Grille.hpp"

    Grille::Grille(){
        //Initialisation et allocation dynamique des pointeurs
        idLastCard=-1;
        finDeLaPartie=false;
        nombreEssai=0;
        centralWidget = new QWidget(this);
        srand(time(nullptr));
        layout = new QGridLayout(centralWidget);
        for(int i(0);i<2;i++){
            for(int j(0);j<6;j++){
              listeCarte[i][j] =new Carte(i,j);
              //Evenement

            }

        }
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
            //permutation aléatoire
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
    void Grille::flipCard(int i,int j){
        listeCarte[i][j]->flip();
        }
    void Grille::onClic(){
        nombreEssai++;

    }

