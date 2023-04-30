#include<iostream>
using namespace std;
int issparse(int m,int n,int *a)
{
    int ans=0;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(*((a+n*i)+j)!=0)
                ans++;
        }
    }
    if(3*(ans+1)<m*n)
        return ans;
    else
        return -1;
}

void sparse(int m,int n,int r, int *a)
{
    int noi=0,noj=0;
    int ans[r+1][3];
    ans[0][0]=m;
    ans[0][1]=n;
    ans[0][2]=r;
    int i1=1;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(*((a+n*i)+j)!=0)
            {
                {
                        ans[i1][0]=i;
                        ans[i1][1]=j;
                        ans[i1][2]=*((a+n*i)+j);
                }
                i1++;
            }
        }
    }
    cout<<"\nThe Sparse Matrix is :"<<endl;
    for(int i2=0;i2<r+1;i2++)
    {
        for(int j2=0;j2<3;j2++)
        {
            cout<<ans[i2][j2]<<" ";
        }
        cout<<"\n";
    }
}

int main()
{
    int m,n;
    cout<<"Enter the size m x n of the matrix: ";
    cin>>m>>n;
    int a[m][n];
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        cin>>a[i][j];
    }
    int value=issparse(m,n,&a[0][0]);
    if(value!=-1)
    {
        sparse(m,n,value,&a[0][0]);
        cout<<"\nSpace Saved is "<<4*((m*n)-(3*(value+1)))<<" bytes";
    }
    else
    cout<<"Sparse Matrix Not required!";
}
