#include <iostream>
#include <string>
using namespace std;
class Landline
{
protected:
    string sub_name;
    long sub_number;

public:
    void call(long sub_number)
    {
        cout << "Calling on " << sub_number << endl;
    }
    void recieve()
    {
        cout << "Call recieved" << endl;
    }
};
class Mobile : public Landline
{

    string name[100];
    long number[100];
    long ld[20];

public:
    void phonebook(int n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << "Enter name and number to be added" << endl;
            cin >> name[i];
            cin >> number[i];
        }
    }
    void call(string)
    {
        cout << "Enter the name to be called " << endl;
        cin >> sub_name;
        for (int j = 0; j < 100; j++)
        {
            if (sub_name == name[j])
            {
                Landline::call(number[j]);
                lastdialed(number[j]);
            }
        }
    }
    static int i;
    void lastdialed(long n)
    {

        if (i < 20)
        {
            ld[i] = n;
            i++;
        }
        if (i == 20)
        {
            ld[0] == n;
        }
    }
    void callfromdialed()
    {
        cout << "The last dialed numbers are " << endl;
        for (int j = 0; j < i; j++)
        {
            cout << ld[j] << endl;
        }
        long n;
        cout << "Enter the number to be called" << endl;
        cin >> n;
        Landline::call(n);
    }
};
int Mobile::i = 0;

int main()

{
    string s;
    Mobile m;
    int n;
    cout << "Enter the number of contacts to be added" << endl;
    cin >> n;

    m.phonebook(n);
    while (1)
    {
        int a;
        cout << "enter 1 to call" << endl;

        cin >> a;
        if (a == 1)
        {
            m.call(s);
        }
        else
        {
            break;
        }
    }

    m.callfromdialed();
    return 0;
}