#include "person.h"
#include <iomanip>
using namespace std;




Person::Person(string n, string number, int a) : name(n), phoneNumber(number), age(a){}


void Person::display(){
  cout << "Name: " << name << ", Cell: " << phoneNumber << ", Age: " << age;
}


