#include<iostream>
using namespace std;

class Person
{
   private:
      string  name;
      string surname;
      int age;
   public:
   Person();
   Person(string, string, int);
   ~Person();

   string getName();
   string getSurname();
   int getAge();
   bool samePerson(Person p);
};

template<class T>
class Node
{
    private:
       T data;
       Node<T>* next = nullptr;
       Node<T>* prev = nullptr;

    public: 
       Node(T, Node<T>*, Node<T>*);
       ~Node();
       
       T getData();
       void setData(T);

       Node<T>* getNext();
       void setNext(Node<T>*);

       Node<T>* getPrev();
       void setPrev(Node<T>*);

       void print();
};