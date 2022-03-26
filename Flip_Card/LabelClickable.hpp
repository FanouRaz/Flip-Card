#ifndef LABELCLICKABLE_HPP
#define LABELCLICKABLE_HPP
//Création d'un Label émettant le signal clicked() lorsqu'il est cliquer
#include <QLabel>
#include <QWidget>
#include <Qt>

class LabelClickable : public QLabel {
    Q_OBJECT

public:
    explicit LabelClickable(QWidget* parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags());
    ~LabelClickable();

signals:
    void clicked();

protected:
    void mousePressEvent(QMouseEvent* event);

};

#endif // LABELCLICKABLE_HPP
