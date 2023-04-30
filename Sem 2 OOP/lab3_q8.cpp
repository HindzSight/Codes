#include <iostream>
using namespace std;
  
  
class Order{
    private:
        static double minimumCharge;
        int tableNum;
        string serversName;
        int numOfPatrons;
    public:
        double returnMinimumCharge();
        static void displayMinimumCharge();
};
  
  
double Order::minimumCharge = 4.75;
  
void Order::displayMinimumCharge(){
    cout << "Minimum charge: $" << minimumCharge;
}
int main(void){
     
    Order::displayMinimumCharge();
    return 0;
}