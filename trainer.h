#ifndef Trainer_H
#define Trainer_H
#include "employee.h"

class Trainer : public Employee{
  private:
    int experience;
    double salary;
    const double BONUS_PER_YEAR = 100;
  public:
    Trainer(string n, string number, int a, int exp);
    void display()override;
    double getWage()const override;
   

};





#endif