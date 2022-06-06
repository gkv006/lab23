#include <iostream>
#include <string>

#include "Tests.h"
#include "DynamicArray.h"
#include "LinkedList.h"

#include <assert.h>
#include "Matrix.h"
#include "Matrix.cpp"

using namespace std;



void TestDynamic()
{
    string *a = new string[5];
    a[0] = "00";
    a[1] = "11";
    a[2] = "22";
    a[3] = "33";
    a[4] = "44";
    DynamicArray<string> test(a, 5);

    test.Set(3,"999");

    assert(test.Get(0) == "00");
    assert(test.GetSize() == 5);
    assert(test.Get(3) == "999");




}

void test(){
    int massiv[3] = {1,2,3};
    DynamicArray<int> test1(massiv, 3);
    test1.Set(2,45);

    assert(test1.Get(0) == 1);
    assert(test1.GetSize() == 3);
    assert(test1.Get(2) == 45);
}

void TestLinkedList(){

    int string1[6] = {1,2,3,4,5,2030};
    LinkedList<int> test1(string1,6);

    assert(test1.GetLength() == 6);
    assert(test1.Get(1) == 2);
    assert(test1.GetLast()==2030);
    assert(test1.GetFirst() == 1);

    test1.InsertAt(999,2);
    test1.Append(5);
    test1.Prepend(80);

    assert(test1.Get(0)==80);
    assert(test1.Get(3) == 999);
    assert(test1.Get(6)==5);

}

void matrix(){
    vector<int> tmp {2,3,5,7,9,11,13,17,19};
    Matrix<int> a{};
    Matrix<int> b{3, 3, tmp};
    Matrix<int> c = a + b;


    //Check element-by-element sums
    for (int i = 1; i <= c.getNumRows(); i++) {
        vector<int> aRow = a.getRow(i);
        vector<int> bRow = b.getRow(i);
        vector<int> cRow = c.getRow(i);
        for (int j = 0; j < c.getNumColumns(); j++) {
            assert(cRow[j] == (aRow[j] + bRow[j]));
        }
    }
}

void testInsert() {

    Matrix<int> m{4,4};

    for (int i = 1; i <= m.getNumRows(); i++) {
        for (int j = 1; j <= m.getNumColumns(); j++) {
            m.insert(i,j,13);
        }
    }

}
