#ifndef BASEVECTOR_H
#define BASEVECTOR_H

//#include <time.h>

class BaseVector {
protected:
    int num_elem = 0;

public:
    BaseVector();
    BaseVector(const BaseVector&);
    virtual ~BaseVector() = 0;

    virtual bool is_empty() const;
    virtual int get_size() const;
};

#endif // BASEVECTOR_H
