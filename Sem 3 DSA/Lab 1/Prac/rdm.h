#include<iostream>
#include<cstdlib>
#include<time.h>
using namespace std;

int* rdm(int n)
{
    srand(time(0));
    int* arr= new int[n];
    for(int i=0;i<n;i++)
    {
        arr[i]=rand() % 100;
    }
    return arr;
}