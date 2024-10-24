#include <iostream>
#include "node.h"

using namespace std;

Person::Person()
{
    name = "";
    surname = "";
    age = 0;
}

Person::Person(string name, string surname, int age)
{
    this->name = name;
    this->surname = surname;
    this->age = age;
}

Person::~Person(){}

string Person::getName()
{
    return this->name;
}

string Person::getSurname()
{
    return this->surname;
}

int Person::getAge()
{
    return this->age;
}

bool Person::samePerson(Person p)
{
    bool result = true;
    if(this->name != p.getName())
    {
        result = false;
    }
    else if(this->surname != p.getSurname())
    {
        result = false;
    }
    else if(this->age != p.getAge())
    {
        result = false;
    }
    return result;
}

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
    cout<<"Datos de la persona: "<<endl;
    cout<<"Nombre: "<<this->getData().getName()<<", Apellido: "<<this->getData().getSurname();
    cout<<", Edad: "<<this->getData().getAge()<<endl;
    cout<<"Direccion del siguiente: "<<this->next<<endl;
    cout<<"Direccion del anterior: "<<this->prev<<endl;
}

