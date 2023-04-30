#include<iostream>
using namespace std;
class Bag
{
    int count;
    int cart[25];
    public:
        void setEmpty();
        void display();
        void insert(int);
};

void Bag ::setEmpty()
{
    count=0;
}

void Bag ::display()
{
    if(count==0)
    cout<<"Bag is empty";
    else
    {
        for (int i = 0; i < count; i++)
        {
            cout<<cart[i]<<endl;
        }
        
    }    
}

void Bag ::insert(int weight)
{
    if (count<25)
    {
        for (int i = 0; i <count; i++)
            {
                cin>>cart[i];
                count++;
            }
    }
    else
    {
        cout<<"The Cart is Full"<<endl;
    }
}

int main()
{
    Bag sack;
    int weight;
    cout<<"Enter the weight of the product"<<endl;
    cin>>weight;
    sack.setEmpty();
    while(1)
    {
    sack.insert(weight);
    sack.display();
    exit(0);
    }
}