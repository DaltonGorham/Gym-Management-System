#ifndef Person_H
#define Person_H
#include <iostream>
using namespace std;
//  Base class
class Person{
  protected:
    string name;
    string phoneNumber;
    int age;
  public:
    Person(string n, string number, int a);
    string getName()const {return name;}
    virtual double getSubscriptionFee() {return 0;};
    virtual void display();
};










#endif