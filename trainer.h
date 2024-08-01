#ifndef Trainer_H
#define Trainer_H
#include "employee.h"

class Trainer : public Employee{
  private:
    int experience;
  public:
    Trainer(string n, string number, int a, int exp);
    void display()override;
};





#endif