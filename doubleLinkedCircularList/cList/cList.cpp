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
void List<T>::insertFirst(T data)
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
        this->head  = newNode;
    }
    this->length++;
    return;
}

template<class T>
void List<T>::insertLast(T data)
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
void List<T>::insert(T data)
{
    if(isEmpty() || data<head->getData())
    {
        insertFirst(data);
    }
    else if(data>tail->getData())
    {
        insertLast(data);
    }
    else
    {
        if(length == 1) //head = data = tail
        {
            insertFirst(data);
        }
        else
        {
            Node<T>* newNode = new Node<T>(data, nullptr, nullptr);
            Node<T>* actual = head;
            Node<T>* prev = tail;
            
            do
            {
                prev = actual;
                actual = actual->getNext();
            } // check tail condition
            while (actual != tail && actual->getData()<data);
            newNode->setNext(actual);
            newNode->setPrev(prev);
            actual->setPrev(newNode);
            prev->setNext(newNode);
            this->length++;    
        }
    }
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
    else if(head->getData() == data)
    {
        return removeHead();
    }
    else if(tail->getData() == data)
    {
        return removeTail();
    }
    else
    {
        Node<T>* NodeToDelete = head;

        do
        {
            NodeToDelete = NodeToDelete->getNext();

        } while (NodeToDelete != tail && NodeToDelete->getData()!= data);

        if(NodeToDelete->getData() == data)
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
    Node<T>* last = tail;

    for(int i = 0; i<n; i++)
    {
        last = nodeToUpdate;
        nodeToUpdate = nodeToUpdate->getNext();  // sets the node to be updated
    }

    T oldData = nodeToUpdate->getData();
    T lastData = last->getData();         // gets data from nodes

    if(nodeToUpdate == tail)
    {
        if(oldData>data)
        {
            remove(oldData);
            insert(data);
        }
        else
        {
            nodeToUpdate->setData(data);
        }
        return true;
    }

    if(nodeToUpdate == head)
    {
        if(oldData<data)
        {
            remove(oldData);
            insert(data);
        }
        else
        {
            nodeToUpdate->setData(data);
        }
        return true;
    }

    if(lastData<= data && data<= nodeToUpdate->getNext()->getData())
    {
        nodeToUpdate->setData(data);
    }
    else
    {
        remove(oldData);
        insert(data);
    }
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