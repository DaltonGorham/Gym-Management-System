#include "member.h"
using namespace std;




Member::Member(string n, string number, int a, double subFee) : Customer(n, number, a), subscriptionFee(subFee){}


void Member::display(){
  cout << "Member: ";
  Person::display(); 
  cout << ", Subscription Fee: $" << subscriptionFee << endl;
}

