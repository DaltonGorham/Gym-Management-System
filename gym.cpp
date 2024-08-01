#include "gym.h"
#include "member.h"
#include "premiumMember.h"
#include "cashier.h"
#include "trainer.h"
#include "fstream"
#include <string>

Gym::Gym() : grossRevenue(0){}

Gym::~Gym() {
  for (Customer* & customer : customers){
    delete customer;
  }

  for (Employee* & employee : employees){
    delete employee;
  }
}

void Gym::addMember(string name, string number, int a, double subFee){
  customers.push_back(new Member(name,number,a,subFee));
  grossRevenue += subFee;
}

void Gym::addPremiumMember(string name, string number, int a, double subFee, double trainFee){
  customers.push_back(new PremiumMember(name,number,a, subFee, trainFee));
  grossRevenue += subFee + trainFee;
}

void Gym::addTrainer(string name, string number, int a, int exp){
  employees.push_back(new Trainer(name,number,a,exp));
  
}

void Gym::addCashier(string name, string number, int a, double wage,int hoursWorked){
  employees.push_back(new Cashier(name,number,a,wage,hoursWorked));
}

void Gym:: displayCustomers(){
  for (Customer* & customer : customers){
    customer->display();
  }
}

void Gym::displayEmployees(){
  for (Employee* & employee : employees){
    employee->display();
  }
}



double Gym::calcNetRevenue(){
  double trainerFees = 0;
  double cashierWages = 0;

  for (Customer* & customer : customers){
    trainerFees += customer->getTrainerFee();
  }

  for (Employee* & employee : employees){
    cashierWages += employee->getWage();
  }

  return grossRevenue - trainerFees - cashierWages;
}


 void Gym:: displayRevenue(){
  cout << "Total Gross Revenue: " << "$" << grossRevenue << endl;
  cout << "Total Net Revenue: " << "$" << calcNetRevenue() << endl;
 }



 void Gym::saveToFile(string fileName){
  ofstream outputFile(fileName);
  outputFile << "CUSTOMERS" << endl;
  for (Customer* & customer : customers){
    outputFile << customer->getName() << ", Membership Status: ";
    if (customer->getSubscriptionFee() == MEMBER_FEE){
      outputFile << "Member" << endl;
    }
    else {
      outputFile << "Premium Member" << endl;
    }
  }
  outputFile << "Total Customers: " << customers.size();

  outputFile << endl << endl;

  outputFile << "EMPLOYEES: " << endl;

  for (Employee* & employee : employees){
    outputFile << employee->getName() << ": $" << employee->getWage() << endl;
  }
  outputFile << "Total Employees: " << employees.size();

  outputFile << endl << endl;

  outputFile << "Total Gross Revenue: " << "$" << grossRevenue << endl;
  outputFile << "Total Net Revenue: " << "$" << calcNetRevenue() << endl;

  outputFile.close();
 }

void Gym::addMemberFromUser(Gym& gym){
  string name, phoneNumber;
  int age;
  

  cout << "Enter Member's Name: ";
  getline(cin,name);
  cout << "Enter Member's Phone Number: ";
  getline(cin,phoneNumber);
  cout << "Enter Member's Age: ";
  cin >> age;
  cin.ignore();

  gym.addMember(name,phoneNumber,age,MEMBER_FEE);

}

void Gym::addPremiumMemberFromUser(Gym& gym) {
  string name, phoneNumber;
  int age;

  cout << "Enter premium member's name: ";
  cin >> ws;
  getline(cin, name);
  cout << "Enter premium member's phone number: ";
  getline(cin, phoneNumber);
  cout << "Enter premium member's age: ";
  cin >> age;

  gym.addPremiumMember(name, phoneNumber, age, PREMIUM_FEE, TRAINING_FEE);
}

void Gym:: addTrainerFromUser(Gym& gym) {
  string name, phoneNumber;
  int age, experience;

  cout << "Enter trainer's name: ";
  cin >> ws;
  getline(cin, name);
  cout << "Enter trainer's phone number: ";
  getline(cin, phoneNumber);
  cout << "Enter trainer's age: ";
  cin >> age;
  cout << "Enter trainer's years of experience: ";
  cin >> experience;

  gym.addTrainer(name, phoneNumber, age, experience);
}


void Gym:: addCashierFromUser(Gym& gym) {
  string name, phoneNumber;
  int age;
  double hourlyRate;
  int hoursWorked;

  cout << "Enter cashier's name: ";
  cin >> ws;
  getline(cin, name);
  cout << "Enter cashier's phone number: ";
  getline(cin, phoneNumber);
  cout << "Enter cashier's age: ";
  cin >> age;
  cout << "Enter cashier's hourly rate: ";
  cin >> hourlyRate;
  cout << "Enter cashier's hours worked per week: ";
  cin >> hoursWorked;

  gym.addCashier(name, phoneNumber, age, hourlyRate, hoursWorked);
}
