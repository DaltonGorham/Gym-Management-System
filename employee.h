#ifndef Employee_H
#define Employee_H
#include "person.h"

class Employee : public Person{
  public:
    Employee(string n, string number, int a);
    virtual double getWage()const {return 0;};
};







#endif