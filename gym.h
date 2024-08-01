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
    const double PREMIUM_FEE = 35.00;
    const double TRAINING_FEE = 10.00;
  public:
    Gym();
    ~Gym();
    void addMember(string name, string number, int a, double subFee);
    void addPremiumMember(string name, string number, int a, double subFee, double trainFee);
    void addTrainer(string name, string number, int a, int exp);
    void addCashier(string name, string number, int a, double wage,int hours);
    double calcNetRevenue();
    void displayRevenue();
    void displayCustomers();
    void displayEmployees();
    void saveToFile(string fileName);
    void addMemberFromUser(Gym& gym);
    void addPremiumMemberFromUser(Gym& gym);
    void addTrainerFromUser(Gym& gym);
};








#endif