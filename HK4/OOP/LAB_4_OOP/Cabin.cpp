#include "Cabin.h"

#include <QDebug>

Cabin::Cabin(QObject *parent) : QObject(parent)
{
    _status = FREE;

    QObject::connect(this, SIGNAL(openDoor()), &_door, SLOT(beginOpening())); // mở cửa

    QObject::connect(&_moveTimer, SIGNAL(timeout()), this, SLOT(free())); // qua 1 tầng

    QObject::connect(&_door, SIGNAL(doorClosed()), this, SLOT(free())); // đóng cửa
}

void Cabin::stopCabin()
{
        _status = WAITING;

        _moveTimer.stop();
        emit openDoor(); //  open the door
 }

void Cabin::moveCabin()
{
    if (_status == FREE)
    {
        _status = MOVING;
        _moveTimer.start(MOVE_TIME);
    }
}

void Cabin::free()
{
    if (_status != FREE)
    {
        _status = FREE;
        emit cabinFinished(false);  // sau khi qua mỗi tầng thì gửi 1 lần tới file Lift
    }
}

