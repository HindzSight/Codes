#include<iostream>
using namespace std;

class Node
{
public:
    Node* NEXT;
    int info;

    Node()
    {
        NEXT=NULL;
        info=0;
    }

    Node(int val)
    {
        NEXT=NULL;
        info=val;
    }

};
class QUEUE
{
  public:
      Node* start;
      Node* tail;
      QUEUE()
      {
          start=NULL;
          tail=NULL;
      }
      Node* sCreateQ()
      {
          return start;
      }
      Node* tCreateQ()
      {
          return tail;
      }

      void Enqueue(Node** top,Node** Tail,int data)
      {
          Node *new_node= new Node(data);
          if(new_node==NULL)
          {
              cout<<"------QUEUE OVERFLOW------"<<endl;
          }
          else
        {


          if(*top==NULL && *Tail==NULL)
          {
              *top=new_node;
              *Tail=new_node;
              new_node->NEXT=NULL;
          }
          else
          {
              (*Tail)->NEXT=new_node;
              *Tail=new_node;
          }
        }

      }

      void Dequeue(Node** top,Node** Tail)
      {
          if(*top==NULL)
            cout<<"------QUEUE UNDERFLOW!------"<<endl;
          Node *temp;
          temp=*top;
          if (*top==*Tail)
          {
              *top=NULL;
              *Tail=NULL;
              delete temp;
          }
          else
          {
              *top=temp->NEXT;
              delete temp;
          }

      }

      void disfrnt(Node** top)
      {
          if(*top==NULL)
            cout<<"------EMPTY QUEUE------"<<endl;
          else
            cout<<(*top)->info<<endl;
      }

      void display(Node** top)
      {
          Node* temp=*top;
          if(*top==NULL)
            cout<<"------EMPTY QUEUE!------"<<endl;
          else
          {
          cout<<"QUEUE : "<<endl;
          while(temp!=NULL)
          {
              cout<<temp->info<<" ";
              temp=temp->NEXT;
          }

          cout<<endl;
          }
      }
};

int main()
{
    QUEUE *q1=new QUEUE();
    Node* head;
    Node* tail;
    head=q1->sCreateQ();
    tail=q1->tCreateQ();
    int choice;
    int data;
    while(1)
        {
            cout<<endl<<"********Queue Menu********"<<endl;
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
                q1->Enqueue(&head,&tail,data);
                cout<<endl;
                break;
            case 2:
                q1->Dequeue(&head,&tail);
                break;
            case 3:
                q1->disfrnt(&head);
                break;
            case 4:
                q1->display(&head);
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

