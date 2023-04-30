#include<iostream>
using namespace std;
class Integer
{
    int x;
    public:
        Integer(int a=6):x(a){}
        int operator !();
};
    
int Integer :: operator!()
{
    if(x == 0)
          return 1;
    int i = x, fact = 1;
    while (x / i != x) {
        fact = fact * i;
        i--;
    }
    return fact;

}

int main()
{
    Integer i1(5);
    int fact ;
    fact=!i1;
    cout<<"The factorial is : "<<fact;
    return 0;
}