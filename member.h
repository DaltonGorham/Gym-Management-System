#ifndef Member_H
#define Member_H
#include "customer.h"


class Member : public Customer{
  private:
    double subscriptionFee;
  public: 
    Member(string n, string number, int a, double subFee);
    double getSubscriptionFee() override {return subscriptionFee;}
    void display()override;
};








#endif