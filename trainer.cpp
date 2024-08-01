#include "trainer.h"
using namespace std;

Trainer::Trainer(string n, string number, int a, int exp) : Employee(n,number,a), experience(exp){}

void Trainer::display(){
  cout << "Trainer: ";
  Person::display();
  cout << "Experience: " << experience << " years" << endl;
}


