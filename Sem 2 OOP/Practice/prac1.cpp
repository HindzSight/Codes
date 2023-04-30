#include <iostream>
#include <math.h>
using namespace std;
int distance(int, int);
class point
{
    int x, y;

public:
    point(int a, int b)
    {
        x = a;
        y = b;
    }
    void displaypoint();
    friend int distance(point, point);
};
void point :: displaypoint()
{
    cout<<"Point is ("<<x<<","<<y<<")"<<endl;
}

int distance(point p, point q)
{
    int d;
    d = sqrt((pow((p.x - q.x), 2)) + pow((p.y - q.y), 2));
    cout<< "The distance is " << d;
}

int main()
{
    point p(1, 1);
    p.displaypoint();
    point q(4, 5);
    q.displaypoint();
    distance(p,q);
    
}