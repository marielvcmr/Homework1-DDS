#include <iostream>
#include "node.h"

using namespace std;

template<class T>
Node<T>::Node(T data, Node<T>*, Node<T>*)
{
    this->data = data;
    this->next = next;
    this->prev = prev;
}

template<class T>
Node<T>::~Node()
{
    this->next = nullptr;
    this->prev = nullptr;
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
Node<T>* Node<T>::getPrev()
{
    return this->prev;
}

template<class T>
void Node<T>::setPrev(Node<T>* prevNode)
{
    this->prev = prevNode;
}

template<class T>
void Node<T>::print()
{   
    cout<<"Data value: "<<this->data<<endl;
    cout<<"Direccion del siguiente: "<<this->next<<endl;
    cout<<"Direccion del anterior: "<<this->prev<<endl;
}

