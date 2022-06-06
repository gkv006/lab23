#include "Matrix.h"


#include <iostream>
#include <iomanip>

const char lBoundingChar = '[';
const char rBoundingChar = ']';
const int formatWidth = 4; //text width for stdout formatting

template <class T>
Matrix<T>::Matrix() {
    rows = 3;
    cols = 3;
    elemCount = rows*cols;
    square = true;
    for (int i = 0; i < rows; i++){
        std::vector<T> v{};
        for (int j = 0; j < cols; j++){
            v.push_back((j+1) + (i*rows));
        }
        data.push_back(v); //add the row to the matrix
    }
}

template <class T>
Matrix<T>::Matrix(int r, int c, std::vector<T> &d)
        : rows{r}, cols{c}, square{r==c} {

    std::vector<T> tmp{};
    //typename qualifier needed for iterators
    typename std::vector<T>::iterator it = d.begin();
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            //check that d is still valid
            if (!(it == d.end())) {
                tmp.push_back(*it);
                it++;
            }
                //if d is not valid, simply insert a zero
            else {
                tmp.push_back(0);
            }
        }
        data.push_back(tmp);
        tmp.clear();
    }
}

template <class T>
Matrix<T>::Matrix(int r, int c)
        : rows{r}, cols{c}, elemCount{r*c}, square{r==c} {
    for (int i = 0; i < rows; i++) {
        std::vector<T> v{};
        for (int j = 0; j < cols; j++) {
            v.push_back(0);
        }
        data.push_back(v);
    }
}

template <class T>
T Matrix<T>::getElement(int r, int c) const {
    if ( (r < 1 || r > rows) || (c < 1 || c > cols) ) {
        perror("Error: row or column access out of bounds!\n");
        exit(1);
    }
    return data[r-1][c-1];
}

template <class T>
std::vector<T> Matrix<T>::getRow(int r) const {
    if (r < 1 || r > rows) {
        perror("Error: row access out of bounds!\n");
        exit(1);
    }
    return (data[r-1]);
}

template <class T>
std::vector<T> Matrix<T>::getColumn(int c) const {
    if (c < 1 || c > cols) {
        perror("Error: column access out of bounds!\n");
        exit(1);
    }
    std::vector<T> ret{};
    for (int i = 0; i < rows; i++) {
        ret.push_back(data[i][c-1]);
    }
    return ret;
}

template <class T>
int Matrix<T>::getNumRows() const {
    return rows;
}

template <class T>
int Matrix<T>::getNumColumns() const {
    return cols;
}



template <class T>
void Matrix<T>::insert(int r, int c, T n) {
    if ( (r < 1 || r > rows) || (c < 1 || c > cols) ) {
        perror("Error: invalid row or column given!\n");
        exit(1);
    }
    data[r-1][c-1] = n;
}



template <class T>
void Matrix<T>::print() {
    for (int i = 0; i < rows; i++){
        std::cout << lBoundingChar;
        for (int j = 0; j < cols; j++){
            std::cout << std::setw(formatWidth) << data[i][j] << " ";
        }
        std::cout << std::setw(formatWidth) << rBoundingChar << std::endl;
    }
}

template <class T>
void Matrix<T>::multiplacrion_on_skalyar(int skalyar) {
    for (int i = 0; i < rows; i++){

        for (int j = 0; j < cols; j++){
            data[i][j] *= skalyar;
        }

    }
}

template <class T>
int Matrix<T>::matrix_norm() {
    int summa = 0, norma = 0;
    for (int i = 0; i < rows; i++){
        if(summa >= norma){
            norma = summa;
        }
        summa = 0;

        for (int j = 0; j < cols; j++){
            summa += data[i][j] ;
        }


    }
    return norma;
}

template <class T>
void Matrix<T>::operator= (const Matrix<T> &rhs) {
    data = rhs.data;
    rows = rhs.rows;
    cols = rhs.cols;
    elemCount = rhs.elemCount;
    square = rhs.square;
}

template <class T>
bool Matrix<T>::operator== (const Matrix<T> &rhs) {
    return (data == rhs.data &&
            rows == rhs.rows &&
            cols == rhs.cols &&
            elemCount == rhs.elemCount &&
            square == rhs.square);
}

template <class T>
bool Matrix<T>::operator!= (const Matrix<T> &rhs) {
    return (!(*this == rhs));
}

template <class T>
Matrix<T> Matrix<T>::operator+ (const Matrix<T> &rhs) {
    if (! (rows == rhs.rows) && (cols == rhs.cols) ) {
        perror("Error: Matrix dimensions must be identical to perform addition!\n");
        exit(1);
    }

    Matrix<T> m{rhs.rows, rhs.cols};
    for (int i = 1; i <= rhs.rows; i++) {
        std::vector<T> r1 = this->getRow(i);
        std::vector<T> r2 = rhs.getRow(i);

        for (unsigned int j = 0; j < r1.size(); j++) {
            r1[j] += r2[j];
        }
        m.data[i-1] = r1;
    }
    return m;
}

template <class T>
Matrix<T> Matrix<T>::operator- (const Matrix<T> &rhs) {
    if (! (rows == rhs.rows) && (cols == rhs.cols) ) {
        perror("Error: Matrix dimensions must be identical to perform addition!\n");
        exit(1);
    }

    Matrix<T> m{rhs.rows, rhs.cols};
    for (int i = 1; i <= rhs.rows; i++) {
        std::vector<T> r1 = this->getRow(i);
        std::vector<T> r2 = rhs.getRow(i);

        for (unsigned int j = 0; j < r1.size(); j++) {
            r1[j] -= r2[j];
        }
        m.data[i-1] = r1;
    }
    return m;
}

template <class T>
Matrix<T> Matrix<T>::operator* (const Matrix<T> &rhs) {

    if (this->getNumColumns() != rhs.getNumRows() ) {
        perror("Error: columns must match rows for multiplication!\n");
        exit(1);
    }

    std::vector<T> res {};
    T tmp = 0;

    for (int i = 1; i <= this->getNumRows(); i++) {
        for (int j = 1; j <= rhs.getNumColumns(); j++) {
            std::vector<T> op1 = this->getRow(i);
            std::vector<T> op2 = rhs.getColumn(j);

            tmp = 0;
            for (int k = 0; k < this->getNumColumns(); k++) {
                tmp += (op1[k]*op2[k]);
            }
            res.push_back(tmp);
        }
    }

    Matrix<T> mult{this->getNumRows(), rhs.getNumColumns(), res};
    return mult;
}