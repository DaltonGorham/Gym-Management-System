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
  cout << "Press Enter To Continue." << endl;
  cin.get();
 }

 void Gym::saveToFile(string fileName){
  ofstream outputFile(fileName);
  outputFile << "**MONTHLY GYM REPORT**\n\n";
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
  cout << "Information Saved To File." << endl;
  outputFile.close();
 }

 





