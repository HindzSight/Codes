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
      bool finder(Node** top,Node** Tail,int pro)
      {
          Node *temp ;
          temp=*top;
          if(*top==NULL)
          {
              return false;
          }
          else
          {
              while(temp!=NULL)
              {
                if((temp->info)==pro)
                {
                    return true;
                }
                temp=temp->NEXT;
              }
              return false;
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
          cout<<"Frames : ";
          while(temp!=NULL)
          {
              cout<<temp->info<<" ";
              temp=temp->NEXT;
          }

          cout<<endl;
          }
      }
      void fifo(Node** top,Node** Tail,string s,int frames)
      {
          int i=0;
          int n = s.length();
          int hit = 0;
          Node *temp ;
          while(i<n)
          {
              temp=*top;
              Node *temp1;
              temp1=*top;
              int val = 0;
              while(temp!=NULL)
              {
                  val++;
                  temp=temp->NEXT;
              }
              int current_value=int(s[i]) - 48;
              if(val == frames)
              {
                  if(finder(top,Tail,current_value))
                  {
                      hit=hit+1;
                      cout<<"Frames : HIT!"<<endl;
                      //display(top);
                  }
                  else
                  {
                      Dequeue(top,Tail);
                      Enqueue(top,Tail,current_value);
                      display(top);
                  }
                  i++;
              }
              else
              {
                  Enqueue(top,Tail,current_value);
                  display(top);
                  i++;
              }
          }
          cout<<"Page Faults : "<<(n-hit)<<endl;
      }
};

int main()
{
    QUEUE *q1=new QUEUE();
    Node* head;
    Node* tail;
    head=q1->sCreateQ();
    tail=q1->tCreateQ();

    int n;
    cout<<"FIFO Page Replacement Algorithm : "<<endl;
    string ref_str = "";
    cout<<"\nEnter the reference string without spaces : ";
    cin>>ref_str;
    cout<<"Enter the frame number : ";
    cin>>n;
    q1->fifo(&head,&tail,ref_str,n);
    return 0;
}

//ref_str : 70120304230321201701
//ref_str : 72312534677105462301