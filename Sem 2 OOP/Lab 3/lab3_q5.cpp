#include<iostream>
using namespace std;
int movie(char mname[25],int mtime=90)
{
    cout<<"the name of the movie is "<<mname<<"run time "<<mtime<<endl;
    cout<<"the name of the movie is "<<mname<<"run time "<<mtime;
    return 0;
}
void main()
{
    movie("JJK 0");
    movie("JJK 0",156);
}