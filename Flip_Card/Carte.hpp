#ifndef CARTE_HPP
#define CARTE_HPP
#include "LabelClickable.hpp"
#include <QPixmap>
class Carte : public LabelClickable{
private:
       Q_OBJECT
    //Un booléen pour savoir si notre carte est face recto ou verso
        bool recto;
        //image au recto
        QPixmap front;
        //image au verso, qui est une constante dans notre cas
        QPixmap back;
        int id;
        int numero;
    public:
    //les méthodes de notre classe
        Carte(int num,int identifiant);
        bool isRecto() const;
        //retourne la carte
        void flip();
        //Définir l'image de la carte quand elle est au recto
        void setPicRecto();
        int getNumero() const;
        void setNumero(int num);
        int getId() const;
        void setId(int identifiant);
        public slots:
            void retourner();
};

#endif // CARTE_HPP
