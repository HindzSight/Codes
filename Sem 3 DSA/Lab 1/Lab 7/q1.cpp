#include<iostream>
using namespace std;

class Node
{
    public:
    int INFO;
    Node* NEXT;
    Node()
    {
        INFO=0;
        NEXT=NULL;
    }
    Node(int info)
    {
        INFO=info;
        NEXT=NULL;
    }
};

class LinkedList
{
    public:
    Node* head;
    LinkedList()
    {
        head=NULL;
    }

    Node* createLL()
    {
        head=NULL;
        return head;
    }

    void insertBegin(int info,Node** start)
    {
        Node *newnode= new Node(info);
        newnode->NEXT=*start;
        *start=newnode;
    }

    void insertEnd(int info,Node** start)
    {
        Node *newnode = new Node(info);
        Node *temp= *start;
        if (*start==NULL)
        {
            newnode->NEXT=NULL;
            *start=newnode;   
        }
        else{
        while(temp->NEXT!=NULL)
        {
            temp=temp->NEXT;
        }
        newnode->NEXT=temp->NEXT;
        temp->NEXT=newnode;
        }

    }

    void insertSpecific(int info,Node** start,int loc)
    {
        Node* newnode = new Node(info);
        Node* temp = new Node();
        temp=*start;
        if(temp==NULL)
        {
            newnode->NEXT=NULL;
            *start=newnode;
        }
        else if(loc=1)
        {
            newnode->NEXT=*start;
            *start=newnode;
        }
        else
        {
        for(int i=1;i<loc-1;i++)
            {
                temp=temp->NEXT;
            }
            newnode->NEXT=temp->NEXT;
            temp->NEXT=newnode;
        }

    }

    void printList(Node* start)
    {
        Node* temp = new Node();
        temp=start;
        cout<<"Linked List : "<<" ";
        while(temp!=NULL)
        {
            cout<<temp->INFO<<" -> ";
            temp=temp->NEXT;
        }
        cout<<"NULL"<<endl;
    }
};

int main()
{
    LinkedList *L1= new LinkedList();
    Node *start=L1->createLL();
    cout<<"Enter the number of elements to be inserted : ";
    int n;
    cin>>n;
    int v;
    for(int i=0;i<n;i++)
    {
        cout<<"ENTER VALUE:";
        cin>>v;
        L1->insertEnd(v,&start);
    }
    L1->printList(start);
    return 0;
}