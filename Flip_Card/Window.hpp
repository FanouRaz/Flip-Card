#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <QMainWindow>


class Window : public QMainWindow{
Q_OBJECT
public:
    Window();
public slots:
    //fonctions associées au clic des boutons quitter et aide
    void quitter();
    void aide();


};
#endif // WINDOW_HPP
