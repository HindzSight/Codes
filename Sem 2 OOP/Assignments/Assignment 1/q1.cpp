#include <iostream>
using namespace std;
struct phone
{
    int areacode, exchange, number;
} phone1, phone2;

int main()
{
    phone1.areacode = 212;
    phone1.exchange = 767;
    phone1.number = 8900;

    cout << "Enter your areacode, exchange, and number: ";
    cin >> phone2.areacode >> phone2.exchange >> phone2.number;

    cout << "My number is (" << phone1.areacode << ") " << phone1.exchange << "-" << phone1.number << endl;
    cout << "Your number is (" << phone2.areacode << ") " << phone2.exchange << "-" << phone2.number << endl;
    return 0;
}   