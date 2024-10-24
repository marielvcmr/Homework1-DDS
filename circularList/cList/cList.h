#include "../node/node.cpp"

template<class T>
class List
{
    private: 
       Node<T>* head = nullptr;
       Node<T>* tail = nullptr;
       int length = 0;
    public: 
       List(Node<T>*);  // constructor to initialize the list, case in which the tail is the same than the tail

       bool isEmpty();

       void insertFirst(T);
       void insertLast(T);
       void insert(T);
       
       bool removeHead();
       bool removeTail();
       bool remove(T);

       bool update(int, T);

       void print();
};