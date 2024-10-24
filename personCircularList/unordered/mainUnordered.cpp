#include <iostream>
#include "./cList/cList.cpp"

using namespace std;

int main()
{
    Person p1("Bank", "Guerreiro", 87); //
    Person p2("Marje", "Gilliatt", 61);
    Person p3("Yvonne", "Partrick", 14);
    Person p4("Anastasie", "Grimes", 86);//
    Person p5("Yuri", "Simonou", 25);
    Person p6("Tabitha", "Wasiela", 37);
    Person p7("Emiline", "Luca", 35);
    Person p8("Simone" , "Montel" ,94);
    Person p9("Natalya", "Blodgetts", 86);//
    Person p10("Nicki", "Hollyar", 76);// **
    Person p11("Alanah", "Thirwell", 64);//
    Person p12("Fayina", "Winchurch", 100);// **

    List<Person> peopleList(nullptr);

    peopleList.insert(p1);
    peopleList.insert(p9);
    peopleList.insert(p12);
    peopleList.insert(p10);
    peopleList.insert(p11);
    peopleList.insert(p4);

    peopleList.print();

    cout<<"Deleting a non-existing person: "<<peopleList.remove(p7)<<endl;
    cout<<"Deleting existing people: "<<peopleList.remove(p10)<<", "<<peopleList.remove(p12)<<endl;

    peopleList.print();

    peopleList.update(2, p7);
    cout<<"Updated list: "<<endl;
    peopleList.print();
}