#ifndef VECTOR_H
#define VECTOR_H

#include <stdarg.h>
#include <cmath>
#include <iostream>
#include <cstdlib>
#include <memory>
#include <stdexcept>

#include "BaseVector.h"
#include "ConstIterator.h"
#include "Iterator.h"

#define EPS 1e-5

template<typename Type>
class Vector: public BaseVector
{
    friend class Iterator<Type>;
    friend class ConstIterator<Type>;

public:

    //Constructors
    Vector();
    explicit Vector(int num_elements);

    Vector(int num_elements, Type* vec);
    Vector(int num_elements, Type vec, ...);
    Vector(std::initializer_list<Type> args);
    explicit Vector(const Vector<Type> &vec);
    Vector(Vector<Type>&& vec) noexcept;

    ~Vector();

    Vector<Type>& operator =(const Vector<Type>& vec);
    Vector<Type>& operator =(Vector<Type> &&vec);
    Vector<Type>& operator =(std::initializer_list<Type> args);

    // UnaryOperations
    bool is_zero() const;   // является ли вектор нулевым
    bool is_single() const;// является ли вектор единичным
    int size() const;
    Type len() const;   // длина вектора
    Vector<Type> operator -() const;
    Vector<Type> neg() const;

    //Iterators
    Iterator<Type> begin();
    ConstIterator<Type> cbegin();
    Iterator<Type> end();
    ConstIterator<Type> cend();


    Type& operator [](int index);
    const Type& operator [](int index) const;
    Type& get_elem_Vector(int index);
    const Type& get_elem_Vector(int index) const;
    bool set_elem_Vector(int index, const Type& vec);

    Vector<Type> get_single_vector() const;

    // умножение и деление вектора на число
    Vector<Type>& operator *=(const Type& mult);
    Vector<Type>& operator /=(const Type& div);
    // скалярное умножение
    Type operator *(const Vector<Type>& vec) const;
    Type scalar_mult(const Vector<Type>& vec) const;

    //направленное векторное умножение
    Vector<Type>& operator &=(const Vector<Type>& vec);
    Vector<Type> operator &(const Vector<Type>& vec) const;

    //сложение и вычитание векторов
    Vector<Type> operator +(const Vector<Type>&) const;
    Vector<Type> summ(const Vector<Type>&) const;
    Vector<Type>& operator +=(const Vector<Type>&);
    Vector<Type>& add(const Vector<Type>&);
    Vector<Type> operator -(const Vector<Type>&) const;
    Vector<Type> diff(const Vector<Type>&) const;
    Vector<Type>& operator -=(const Vector<Type>&);
    Vector<Type>& subtract(const Vector<Type>&);

    double angle_between_vectors(const Vector<Type>&) const;
    bool is_collinearity(const Vector<Type>&) const;
    bool is_orthogonality(const Vector<Type>&) const;

    bool operator ==(const Vector<Type>&) const;
    bool equals(const Vector <Type> &) const;
    bool operator !=(const Vector<Type>&) const;
    bool notequals(const Vector<Type>&) const;

protected:
    Type sum_all_elem();
    void sum_vectors(Vector<Type> &result, const Vector<Type>& vec1, const Vector<Type>& vec2) const;
    void difference_vectors(Vector<Type> &result, const Vector<Type>& vec1, const Vector<Type>& vec2) const;
    void mult_vectors(Vector<Type> &result, const Vector<Type>& vec1, const Vector<Type>& vec2) const;
    void new_dyn_mem(int);

private:
    std::shared_ptr<Type[]> data_list;
};

template<typename Type>
std::ostream& operator <<(std::ostream& os, const Vector<Type>& vec)
{
    Iterator<Type> iter(vec);

    if (!iter)
    {
        os << "Vector is empty.";
        return os;
    }
    os << '(' << *iter;
    for (iter++; iter; iter++)
        os << ", " << *iter ;
    os << ')';

    return os;
}

#endif // VECTOR_H
