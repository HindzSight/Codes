#include<iostream>
using namespace std;

class STACK
{
public:
    int top;
    int arr[5];
    STACK()
    {
        top=-1;
    }
    bool isEmpty()
    {
        if(top<4)
            return true;
        else
            return false;
    }

    void push(int val)
    {
        if(isEmpty())
        {
            arr[top+1]=val;
            top=top+1;
        }
        else
            cout<<"Stack Overflow!"<<endl;
    }
    void pop()
    {
        int p=0;
        p=arr[top];
        if(top==-1)
            cout<<"Stack Underflow!"<<endl;
        else
            {
                top=top-1;
                cout<<"Popped Value : "<<p<<endl;
            }
    }

    void display()
    {
        cout<<"STACK : "<<endl;
        for(int i=top;i>=0;i--)
        {
            cout<<arr[i]<<endl;
        }
        cout<<endl;
    }
};

int main()
{
    STACK s1;
    int choice;
    int data;
    while(1)
        {
            cout<<"***Stack Menu**"<<endl;
            cout<<"1.push()"<<endl;
            cout<<"2.pop()"<<endl;
            cout<<"3.display()"<<endl;
            cout<<"4.Exit"<<endl;
            cout<<"Enter Choice(1-4):";
            cin>>choice;
            switch(choice)
            {
            case 1:
                cout<<"Enter Element to push : ";
                cin>>data;
                s1.push(data);
                cout<<endl;
                break;
            case 2:
                s1.pop();
                break;
            case 3:
                s1.display();
                break;
            case 4:
                break;
            default:
                cout<<"Enter Valid Choice"<<endl;
                break;
            }
            if(choice==4)
                break;
        }
    return 0;
}
