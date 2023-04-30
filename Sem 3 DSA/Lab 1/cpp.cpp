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
class STACK
{
  public:
      Node* start;
      STACK()
      {
          start=NULL;
      }
      Node* CreateS()
      {
          return start;
      }

      void push(Node** top,int data)
      {
          Node *new_node= new Node(data);
          if(new_node==NULL)
          {
              cout<<"STACK OVERFLOW"<<endl;
          }
          else
            {


          if(*top==NULL)
          {
              *top=new_node;
              new_node->NEXT=NULL;
          }
          else
          {
              new_node->NEXT=*top;
              *top=new_node;
          }
            }

      }

      void pop(Node** top)
      {
          Node* temp;
          temp=*top;

          if(temp==NULL)
          {
              cout<<"STACK UNDERFLOW"<<endl;
          }
          else
          {
              int p;
              p=temp->info;
              cout<<"Popped Value : "<<p<<endl;
              *top=temp->NEXT;
              delete temp;
          }
      }

      void display(Node** top)
      {
          Node* temp=*top;
          cout<<"STACK : "<<endl;
          while(temp!=NULL)
          {
              cout<<temp->info<<endl;
              temp=temp->NEXT;
          }
          cout<<endl;
      }
};

int main()
{
    STACK *s1 = new STACK();
    Node* top=s1->CreateS();
    int choice;
    int data;
    while(1)
        {
            cout<<"***Stack Menu***"<<endl;
            cout<<"1.push()"<<endl;
            cout<<"2.pop()"<<endl;
            cout<<"3.display()"<<endl;
            cout<<"4.Exit"<<endl;
            cout<<"Enter Choice(1-4):";
            cin>>choice;
            cout<<endl;
            switch(choice)
            {
            case 1:
                cout<<"Enter Element to push : ";
                cin>>data;
                s1->push(&top,data);
                cout<<endl;
                break;
            case 2:
                s1->pop(&top);
                break;
            case 3:
                s1->display(&top);
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
