#ifndef PremiumMember_H
#define PremiumMember_H
#include "member.h"

class PremiumMember : public Member{
  private:
    double trainerFee;
  public:
    PremiumMember(string n, string number, int a, double subFee, double trainFee);
    double getTrainerFee()const {return trainerFee;}
    double getSubscriptionFee()override;
    void display()override;
};









#endif