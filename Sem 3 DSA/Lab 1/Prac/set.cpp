#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void RemoveDuplicate(int a[],int n)
{
    set<int> s1;
	for(int i=0;i<10;i++)
	{
		s1.insert(a[i]);
	}
	for(auto itr = s1.begin(); itr != s1.end(); itr++)
	cout<<(*itr)<<" ";
}
int main() {
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
	RemoveDuplicate(a,n);
	return 0;
}