#include"Carte.hpp"
Carte::Carte(int identifiant){
    back=QPixmap("images/verso.jpg");
    id=identifiant;
    front=QPixmap("images/photo"+QString::number(id)+".jpeg");
    setPixmap(back);
    recto=false;


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
int Carte::getId() const{
    return id;
}
void Carte::setId(int identifiant){
    id=identifiant;
}
