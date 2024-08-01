#ifndef Customer_H
#define Customer_H
#include "person.h"


class Customer : public Person{
  public:
  Customer(string n, string number, int a);
   virtual double getTrainerFee() {return 0;}
};








#endif