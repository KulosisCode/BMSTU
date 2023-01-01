#ifndef ITERATOR_H
#define ITERATOR_H

#include "BaseIter.h"
#include "Error.h"
using namespace std;
#include<iterator>

template<class Type>
class Vector;

template<typename Type>
class Iterator : public BaseIter, public iterator<bidirectional_iterator_tag, Type>
{
public:
    Iterator(const Iterator<Type>& iter);
    Iterator(const Vector<Type>& vec);
    ~Iterator() = default;

    Type& operator*();
    const Type& operator*() const;
    Type* operator->();
    const Type* operator->() const;
    operator bool() const override;

    Iterator<Type>& operator=(const Iterator<Type>& iter);

    Iterator<Type>& operator+=(int n);
    Iterator<Type> operator+(int n) const;
    Iterator<Type>& operator++();
    Iterator<Type> operator++(int);

    Iterator<Type>& operator-=(int n);
    Iterator<Type> operator-(int n) const;
    Iterator<Type>& operator--();
    Iterator<Type> operator--(int);

//    bool operator<=(const Iterator<Type>& b) const;
//    bool operator<(const Iterator<Type>& b) const;
//    bool operator>=(const Iterator<Type>& b) const;
//    bool operator>(const Iterator<Type>& b) const;
    bool operator==(const Iterator<Type>& b) const;
    bool operator!=(const Iterator<Type>& b) const;
private:
    std::weak_ptr<Type[]> ptr;

protected:
    Type* get_cur_ptr() const;
    bool check(int line) const;
};

template<class Type>
Type* Iterator<Type>::get_cur_ptr() const
{
//    time_t t_time = time(NULL);
//    if (index < 0 || index >= num_elem || ptr.expired())
//        throw indexError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));

    std::shared_ptr<Type[]> copy_ptr = ptr.lock();
    return copy_ptr.get() + index;
}

template<class Type>
Iterator<Type>::Iterator(const Vector<Type>& vec)
{
    index = 0;
    num_elem = vec.num_elem;
    ptr = vec.data_list;
}

template<class Type>
Iterator<Type>::Iterator(const Iterator<Type>& iter)
{
    ptr = iter.ptr;
    index = iter.index;
    num_elem = iter.num_elem;
}

template<class Type>
Type& Iterator<Type>::operator*()
{
    check(__LINE__);

    std::shared_ptr<Type[]> copy_ptr = ptr.lock();
    return *get_cur_ptr();
}

template<class Type>
const Type& Iterator<Type>::operator*() const
{
    check(__LINE__);

    std::shared_ptr<Type> copy_ptr = ptr.lock();
    return *get_cur_ptr();
}

template<class Type>
Type* Iterator<Type>::operator->()
{
    check(__LINE__);

    return get_cur_ptr();
}

template<class Type>
const Type* Iterator<Type>::operator->() const
{
    check(__LINE__);

    return get_cur_ptr();
}

template<class Type>
Iterator<Type>& Iterator<Type>::operator=(const Iterator<Type>& iter)
{
    check(__LINE__);

    ptr = iter.ptr;
    return *this;
}

template<class Type>
Iterator<Type>& Iterator<Type>::operator+=(int n)
{
    check(__LINE__);
//    ptr += n;
    index += n;///////////////////////////////////////////
    return *this;
}

template<class Type>
Iterator<Type> Iterator<Type>::operator+(int n) const
{
    check(__LINE__);
    Iterator<Type> iter(*this);
    iter.index += n;

    return iter;
}

template<class Type>
Iterator<Type> Iterator<Type>::operator++(int)
{
    check(__LINE__);
    Iterator<Type> tmp(*this);
    ++(*this);

    return tmp;
}

template<class Type>
Iterator<Type>& Iterator<Type>::operator++()
{
    check(__LINE__);
    ++index;

    return *this;
}

//template<class Type>
//Iterator<Type>& Iterator<Type>::operator-=(int n)
//{
//    check(__LINE__);
//    index -= n;

//    return *this;
//}

//template<class Type>
//Iterator<Type> Iterator<Type>::operator-(int n) const
//{
//    check(__LINE__);

//    Iterator<Type> iter(*this);
//    iter -= n;

//    return iter;
//}

template<class Type>
Iterator<Type> Iterator<Type>::operator--(int)
{
    check(__LINE__);
    --(*this);

    return *this;
}

template<class Type>
Iterator<Type>& Iterator<Type>::operator--()
{
    check(__LINE__);
    --index;

    return *this;
}

//template<class Type>
//bool Iterator<Type>::operator<=(const Iterator<Type>& b) const
//{
//    check(__LINE__);

//    return ptr <= b.ptr;
//}

//template<class Type>
//bool Iterator<Type>::operator<(const Iterator<Type>& b) const
//{
//    check(__LINE__);

//    return ptr < b.ptr;
//}

//template<class Type>
//bool Iterator<Type>::operator>=(const Iterator<Type>& b) const
//{
//    check(__LINE__);

//    return ptr >= b.ptr;
//}

//template<class Type>
//bool Iterator<Type>::operator>(const Iterator<Type>& b) const
//{
//    check(__LINE__);

//    return ptr > b.ptr;
//}

template<class Type>
bool Iterator<Type>::operator==(const Iterator<Type>& b) const
{
    check(__LINE__);

    //return ptr == b.ptr;
    return get_cur_ptr() == b.get_cur_ptr();
}

template<class Type>
bool Iterator<Type>::operator!=(const Iterator<Type>& b) const
{
    check(__LINE__);

    //return ptr != b.ptr;
    return get_cur_ptr() != b.get_cur_ptr();
}

template<class Type>
Iterator<Type>::operator bool() const
{
    check(__LINE__);

    if (index >= num_elem || index < 0 || (num_elem == 0))
        return false;
    else
        return true;
}

template<class Type>
bool Iterator<Type>::check(int line) const
{
    if (!ptr.expired())
        return true;

    time_t t_time = time(NULL);
    throw deletedObj(__FILE__, typeid(*this).name(), line, ctime(&t_time));
    return false;
}

#endif // ITERATOR_H
