#include "iostream"
#include "./cList/cList.cpp"

using namespace std;

int main()
{
    List<int> myList(nullptr);
    myList.insert(5);
    myList.insert(2);
    myList.insert(5);
    myList.insert(6);
    myList.insert(2);
    myList.insert(0);
    myList.insert(4);
    myList.print();
    
    cout<<"Remove 0 and 2 (existing elements) and 8 (non-existing element): "<<myList.remove(0)<<" "<<myList.remove(2)<<", "<<myList.remove(8)<<endl;
    myList.print();
    
    cout<<"Updated list: "<<endl;
    cout<<myList.update(2, 3)<<endl;
    myList.print();

}