#include "cashier.h"


Cashier::Cashier(string n, string number, int a, double wage, int hours) : Employee(n,number,a), hourlyWage(wage), hoursWorked(hours){}


void Cashier::display(){
  cout << "Cashier: ";
  Person::display();
  cout << endl;
  cout << "Hourly Wage: " << hourlyWage << endl;
}


double Cashier::getWage()const{
  return hourlyWage * hoursWorked;
}