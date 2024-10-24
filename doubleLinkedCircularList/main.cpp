#include <iostream>
#include "./cList/cList.cpp"

int main()
{
    List<int> myList(nullptr);
    cout<<"Insertion of 6, 5, 8, 6, 10, 0, 2, 9, 13, 4, 1: "<<endl;
    myList.insert(6);
    myList.insert(5);
    myList.insert(8);
    myList.insert(6);
    myList.insert(10);
    myList.insert(0);
    myList.insert(2);
    myList.insert(9);
    myList.insert(13);
    myList.insert(4);
    myList.insert(1);
    myList.print();
    myList.printReverse();

    cout<<"Deletion of existing elements 5 and 8: ";
    cout<<myList.remove(5)<<" "<<myList.remove(8)<<endl;
    cout<<"Deletion of a non-existing element 3: "<<myList.remove(3)<<endl;
    myList.print();

    cout<<"List with updated elements: "<<endl;
    myList.update(5, 7);
    myList.update(8, 15);
    myList.print();
}
