#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
void correct();
void wrong();
int next_question()
{   
    int static count=0;
    srand(time(0));
    int m, n, ans;
    m = rand() % (10 - 1 + 1) + 1; // (max-min+1)+min
    n = rand() % (10 - 1 + 1) + 1;

    cout << "How much is " << m << " times " << n << "? " << endl;
    cin >> ans;
    if (ans == (m * n))
        {          
            correct();

            next_question();       
        }
    else
        {
            wrong();
            count++;
            next_question();
        }
    return 0;
}

void correct()
{
    int n;
    srand(time(0));
    n = rand() % 3; 
    switch(n)
    {
    case 0:
        cout << "Good Work XD\n";
        break;
    case 1:
        cout << "Very good!\n";
        break;
    case 2:
        cout << "Excellent!\n"; 
        break;
    case 3:
        cout << "Keep up the good work!\n";
        break;
    default:
        cout << "GGWP";
        break;
    }
    
}

void wrong()
{
    int n;
    srand(time(0));
    n = rand() % 3; 
    switch(n)
    {
    case 0:
        cout << "No please Try again\n";
        break;
    case 1:
        cout << "Wrong , try again\n";
        break;
    case 2:
        cout << "KAL\n"; 
        break;
    case 3:
        cout << "NHK\n";
        break;
    default:
        cout << "NT";
        break;
    }

}

int main()
{   
        next_question();

    return 0;
}
