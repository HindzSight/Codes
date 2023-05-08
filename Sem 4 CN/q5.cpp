#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    // string ip;
    int n;
    int giv[4] = {0};
    char slash = '/';
    cout << "Enter IP address (x.y.z.t/n): ";
    cin >> giv[0] >> slash >> giv[1] >> slash >> giv[2] >> slash >> giv[3] >> slash >> n;
    int arr[4] = {0};
    int oct = n / 8;
    int rem = n % 8;
    for (int i = 0; i < 4; i++)
    {
        arr[i] = 255;
    }
    int val = (32 - n);
    int num = val / 8;
    for (int i = 1; i <= num; i++)
    {
        arr[4 - i] = 0;
    }
    int p = val % 8;
    int zero = 0;
    if (p != 0)
    {
        for (int o = 0; o < p; o++)
        {
            zero += pow(2, o);
        }
        int newval = 255 - zero;
        arr[3 - num] = newval;
    }

    cout << endl;
    int num_add = pow(2, val);
    cout << "Number of address in the block : " << num_add << endl;
    int first_add[4] = {0};
    for (int i = 0; i < 4; i++)
    {
        first_add[i] = arr[i] & giv[i];
    }
    cout << "\nFirst Address : ";
    for (int i = 0; i < 4; i++)
    {
        cout << first_add[i];
        if (i != 3)
            cout << ".";
    }

    int last_add[4] = {0};
    for (int i = 0; i < 4; i++)
    {
        arr[i] = 255 - arr[i];
    }
    for (int i = 0; i < 4; i++)
    {
        last_add[i] = arr[i] | giv[i];
    }
    cout << "\nLast Address : ";
    for (int i = 0; i < 4; i++)
    {
        cout << last_add[i];
        if (i != 3)
            cout << ".";
    }
    return 0;
}
