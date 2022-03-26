#include"Carte.hpp"
Carte::Carte(int num,int identifiant){
    back=QPixmap("images/verso.jpg");
    numero=num;
    id=identifiant;
    front=QPixmap("images/photo"+QString::number(id)+".jpeg");
    setPixmap(back);
    recto=false;
    QObject::connect(this, SIGNAL(clicked()),this, SLOT(retourner()));
}

//retourne true si la carte est en face recto, false sinon
bool Carte::isRecto() const{
    return recto;
}
//retourne la carte
void Carte::flip(){
    recto = !recto;
    if(recto){
        setPixmap(front);
    }
    else{
        setPixmap(back);
    }

}
/*void Carte::setPicRecto(){
     front=QPixmap("images/photo"+QString::number(numero)+".jpeg");
}*/
int Carte::getNumero() const{
    return numero;
}
void Carte::setNumero(int num){
    numero=num;
}
int Carte::getId() const{
    return numero;
}
void Carte::setId(int identifiant){
    id=identifiant;
}
void Carte::retourner(){
    //Si la carte cliquée est en verso elle sera retournée,
    if(!recto){
       recto=true;
       setPixmap(front);
    }

}
