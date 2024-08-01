#include "premiumMember.h"
using namespace std;


PremiumMember::PremiumMember(string n, string number, int a, double subFee,double trainFee) : Member(n,number,a,subFee),  trainerFee(trainFee){}



double PremiumMember::getSubscriptionFee(){
  return Member::getSubscriptionFee();
}

void PremiumMember::display(){
  cout << "Premium ";
  Member::display();
  cout << "Trainer Fee: $" << trainerFee;
}

