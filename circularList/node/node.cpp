#include <iostream>
#include "node.h"
using namespace std;  

template<class T>
Node<T>::Node(T data, Node<T>* next)
{
    this->data =  data;
    this->next = next;
}

template<class T>
Node<T>::~Node()
{
    this->next = nullptr; //
}

template<class T>
T Node<T>::getData()
{
    return this->data;
}

template<class T>
void Node<T>::setData(T data)
{
    this->data = data;
}

template<class T>
Node<T>* Node<T>::getNext()
{
    return this->next;
}

template<class T>
void Node<T>::setNext(Node<T>* nextNode)
{
    this->next = nextNode;
}

template<class T>
void Node<T>::print()
{
    cout<<"Valor del dato en el nodo: "<<this->data<<endl;
    cout<<"Direccion del siguiente nodo: "<<this->next<<endl;
}