#include<iostream>
using namespace std;

class qarr
{
public:
    int arr[5];
    int frnt;
    int rear;

    qarr()
    {
        frnt=-1;
        rear=-1;
    }

    void Enqueue(int value)
    {
        if(frnt==-1 && rear ==-1)
        {
            frnt=0;
            rear=0;
        }
        else if (rear==4)
        {
            if(frnt==0)
            {
                cout<<"QUEUE IS FULL!"<<endl;
                return;
            }
            else
            rear=0;
        }
        else if((rear+1)==(frnt))
        {
            cout<<"QUEUE IS FULL!"<<endl;
            return;
        }
        else
            rear+=1;
        arr[rear]=value;
    }

    void Dequeue()
    {
        if(rear==-1 || frnt==-1)
        {
            cout<<"EMPTY QUEUE"<<endl;
            return;
        }
        int item=arr[frnt];
        if(frnt==rear)
        {
            frnt=-1;
            rear=-1;
            cout<<"DELETED VALUE:"<<item;
        }
        else if(frnt==4)
        {
            frnt=0;
            cout<<"DELETED VALUE:"<<item;
        }
        else
        {
            frnt=frnt+1;
            cout<<"DELETED VALUE:"<<item;
        }
    }

    void disfrnt()
    {
        if(frnt==-1 && rear==-1)
        {
            cout<<"EMPTY QUEUE"<<endl;
        }
        else
            cout<<"Front : "<<arr[frnt];
    }

    void display()
    {
        if(frnt==-1 && rear==-1)
        {
            cout<<"EMPTY QUEUE"<<endl;
        }
        else if(frnt<=rear)
        {
            for(int i=frnt;i<=rear;i++)
            {
                cout<<arr[i]<<" ";
            }
        }
        else
        {
            for(int i=frnt;i<5;i++)
            {
                cout<<arr[i]<<" ";
            }
            for(int i=0;i<=rear;i++)
            {
                cout<<arr[i]<<" ";
            }
        }

    }
};

int main()
{
    qarr q1;
    int choice;
    int data;
    while(1)
        {
            cout<<endl<<"***Queue Menu**"<<endl;
            cout<<"1.enqueue()"<<endl;
            cout<<"2.dequeue()"<<endl;
            cout<<"3.displayfront()"<<endl;
            cout<<"4.displayall()"<<endl;
            cout<<"5.exit()"<<endl;
            cout<<"Enter Choice(1-5):";
            cin>>choice;
            switch(choice)
            {
            case 1:
                cout<<"Enter Element to enqueue : ";
                cin>>data;
                q1.Enqueue(data);
                cout<<endl;
                break;
            case 2:
                q1.Dequeue();
                break;
            case 3:
                q1.disfrnt();
                break;
            case 4:
                q1.display();
                break;
            case 5:
                break;
            default:
                cout<<"Enter Valid Choice"<<endl;
                break;
            }
            if(choice==5)
                break;
        }
    return 0;
}

