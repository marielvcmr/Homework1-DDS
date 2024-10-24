#include<iostream>
using namespace std;

class Person
{
   private: 
      string name;
      string surname;
      int age;
   public: 
      Person();             // constructors and destructor 
      Person(string, string, int);
      ~Person();
      // selector
      string getName();
      string getSurname();
      int getAge();
      // comparison
      bool samePerson(Person p);
};

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