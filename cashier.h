#ifndef Cashier_H
#define Cashier_H
#include "employee.h"

class Cashier : public Employee{
  private:
    double hourlyWage;
    int hoursWorked;
  public: 
    Cashier(string n, string number, int a, double wage, int hoursWorked);
    void display()override;
    double getWage()const override;
};








#endif