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

       void insertFirst(T); // from insert to 
       void insertLast(T);
       void insert(T);

       bool removeHead();  //remove  there might
       bool removeTail();  // be changes in 
       bool remove(T);   //the function structures

       bool update(int, T);

       void print();
       void printReverse();
};