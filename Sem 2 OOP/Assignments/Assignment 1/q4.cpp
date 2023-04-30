#include <iostream>
#include<time.h>
using namespace std;
int flip()
{
    
    int i = rand() % 2;

    if (i == 0)
        return 0;

    else
        return 1;
}
int main()
{

    int toss;
    int heads = 0;
    int tails = 0;
    srand(time(0));
    for (toss = 1; toss <= 100; toss++)
    {
        cout<<endl<<flip();

        if (flip() == 0)
            heads++;
        else
            tails++;
    }
    cout << "\nHeads was flipped " << heads << " times" << endl;
    cout << "Tails was flipped " << tails << " times" << endl;
    return 0;
}
