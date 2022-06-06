#include <iostream>
#include <string>


#include "DynamicArray.h"
#include "LinkedList.h"
#include "Tests.h"
#include "Matrix.h"
#include "Matrix.cpp"

using namespace std;






#define main_menu  cout<<"Choose:\n "  \
    "1.DynamicArray\n 2.LinkedList\n 3.Matrix\n 4.UnitTest\n" <<endl;

#define massiv_menu cout<<" 1)Find element by index\n 2)Get size\n 3)Set element by index \n 4)Print massiv\n 5)Resize an array\n 6)Exit\n"<<endl;
#define string_menu cout<<" 1)Get first element in a list\n " \
                            "2)Get last element in a list\n "\
                            "3)Get element by index\n "\
                            "4)Get the length of the list\n "\
                            "5)Add an element to the end of the list\n"\
                            "6)Add an element to the beginning of the list\n "\
                            "7)Insert an element at a given position\n"\
                            "8.Print list"<<endl;

#define matrix_menu cout<<"1.Matrix +\n" \
                          "2.Matrix -\n"                 \
                          "3.Martix *\n"\
                          "4.Multiplication by scalar\n"\
                          "5.Print matrix 1 and matrix 2\n"\
                          "6.Insert values by index\n"   \
                            "7.Matrix norm\n"             \
                            "8.Exit"<<endl;

int main() {

    main_menu

    while (true) {
        int choose;
        cin >> choose;
        switch (choose) {
            case 1: {
                cout << "Enter number elements massiv: "<<endl;
                int size;
                cin >> size;
                DynamicArray<int> test(size);
                cout << "Enter massiv"<<endl;
                for (int i = 0; i < size; i++) {
                    int chislo;
                    cin >> chislo;
                    test.Set(i,chislo);
                }
                massiv_menu
                while (true) {
                    int menu2;
                    cin >> menu2;
                    switch (menu2){
                        case 1:
                            int index;
                            cout << "Enter index: ";
                            cin >> index;
                            cout << "Values: " << test.Get(index) << endl;
                            break;
                        case 2:
                            cout <<test.GetSize()<< endl;
                            break;
                        case 3:
                            int index_val,values;
                            cout << "Enter index: "<< endl;
                            cin >> index_val;
                            cout << "Enter values: "<< endl;
                            cin >> values;
                            test.Set(index_val,values);
                            break;
                        case 4:
                            test.print_massvi();
                            break;
                        case 5:
                            int new_size;
                            cout << "Enter new size: "<< endl;
                            cin >> new_size;
                            test.Resize(new_size);
                            break;
                        case 6:
                            return 0;

                    }
                }

            }
            case 2: {
                LinkedList<int> spicok;

                string_menu


                while (true) {
                    int str_men;
                    cin >> str_men;
                    switch (str_men) {
                        case 1:
                            cout << "First element is: " << spicok.GetFirst() << endl;
                            break;
                        case 2:
                            cout << "Last element is: " << spicok.GetLast() << endl;
                            break;
                        case 3:
                            cout << "Enter index: " << endl;
                            int index1;
                            cin >> index1;
                            spicok.Get(index1);
                            break;
                        case 4:
                            cout << "List Length: " << spicok.GetLength() << endl;
                            break;
                        case 5:
                            cout << "Enter element" << endl;
                            int element;
                            cin >> element;
                            spicok.Append(element);
                            cout << "An element has been added to the end" << endl;
                            break;
                        case 6:
                            cout << "Enter element" << endl;
                            int element1;
                            cin >> element1;
                            spicok.Prepend(element1);
                            cout << "An element has been added to the start" << endl;
                            break;
                        case 7:
                            cout << "Enter element" << endl;
                            int element2;
                            cin >> element2;

                            cout << "Enter position to append element" << endl;
                            int position;
                            cin >> position;

                            spicok.InsertAt(element2, position);
                            cout << element2 << " has been added to" << position << endl;
                            break;
                        case 8:{
                            for(int i=0;i<spicok.GetLength();i++){
                                cout<<spicok.Get(i)<<" ";
                            }
                            cout<<""<<endl;
                            break;
                        }
                        case 9:{
                            return 0;
                        }

                    }
                }
            }

            case 3:
            {
                int type;
                while (true) {
                    cout << "Select type \n"
                            "1. int\n"
                            "2. float\n" << endl;

                    cin>>type;

                    int row,columns,val,row2,columns2;

                    cout << "Input row matrix 1"<<endl;
                    cin>>row;
                    cout << "Input columns matrix 1"<<endl;
                    cin>>columns;


                    cout << "Input row matrix 2"<<endl;
                    cin>>row2;
                    cout << "Input columns matrix 2"<<endl;
                    cin>>columns2;

                    cout << "1)Fill matrix with zeros\n"
                            "2)Enter values"<<endl;
                    cin>>val;

                    if (type ==1){


                        if (val ==1){
                            Matrix<int> matrix1{row,columns};
                            Matrix<int> matrix2{row2,columns2};
                            matrix_menu
                            while (true) {
                                int ch;
                                cin >> ch;
                                switch (ch) {
                                    case 1: {
                                        matrix1 = matrix1 + matrix2;
                                        matrix1.print();
                                        break;
                                    }
                                    case 2: {
                                        matrix1 = matrix1 - matrix2;
                                        matrix1.print();
                                        break;
                                    }
                                    case 3: {
                                        matrix1 = matrix1 * matrix2;
                                        matrix1.print();
                                        break;
                                    }
                                    case 4:{
                                        cout << "Enter skalyar" << endl;
                                        int ckal;
                                        cin>>ckal;
                                        matrix1.multiplacrion_on_skalyar(ckal);
                                        matrix1.print();
                                        break;
                                    }
                                    case 5:{
                                        matrix1.print();
                                        cout << "--------------------------------"<<endl;
                                        matrix2.print();
                                        break;
                                    }
                                    case 6:{
                                        int ind_r,ind_s,val;
                                        cout<< "Enter row" << endl;
                                        cin>>ind_r;
                                        cout<< "Enter Columns" << endl;
                                        cin>>ind_s;
                                        cout<< "Enter val" << endl;
                                        cin>>val;
                                        matrix1.insert(ind_r,ind_s,val);
                                        break;
                                    }
                                    case 7:{
                                        cout << "Matrix #1 norm"<<endl;
                                        cout << matrix1.matrix_norm()<<endl;
                                        cout << "Matrix #2 norm"<<endl;
                                        cout << matrix2.matrix_norm()<<endl;
                                        break;
                                    }
                                    case 8:{
                                        return 0;
                                    }

                                }
                            }

                        }
                        else if(val ==2) {

                            vector<int> vec1;
                            cout << "Enter values massiv 1:" << endl;
                            for (int i = 0; i < row * columns; i++) {
                                int ins;
                                cin >> ins;
                                vec1.push_back(ins);
                            }

                            vector<int> vec2;
                            cout << "Enter values massiv 2:" << endl;
                            for (int i = 0; i < row2 * columns2; i++) {
                                int ins;
                                cin >> ins;
                                vec2.push_back(ins);
                            }

                            Matrix<int> matrix1{row, columns, vec1};
                            Matrix<int> matrix2{row2, columns2, vec2};


                            matrix_menu
                            while (true) {
                                int ch;
                                cin >> ch;

                                switch (ch) {
                                    case 1: {
                                        matrix1 = matrix1 + matrix2;
                                        matrix1.print();
                                        break;
                                    }
                                    case 2: {
                                        matrix1 = matrix1 - matrix2;
                                        matrix1.print();
                                        break;
                                    }
                                    case 3: {
                                        matrix1 = matrix1 * matrix2;
                                        matrix1.print();
                                        break;
                                    }
                                    case 4:{
                                        cout << "Enter skalyar" << endl;
                                        int ckal;
                                        cin>>ckal;
                                        matrix1.multiplacrion_on_skalyar(ckal);
                                        matrix1.print();
                                        break;
                                    }
                                    case 5:{
                                        matrix1.print();
                                        cout << "--------------------------------"<<endl;
                                        matrix2.print();
                                        break;
                                    }
                                    case 6:{
                                        int ind_r,ind_s,val;
                                        cout<< "Enter row" << endl;
                                        cin>>ind_r;
                                        cout<< "Enter Columns" << endl;
                                        cin>>ind_s;
                                        cout<< "Enter val" << endl;
                                        cin>>val;
                                        matrix1.insert(ind_r,ind_s,val);
                                        break;
                                    }
                                    case 7:{
                                        cout << "Matrix #1 norm"<<endl;
                                        cout << matrix1.matrix_norm()<<endl;
                                        cout << "Matrix #2 norm"<<endl;
                                        cout << matrix2.matrix_norm()<<endl;
                                        break;
                                    }
                                    case 8:{
                                        return 0;
                                    }

                                }
                            }
                        }

                    }

                    else if(type ==2){

                        if (val ==1){
                            Matrix<float> matrix1{row,columns};
                            Matrix<float> matrix2{row2,columns2};
                            matrix_menu
                            while (true) {
                                int ch;
                                cin >> ch;
                                switch (ch) {
                                    case 1: {
                                        matrix1 = matrix1 + matrix2;
                                        matrix1.print();
                                        break;
                                    }
                                    case 2: {
                                        matrix1 = matrix1 - matrix2;
                                        matrix1.print();
                                        break;
                                    }
                                    case 3: {
                                        matrix1 = matrix1 * matrix2;
                                        matrix1.print();
                                        break;
                                    }
                                    case 4:{
                                        cout << "Enter skalyar" << endl;
                                        int ckal;
                                        cin>>ckal;
                                        matrix1.multiplacrion_on_skalyar(ckal);
                                        matrix1.print();
                                        break;
                                    }
                                    case 5:{
                                        matrix1.print();
                                        cout << "--------------------------------"<<endl;
                                        matrix2.print();
                                        break;
                                    }
                                    case 6:{
                                        int ind_r,ind_s;
                                        float val;
                                        cout<< "Enter row" << endl;
                                        cin>>ind_r;
                                        cout<< "Enter Columns" << endl;
                                        cin>>ind_s;
                                        cout<< "Enter val" << endl;
                                        cin>>val;
                                        matrix1.insert(ind_r,ind_s,val);
                                        break;
                                    }
                                    case 7:{
                                        cout << "Matrix #1 norm"<<endl;
                                        cout << matrix1.matrix_norm()<<endl;
                                        cout << "Matrix #2 norm"<<endl;
                                        cout << matrix2.matrix_norm()<<endl;
                                        break;
                                    }
                                    case 8:{
                                        return 0;
                                    }

                                }
                            }

                        }
                        else if(val ==2) {

                            vector<float> vec1;
                            cout << "Enter values massiv 1:" << endl;
                            for (int i = 0; i < row * columns; i++) {
                                float ins;
                                cin >> ins;
                                vec1.push_back(ins);
                            }

                            vector<float> vec2;
                            cout << "Enter values massiv 2:" << endl;
                            for (int i = 0; i < row2 * columns2; i++) {
                                float ins;
                                cin >> ins;
                                vec2.push_back(ins);
                            }

                            Matrix<float> matrix1{row, columns, vec1};
                            Matrix<float> matrix2{row2, columns2, vec2};


                            matrix_menu
                            while (true) {
                                int ch;
                                cin >> ch;

                                switch (ch) {
                                    case 1: {
                                        matrix1 = matrix1 + matrix2;
                                        matrix1.print();
                                        break;
                                    }
                                    case 2: {
                                        matrix1 = matrix1 - matrix2;
                                        matrix1.print();
                                        break;
                                    }
                                    case 3: {
                                        matrix1 = matrix1 * matrix2;
                                        matrix1.print();
                                        break;
                                    }
                                    case 4:{
                                        cout << "Enter skalyar" << endl;
                                        int ckal;
                                        cin>>ckal;
                                        matrix1.multiplacrion_on_skalyar(ckal);
                                        matrix1.print();
                                        break;
                                    }
                                    case 5:{
                                        matrix1.print();
                                        cout << "--------------------------------"<<endl;
                                        matrix2.print();
                                        break;
                                    }
                                    case 6:{
                                        int ind_r,ind_s,val;
                                        cout<< "Enter row" << endl;
                                        cin>>ind_r;
                                        cout<< "Enter Columns" << endl;
                                        cin>>ind_s;
                                        cout<< "Enter val" << endl;
                                        cin>>val;
                                        matrix1.insert(ind_r,ind_s,val);
                                        break;
                                    }
                                    case 7:{
                                        cout << "Matrix #1 norm"<<endl;
                                        cout << matrix1.matrix_norm()<<endl;
                                        cout << "Matrix #2 norm"<<endl;
                                        cout << matrix2.matrix_norm()<<endl;
                                        break;
                                    }
                                    case 8:{
                                        return 0;
                                    }

                                }
                            }
                        }

                    }


                    else{
                        cout << "Type is not defind" <<endl;
                        break;
                    }


                }
            }
            case 4:
            {

                TestDynamic();
                //test();
                matrix();
                TestLinkedList();
                testInsert();

                cout<<"ALL OK"<<endl;

            }

        }



    }



}
