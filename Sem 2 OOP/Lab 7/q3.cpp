#include<iostream>
using namespace std;
class Mother
{
    protected:
        void display()
        {
            cout<<"Hello MUM"<<endl;
        }
};

class Daughter : protected Mother
{
    public:
        void display()
        {
            Mother::display();
            cout<<"Hi Daughter"<<endl;
        }
};

int main()
{
    Daughter D1;
    D1.display();
}