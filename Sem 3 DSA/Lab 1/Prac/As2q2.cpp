#include<iostream>
using namespace std;

class Node
{
    public:
    char INFO;
    Node* NEXT;
    Node()
    {
        INFO='0';
        NEXT=NULL;
    }
    Node(char info)
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

    void insertBegin(char info,Node** start)
    {
        Node *newnode= new Node(info);
        newnode->NEXT=*start;
        *start=newnode;
    }

    void insertEnd(char info,Node** start)
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

    void insertSpecific(char info,Node** start,int loc)
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
            cout<<temp->INFO    ;
            temp=temp->NEXT;
        }
        cout<<endl;
    }

    void translate(Node** start)
    {
        Node* temp = new Node();
        temp=*start;
        while(temp!=NULL)
        {
            if(temp->INFO == '*' || temp->INFO== '/')
            {
                if(temp->NEXT->INFO=='*' || temp->NEXT->INFO=='/')
                {
                    temp->INFO='\0'; // Else delete the node here !
                    temp->NEXT->NEXT->INFO-=32;
                }
                else
                {
                    temp->INFO=' ';
                }
            }
            temp=temp->NEXT;
        }


    }
};

int main()
{
    LinkedList *L1= new LinkedList();
    Node *start=L1->createLL();
    L1->insertBegin('A',&start);
    L1->insertEnd('n',&start);
    L1->insertEnd('*',&start);
    L1->insertEnd('/',&start);
    L1->insertEnd('a',&start);
    L1->insertEnd('p',&start);
    L1->insertEnd('p',&start);
    L1->insertEnd('l',&start);
    L1->insertEnd('e',&start);
    L1->insertEnd('*',&start);
    L1->insertEnd('a',&start);
    L1->insertEnd('/',&start);
    L1->insertEnd('d',&start);
    L1->insertEnd('a',&start);
    L1->insertEnd('y',&start);
    L1->insertEnd('*',&start);
    L1->insertEnd('*',&start);
    L1->insertEnd('k',&start);
    L1->insertEnd('e',&start);
    L1->insertEnd('e',&start);
    L1->insertEnd('p',&start);  
    L1->insertEnd('s',&start);
    L1->insertEnd('/',&start);
    L1->insertEnd('*',&start);
    L1->insertEnd('a',&start);
    L1->insertEnd('/',&start);
    L1->insertEnd('/',&start);
    L1->insertEnd('d',&start);
    L1->insertEnd('o',&start);
    L1->insertEnd('c',&start);
    L1->insertEnd('t',&start);
    L1->insertEnd('o',&start);
    L1->insertEnd('r',&start);
    L1->insertEnd('*',&start);
    L1->insertEnd('A',&start);
    L1->insertEnd('w',&start);
    L1->insertEnd('a',&start);
    L1->insertEnd('y',&start);

    L1->printList(start);

    L1->translate(&start);

    L1->printList(start);
    return 0;
}

    /*L1->insertBegin(2,&start);
    L1->insertBegin(160,&start);
    L1->printList(start);
    cout<<endl;
    L1->insertEnd(69,&start);
    */