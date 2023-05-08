#include<iostream>
#include<bits/stdc++.h>
#include<string>
#include <stdlib.h>

using namespace std;

bool validate(string s)
{
    int val = 0;
    string o[4]={};
    int i=0;
    int index =0;
    while(s[i]!='\0')
      {
          if(s[i]=='.')
          {
              if(index==3){
                return false;
              }
            index+=1;
          }
          else if(s[i]>=48 && s[i]<=57)
          {
              o[index]+=s[i];
          }
          else{
            return false;
          }
          i++;
      }
      if(index!=3){
        return false;
      }
      for(int j=0;j<4;j++)
      {
          if(o[j]=="") return false;
          if(o[j][0]=='0' && o[j].size()>1) return false;
          int temp = stoi(o[j]);
          if( temp >=256 || temp<0)
            return false;
        else
        {
            val = stoi(o[0]);
        }
      }
      switch(val)
      {
      case 0 ... 127:
          {
            cout<<"A"<<endl;
            break;
          }
      case 128 ... 191:
        {
            cout<<"B"<<endl;
            break;
        }
      case 192 ... 223:
        {
            cout<<"C"<<endl;
            break;
        }
      case 224 ... 239:
        {
            cout<<"D"<<endl;
            break;
        }
      case 240 ... 255:
        {
            cout<<"E"<<endl;
            break;
        }
      }
      return true;

}

int main()
{
    string ip;
    cout<<"Enter the IP Address : ";
    getline(cin,ip);
    validate(ip);
    return 0;
}
