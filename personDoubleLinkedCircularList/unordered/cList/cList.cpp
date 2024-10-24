#include <iostream>
#include "cList.h"
using namespace std;

template<class T>
List<T>::List(Node<T>* node)
{
    head = node;
    tail = node;

    if( node !=nullptr)
    {
        head->setNext(tail);
        tail->setPrev(head);
    }
}

template<class T>
bool List<T>::isEmpty()
{
    return this->head == nullptr;
}

template<class T>
void List<T>::insert(T data)
{
    Node<T>* newNode = new Node<T>(data, nullptr, nullptr);
    if(isEmpty())
    {
        head = newNode;
        tail = newNode;
        head->setNext(tail);
        tail->setPrev(head);        
    }
    else
    {
        newNode->setPrev(tail);
        newNode->setNext(head);
        head->setPrev(newNode);
        tail->setNext(newNode);
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
    else if(head->getNext()==tail)
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
        Node<T>* NodeToDelete = head;
        head = NodeToDelete->getNext();
        head->setPrev(tail);
        tail->setNext(head);
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
        Node<T>* NodeToDelete = tail;
        tail = tail->getPrev();
        head->setPrev(tail);
        tail->setNext(head);
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
    else if(head->getData().samePerson(data))
    {
        return removeHead();
    }
    else if(tail->getData().samePerson(data))
    {
        return removeTail();
    }
    else
    {
        Node<T>* NodeToDelete = head;

        do
        {
            NodeToDelete = NodeToDelete->getNext();

        } while (NodeToDelete != tail && !(NodeToDelete->getData().samePerson(data)));

        if(NodeToDelete->getData().samePerson(data))
        {
            NodeToDelete->getPrev()->setNext(NodeToDelete->getNext());
            NodeToDelete->getNext()->setPrev(NodeToDelete->getPrev());
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
    Node<T>* temp = head;
    cout<<"List length: "<<length<<endl;
    cout<<"List from head to tail: "<<endl;
    do
    {
        temp->print();
        temp = temp->getNext();
    } while(temp != head);
    cout<<endl;
}

template<class T>
void List<T>::printReverse()
{
    Node<T>* temp = tail;
    cout<<"List length: "<<length<<endl;
    cout<<"List from tail to head: "<<endl;
    do
    {
        temp->print();
        temp = temp->getPrev();
    } while (temp != tail); 
    cout<<endl;  
}