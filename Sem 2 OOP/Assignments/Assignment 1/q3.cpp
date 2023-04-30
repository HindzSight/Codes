#include <iostream>
using namespace std;
struct time
{
    int h, m, s;
} samay;
long hms_to_sec(int hours, int minutes, int seconds)
{
    int total_seconds;
    total_seconds = (hours * 3600) + (minutes * 60) + (seconds);
    cout << "Entered Time is equivalent to " << total_seconds << " seconds" << endl;
    return 0;
}

int main()
{
    char colon;
    cout << "Enter the time in HH:MM:SS : ";
    cin >> samay.h >> colon >> samay.m >> colon >> samay.s;
    hms_to_sec(samay.h, samay.m, samay.s);
    return 0;
}