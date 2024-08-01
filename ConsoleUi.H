#ifndef ConsoleUI_H
#define ConsoleUI_H
#include "gym.h"


class Console : public Gym{
  public:
    void displayCustomers(Gym& gym);
    void displayEmployees(Gym& gym);
    void addMemberFromUser(Gym& gym);
    void addPremiumMemberFromUser(Gym& gym);
    void addTrainerFromUser(Gym& gym);
    void addCashierFromUser(Gym& gym);
    void clearScreen() {cout << "\033[2J\033[1;1H";}
    void displayIntro();
    void bufferInput();
};










#endif