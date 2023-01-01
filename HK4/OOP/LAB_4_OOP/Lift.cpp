#include "Lift.h"

Lift::Lift(QObject *parent) : QObject(parent)
{
    _controller.setStyleSheet("background-color:lightblue");

    QObject::connect(&_cabin, SIGNAL(cabinFinished(bool)), &_controller, SLOT(newTarget(bool))); // signal từ cabin khi đc free
    QObject::connect(&_controller, SIGNAL(moveCabinSignal()), &_cabin, SLOT(moveCabin())); // từ controller
    QObject::connect(&_controller, SIGNAL(stopCabinSignal()), &_cabin, SLOT(stopCabin())); // từ controller
}

QWidget *Lift::widget()
{
    return &_controller;
}
