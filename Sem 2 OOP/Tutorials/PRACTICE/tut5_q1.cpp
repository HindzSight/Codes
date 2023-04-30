#include <iostream>
using namespace std;
class custdata
{
    int custno;
    int zipcode;

public:
    custdata(int, int);
    void display();
};

custdata::custdata(int c, int z)
{
    custno = c;
    zipcode = z;
}

void custdata::display()
{
    cout << "The Customer Number is : " << custno << endl;
    cout << "The zipcode is         : " << zipcode << endl;
}

class cities
{
    string cityname;
    string state;
    int zipcode;

public:
    cities(string, string, int);
    void display();
};

cities::cities(string c, string s, int z)
{
    cityname = c;
    state = s;
    zipcode = z;
}
void cities::display()
{
    cout << "The City Name is       : " << cityname << endl;
    cout << "The State is           : " << state << endl;
    cout << "The zipcode is         : " << zipcode << endl;
}

int main()
{
    custdata c(1, 452005);
    cities c1("Indore", "Madhya Pradesh", 452001);
    c.display();
    c1.display();
    return 0;
}