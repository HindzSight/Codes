#include<iostream>
#include<bits/stdc++.h>
#include<string>

using namespace std;

int main()
{
	string s = "110101111101011111101011111110";
	cout<<"Before Stuffing : "<<s<<endl;
	int pos =0;
	string b_s = "0";
	int count = 0;
	//Bit-Stuff
	for (int i=0;i<s.length();i++)
	{
		if(s[i] == '1' )
		{
			count++;
			if(count == 5)
			{
				s.insert(i+1,b_s);
			}
		}
		else
		{
			count = 0;
		}
	} 
	cout<<"\nAfter Stuffing  : "<<s<<endl;
	string de_s = "";
	count =0;
	//De-stuff
	for(int i=0;i<s.length();i++)
	{
		de_s+=s[i];
		if(s[i] == '1')
		{
			count++;
			if(count == 5)
				{
					i+=1;
				}
		}
		else
		{
			count = 0;
		}
	}

	cout<<"\nDestuff         : "<<de_s<<endl;
	
	
	return 0;
}
