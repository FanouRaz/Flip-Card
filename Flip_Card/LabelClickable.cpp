#include "LabelClickable.hpp"

LabelClickable::LabelClickable(QWidget* parent, Qt::WindowFlags f)
    : QLabel(parent) {

}

LabelClickable::~LabelClickable() {}
//emettre un signal "clicked" lorsque l'on clique sur le QLabel
void LabelClickable::mousePressEvent(QMouseEvent* event) {
    emit clicked();
}
