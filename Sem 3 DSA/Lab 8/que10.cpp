#include <iostream>
using namespace std;

class node{
    public:
    int info;
    node * next;
    node * prev;

};

void printLL(node * start){
    cout<<"-------------Linked List-----------"<<endl;
    node*temp=start;
    while(temp!=NULL){
        cout<<temp->info<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

void insert_at_beginning (node ** start, int val){


    node * new_node=new node();
    new_node->info=val;

    new_node->next=*start;

    new_node->prev=NULL;
    *start=new_node;
    return;


}

void insert_at_position(node * start, int info, int pos){

    if(start==NULL){
        cout<<"Invalid Position, list is empty"<<endl;
    }
    node * temp=start;
    for(int i=1;i<=pos-2;i++){

        if(temp==NULL){
            cout<<"Invalid Position, position is out of range"<<endl;
            return;
        }
        temp=temp->next;

    }
    node * new_node=new node();
    node*temp2=temp->next;
    new_node->info=info;
    new_node->prev=temp;
    new_node->next=temp->next;
    temp->next=new_node;
    temp2->prev=new_node;



}


int main(){

    int n;
    cout<<"Enter the number of operation you want to perform"<<endl;
    cin>>n;

    node * head=NULL;
    for(int i=0;i<n;i++){

        int choice;
        cout<<"Enter 1 to insert at start"<<endl;
        cout<<"Enter 2 to insert at any position"<<endl;
        cout<<"Enter 3 to insert at end"<<endl;
        cin>>choice;
        switch(choice){
        case 1:
            int info;
            cout<<"Enter the value"<<endl;
            cin>>info;

            insert_at_beginning(&head,info);
            printLL(head);
            break;
        case 2:

            cout<<"Enter the value"<<endl;
            cin>>info;
            int pos;
            cout<<"Enter position"<<endl;
            cin>>pos;
            insert_at_position(head,info,pos);
            printLL(head);
            break;

        }

    }

}









