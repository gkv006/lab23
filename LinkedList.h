#ifndef LABA23_LINKEDLIST_H
#define LABA23_LINKEDLIST_H

#include <iostream>
#include <string>

using namespace std;


template <class T> //Class for the list LinkedList
class Node{
public:
    T data;
    Node *next;
};

template <class T>
class LinkedList{

    Node<T> *head = NULL;

public:

//adding to the list
    void Append(T item){
        Node <T> *temp = new Node<T>;
        temp->data = item;
        temp->next = NULL;
        if (this->head == NULL)
            this->head = temp;
        else
        {
            Node <T> *current = this->head;
            while(current->next != NULL){
                current = current->next;
            }
            current->next = temp;
        }
    }



    void Prepend(T item){
        Node <T> *temp = new Node<T>;
        temp->data = item;
        temp->next = this->head;
        this->head = temp;
    }

    void InsertAt(T item, int index){
        if(index > this->GetLength() || index < 0) throw "IndexOutOfRange";
        else
        {
            Node <T> *current = this->head;
            Node <T> *temp = new Node <T>;
            temp->data = item;
            int i = 0;
            for(;i<index - 1;i++){
                current = current->next;
            }
            temp->next = current->next;
            current->next = temp;
        }
    }

//constructors

    LinkedList(){
        Node <T> *current = this->head;
        while (current)
        {
            Node<T> * nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    LinkedList (const LinkedList <T> & list){
        Node <T> *current = list.head;
        while(current != NULL){
            this->Append(current->data);
            current = current->next;
        }
    }

    LinkedList(T *items, int count){
        for(int i=0;i<count;i++){
            Append(items[i]);
        }
    }


    ~LinkedList(){
        this->head = NULL;
    }

//other

    int GetLength(){
        Node <T> *current = this->head;
        int ans = 0;
        while(current != NULL){
            current = current->next;
            ans++;
        }
        return ans;
    }

    T GetFirst(){
        if(this->GetLength()==0)
            throw "IndexOutOfRange";
        else
            return this->head->data;
    }

    T Get(int index){
        if(index >= this->GetLength() || index < 0)
            throw "IndexOutOfRange";
        else{
            Node<T> *temp = this->head;
            for(int i = 0; i < index; i++){
                temp = temp->next;
            }
            return temp->data;
        }
    }

    T GetLast(){
        if(this->GetLength()==0)
            throw "IndexOutOfRange";
        else
        {
            Node<T> *temp = this->head;
            while(temp->next != NULL)
                temp = temp->next;
            return temp->data;
        }
    }

    LinkedList<T> GetSubList(int startIndex, int endIndex){
        if (startIndex > endIndex || startIndex<0 || endIndex<0 || endIndex>this->GetLength())
            throw "IndexOutOfRange";
        else{
            LinkedList <T> ans;
            for(int i = startIndex; i<=endIndex; i++){
                ans.Append(this->Get(i));
            }
            return ans;
        }
    }

    LinkedList<T> Concat(LinkedList<T> list){
        LinkedList <T> ans;
        for(int i=0;i<this->GetLength();i++){
            ans.Append(this->Get(i));
        }
        for(int i=0;i<list.GetLength();i++){
            ans.Append(list.Get(i));
        }
        return ans;
    }

};

#endif //LABA23_LINKEDLIST_H