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
        //Un id pour identifier une carte
        int id;
    public:
    //les méthodes de notre classe
        Carte(int identifiant);
        bool isRecto() const;
        //retourne la carte
        void flip();
        int getId() const;
        void setId(int identifiant);

};

#endif // CARTE_HPP
