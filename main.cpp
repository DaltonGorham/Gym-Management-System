#include "ConsoleUi.H"
#include "gym.h"
#include <ios>
#include <limits>
using namespace std;
int main(){
  Console ui;
  Gym gym;

  int choice;

  ui.displayIntro();

  do {
    cout << "1: Add Member\n";
    cout << "2: Add Premium Member\n";
    cout << "3: Add Trainer\n";
    cout << "4: Add Cashier\n";
    cout << "5: Display Customer List\n";
    cout << "6: Diplay Employee List\n";
    cout << "7: Display Revenue\n";
    cout << "8: Save Info To File\n";
    cout << "9: Exit\n";
    cin >> choice;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');


    switch(choice){
      case 1: ui.addMemberFromUser(gym); break;
      case 2: ui.addPremiumMemberFromUser(gym); break;
      case 3: ui.addTrainerFromUser(gym); break;
      case 4: ui.addCashierFromUser(gym); break;
      case 5: ui.displayCustomers(gym); break;
      case 6: ui.displayEmployees(gym); break;
      case 7: gym.displayRevenue(); break;
      case 8: gym.saveToFile("GymReport.txt");
      case 9: break;
      default: "Invalid Option. Choose 1-9.";

    }
  } while(choice != 9);
  
  





  return 0;
}