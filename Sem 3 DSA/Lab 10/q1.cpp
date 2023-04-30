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
            cout<<"QUEUE IS FULL!";

        int temp=frnt;
        int i=0;
        while(temp<=rear)
        {
            arr[i]=arr[temp];
            temp+=1;
            i+=1;
        }
        rear=rear-frnt+1;
        frnt=0;
        }
        else
            rear+=1;
        arr[rear]=value;
    }
    void Dequeue()
    {
        int item=arr[frnt];
        if(rear==-1 && frnt==-1)
        {
            cout<<"EMPTY QUEUE"<<endl;
        }
        else if(frnt==rear)
        {
            frnt=-1;
            rear=-1;
            cout<<"DELETED VALUE:"<<item;
        }
        else
        {
            frnt++;
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
        else{
        cout<<"Queue : ";
        for(int i=frnt;i<=rear;i++)
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
