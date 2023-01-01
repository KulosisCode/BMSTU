#ifndef BASEITER_H
#define BASEITER_H

#include <iostream>
#include <memory>
#include <time.h>

class BaseIter
{
protected:
    int index = 0;
    int num_elem = 0;
public:
    BaseIter();
    BaseIter(const BaseIter&);
    virtual ~BaseIter() = 0;
    virtual explicit operator bool() const = 0;
};

#endif // BASEITER_H
