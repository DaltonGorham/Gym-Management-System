#include "person.cpp"
#include "customer.cpp"
#include "member.cpp"
#include "premiumMember.cpp"
#include "employee.cpp"
#include "trainer.cpp"
#include "cashier.cpp"
#include "gym.cpp"
using namespace std;
int main(){
  
  Gym gym;

  gym.addMember("dalton", "501-887-6029", 21, 25);
  gym.addMember("dalton", "501-887-6029", 21, 25);
  gym.addMember("dalton", "501-887-6029", 21, 25);
  gym.addMember("dalton", "501-887-6029", 21, 25);
  gym.addMember("dalton", "501-887-6029", 21, 25);
  gym.addPremiumMember("kiley", "501-556-4999", 21, 35, 10);
  gym.addCashier("pat", "501-227-8897", 22, 11.25, 100);
  gym.addTrainer("Riley", "501-206-2755", 33, 4);

  gym.displayRevenue();
  cout << endl;

  gym.displayCustomers();
  cout << endl;
  gym.displayEmployees();

  gym.saveToFile("GymReport.txt");
  
  





  return 0;
}