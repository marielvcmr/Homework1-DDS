template<class T>
class Node
{
    private: 
       T data;
       Node<T>* next = nullptr;
    public: 
       Node(T, Node<T>*); // Constructor
       ~Node();          // Destructor

       T getData();
       void setData(T);

       Node<T>* getNext();
       void setNext(Node<T>*);
       
       void print();
};