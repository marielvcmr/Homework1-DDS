#include <iostream>
#include "cList.h"

using namespace std;

template<class T>
List<T>::List(Node<T>* node)
{
    this->head = node;
    this->tail = node;
    if(node != nullptr)  //in this case,  head and tail cannot point to a null value
    {
        head->setNext(tail);
    }  
}

template<class T>
bool List<T>::isEmpty()
{
    return head == nullptr;
}

template <class T>
void List<T>::insert(T data)
{
    Node<T>* newNode = new Node<T>(data, nullptr);
    
    if(isEmpty())
    {
        this->head = newNode;
        this->tail = newNode;
        this->head->setNext(tail);
    }
    else  // case list is not empty
    {
        tail->setNext(newNode);
        newNode->setNext(head);
        tail = newNode;
    }
    this->length++;
    return;
}

template<class T>
bool List<T>::removeHead()
{
    if(isEmpty())
    {
        return false;
    }
    else if( head->getNext() == tail) // or list length equals 1
    {
        delete head;
        delete tail;
        head = nullptr;
        tail = nullptr;
        this->length--;
        return true;
    }
    else // length greater than 1
    {
        Node<T>* NodeToDelete = head;
        tail->setNext(head->getNext());
        head = head->getNext();
        delete NodeToDelete;
        this->length--;
        return true;
    }
}

template<class T>
bool List<T>::removeTail()
{
    if(isEmpty())
    {
        return false;
    }
    else if( head->getNext() == tail) // or list length equals 1
    {
        delete head;
        delete tail;
        head = nullptr;
        tail = nullptr;
        this->length--;
        return true;
    }
    else
    {
        Node<T>* prev = head;
        while(prev->getNext() != tail)
        {
            prev = prev->getNext();
        }
        
        Node<T>* NodeToDelete = tail;
        prev->setNext(head);
        tail = prev;
        delete NodeToDelete;
        this->length--;
        return true;
    }
}

template<class T>
bool List<T>::remove(T data)
{
    if(isEmpty())
    {
        return false;
    }
    else if(head->getData().samePerson(data))   // BY HERE TO COMPARE TWO PEOPLE
    {
        return removeHead();
    }
    else if(tail->getData().samePerson(data))
    {
        return removeTail();
    }
    else
    {
        Node<T>* prev = tail;
        Node<T>* NodeToDelete = head;
        do
        {
            prev = NodeToDelete;
            NodeToDelete = NodeToDelete->getNext();
        }
        while (NodeToDelete != tail && !(NodeToDelete->getData().samePerson(data)));

        if(NodeToDelete->getData().samePerson(data))
        {
           prev->setNext(NodeToDelete->getNext());
           delete NodeToDelete;
           this->length--;
           return true;
        }
        else
        {
            return false;
        }
    }
}

template<class T>
bool List<T>::update(int n, T data)
{
    if(isEmpty() || n >= this->length || n < 0)
    {
        return false;
    }
    
    Node<T>* nodeToUpdate = head;

    for(int i = 0; i<n; i++)
    {
        nodeToUpdate = nodeToUpdate->getNext();  // sets the node to be updated
    }

    nodeToUpdate->setData(data);
    return true;
}

template<class T>
void List<T>::print()
{
    Node<T>* temp =  head;
    cout<<"Length of List: "<<this->length<<endl;
    cout<<"head: "<<head<<endl<<"People on the list: "<<endl;
    do
    {
        temp->print();
        cout<<endl;
        temp = temp->getNext();
    }
    while(temp != head);
    cout<<endl;
}

