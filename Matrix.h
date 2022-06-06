#ifndef LABA23_MATRIX_H
#define LABA23_MATRIX_H


using namespace std;

#include <vector>

template <class T>
class Matrix{
public:

    Matrix();

    Matrix(int r, int c);

    Matrix(int r, int c, std::vector<T> &d);


    T getElement(int r, int c) const;

    std::vector<T> getRow(int r) const;

    std::vector<T> getColumn(int c) const;

    int getNumRows() const;

    int getNumColumns() const;


    void insert(int r, int c, T n);


    void print();
    void multiplacrion_on_skalyar(int skalyar);
    int matrix_norm();


    void operator= (const Matrix<T> &rhs);
    bool operator== (const Matrix<T> &rhs);
    bool operator!= (const Matrix<T> &rhs);
    Matrix<T> operator+ (const Matrix<T> &rhs);
    Matrix<T> operator- (const Matrix<T> &rhs);
    Matrix<T> operator* (const Matrix<T> &rhs);



private:

    std::vector<std::vector<T> > data;

    int rows;
    int cols;
    int elemCount;
    bool square;

};


#endif //LABA23_MATRIX_H