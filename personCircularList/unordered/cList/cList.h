#include "../node/node.cpp"

template<class T>
class List
{
    private: 
       Node<T>* head = nullptr;
       Node<T>* tail = nullptr;
       int length = 0;
    public: 
       List(Node<T>*);  // constructor to initialize the list, case in which the tail is the same as the tail

       bool isEmpty(); //

       void insert(T); // what was insertLast, since order doesn't matter
       
       bool removeHead(); //
       bool removeTail(); //
       bool remove(T); //

       bool update(int, T);  // just gets the node and sets a new data value

       void print();
};