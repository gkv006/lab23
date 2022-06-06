
#ifndef LABA23_SEQUENCE_H
#define LABA23_SEQUENCE_H



template <class T>
class Sequence
{
    virtual int getLength() = 0;

    virtual T getFirst() = 0;

    virtual T getLast() = 0;

    virtual T get(int index) = 0;

    virtual void append(T item) = 0;

    virtual void prepend(T item) = 0;

    virtual void insertAt(T item, int index) = 0;

    virtual void output() = 0;
};
#endif //LABA23_SEQUENCE_H