#include "trainer.h"
using namespace std;

Trainer::Trainer(string n, string number, int a, int exp) : Employee(n,number,a), experience(exp), salary(1200)  {}

void Trainer::display(){
  cout << "Trainer: ";
  Person::display();
  cout << ", Experience: " << experience << " years, " <<
   "Salary: " << "$" << getWage();
}


double Trainer::getWage()const{
  return salary + (experience * BONUS_PER_YEAR);
}
