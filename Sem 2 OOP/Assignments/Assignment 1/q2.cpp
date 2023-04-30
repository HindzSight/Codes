#include <iostream>
using namespace std;
struct month
{
    int day, month, year;
} date;

int main()
{
    char slash;
    cout << "Enter the date in DD/MM/YYYY:";
    cin >> date.day >> slash >> date.month >> slash >> date.year;
    cout << "\nEntered Date is : " << date.day << "/" << date.month << "/" << date.year;
    return 0;
}