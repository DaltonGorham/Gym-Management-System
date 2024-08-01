#include "gym.h"
#include "member.h"
#include "premiumMember.h"
#include "cashier.h"
#include "trainer.h"

Gym::Gym() : grossRevenue(0){}


void Gym::addMember(string name, string number, int a, double subFee){
  customers.push_back(new Member(name,number,a,subFee));
  grossRevenue += subFee;
}

void Gym::addPremiumMember(string name, string number, int a, double subFee, double trainFee){
  customers.push_back(new PremiumMember(name,number,a,subFee,trainFee));
  grossRevenue += subFee;
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
 }
