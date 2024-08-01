#ifndef Gym_H
#define Gym_H
#include "employee.h"
#include "customer.h"
#include <vector>


class Gym{
  private:
    vector<Customer*> customers;
    vector<Employee*> employees;
    double grossRevenue;
    double cashierWages;
    const double MEMBER_FEE = 25.00;
    const double PREMIUM_MEMBER_FEE = 35.00;
  public:
    Gym();
    void addMember(string name, string number, int a, double subFee);
    void addPremiumMember(string name, string number, int a, double subFee, double trainFee);
    void addTrainer(string name, string number, int a, int exp);
    void addCashier(string name, string number, int a, double wage,int hours);
    double calcNetRevenue();
    void displayRevenue();
};








#endif