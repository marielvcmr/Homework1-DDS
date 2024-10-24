#include "../node/node.cpp"

template<class T>
class List
{
    private:
       Node<T>* head = nullptr;
       Node<T>* tail = nullptr;
       int length = 0;

    public: 
       List(Node<T>*); 

       bool isEmpty();

       void insert(T);

       bool removeHead();  
       bool removeTail();
       bool remove(T);

       bool update(int, T);

       void print();
       void printReverse();
};