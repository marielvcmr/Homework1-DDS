#include <iostream>
#include "./cList/cList.cpp"

using namespace std;

int main()
{
    Person p1("Dottie", "Cottem",53);
    Person p2("Madelena", "Kopps", 88);
    Person p3("Liliane", "Redmain", 39);
    Person p4("Elvyn", "Conew", 22);
    Person p5("Charo", "Weatherhogg", 18);
    Person p6("Cosimo", "Murdoch", 39);
    Person p7("Hatti", "Crippill", 76);
    Person p8("Emily", "Carrell", 39);
    Person p9("Aldis", "Hillhouse", 64);
    Person p10("Jesus", "Edmand", 60);
    Person p11("Davide", "Murdy", 84);
    Person p12("Jeremy","Jeness", 67);
    Person p13("Bonnie", "Drennan", 79);
    Person p14("Niki", "Hofer", 67);
    Person p15("Vincenty", "Hazelden", 29);
    Person p16("Elka", "Dumphreys", 83);
    Person p17("Reid", "Sicily", 32);
    Person p18("Darren", "Ronaldson", 16);
    Person p19("Elihu", "Wilton", 23);
    Person p20("Chrystel", "Hollier", 38);

    List<Person> peopleList(nullptr);

    peopleList.insert(p1);
    peopleList.insert(p2);
    peopleList.insert(p3);
    peopleList.insert(p4);
    peopleList.insert(p5);
    peopleList.insert(p6);
    peopleList.insert(p7);
    peopleList.insert(p8);
    peopleList.insert(p9);
    peopleList.insert(p10);
    peopleList.insert(p11);
    peopleList.insert(p12);

    peopleList.print();

    cout<<"Deleting a non-existing person: "<<peopleList.remove(p13)<<endl;
    cout<<"Deleting existing people: "<<peopleList.remove(p10)<<", "<<peopleList.remove(p8)<<endl;

    peopleList.print();

    peopleList.update(3, p16);
    cout<<"Updated list: "<<endl;
    peopleList.print();
    peopleList.printReverse();
}