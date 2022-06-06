
#ifndef LABA23_DYNAMICARRAY_H
#define LABA23_DYNAMICARRAY_H

#include <iostream>
#include <string>

using namespace std;

template <class T>
class DynamicArray{

private:

    T *items;
    int size;

public:

//constructors

    DynamicArray(T *items, int count){
        this->items = items;
        this->size = count;
    }

    DynamicArray(){
        this->items = NULL;
        this->size = 0;
    }

    DynamicArray(int size){
        this->items = new T[size];
        this->size = size;
    }

    DynamicArray(const DynamicArray<T> & dynamicArray){
        this->items = dynamicArray.items;
        this->size = dynamicArray.size;
    }

    ~DynamicArray(){
        delete [] this->items;
        cout<<"DynARR destructor"<<endl;
    }

//other
    void print_massvi() {
        for (int i = 0; i < size; i++)
            cout << items[i] << " ";
        cout << "\n";
    }

    int GetSize(){
        return this->size;
    }


    T Get(int index){
        if (index >= 0 && index < this->size)
            return this->items[index];
        else
            throw "IndexOutOfRange";
    }

    void Set(int index, T value){
        this->items[index] = value;
    }

    void Resize(int newSize){
        T *temp = new T[newSize];
        temp[0] = this->items[0];
        for(int i = 0; i < min(this->size, newSize); i++){
            temp[i] = this->items[i];
        }
        delete [] this->items;
        this->items = temp;
        this->size = newSize;
    }



};



#endif //LABA23_DYNAMICARRAY_H