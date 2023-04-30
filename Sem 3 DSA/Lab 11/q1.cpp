#include<iostream>
using namespace std;

class Node
{
public:
    Node* LC;
    int INFO;
    Node* RC;

    Node()
    {
        LC=NULL;
        RC=NULL;
        INFO=0;
    }
    Node(int data)
    {
        LC=NULL;
        RC=NULL;
        INFO=data;
    }

};
Node* LOC=NULL;
Node* PAR=NULL;

class BST
{
public:
    Node* root;
    BST()
    {
        root=NULL;
    }

    Node* createBST()
    {
        return root;
    }

    void search_bst(Node** head,int key)
    {
        LOC=NULL;
        PAR=NULL;
        if(*head==NULL)
            return;
        if((*head)->INFO==key)
        {
            LOC=*head;
            PAR=NULL;
            return;
        }

        Node* temp=*head;
        while(temp!=NULL)
        {
            PAR=temp;
            if(key<temp->INFO)
                temp=temp->LC;
            else
                temp=temp->RC;
            if(temp!=NULL && temp->INFO==key)
            {
                LOC=temp;
                break;
            }
        }
        if(LOC==NULL)
            return ;
    }

    void Insert_BST(Node** head,int key)
    {
        //Node *temp=*head;
        search_bst(head,key);
        if(LOC==NULL)
            return;
        Node* new_node=new Node(key);
        new_node->LC=NULL;
        new_node->RC=NULL;
        if(head==NULL)
            *head=new_node;
        else if(key<PAR->INFO)
            PAR->LC=new_node;
        else
            PAR->RC=new_node;
    }

    void inorder(Node** start)
    {
        cout<<"IN FUNCTION!"<<endl;
        Node* temp=*start;
        if(temp==NULL)
        {
            cout<<"NULL"<<endl;
            return;

        }
        else
        {
            inorder(&(temp->LC));
            cout<<temp->INFO<<" ";
            inorder(&(temp->RC));

        }
    }
    void preorder(Node** head)
    {
        Node* temp=*head;
        if(temp==NULL)
            return;
        else
        {
            preorder(&(temp->LC));
            preorder(&(temp->RC));
            cout<<temp->INFO<<" ";

        }
    }
    void postorder(Node** start)
    {
        Node* temp=*start;
        if(temp==NULL)
            return;
        else
        {
            cout<<temp->INFO<<" ";
            postorder(&(temp->LC));
            postorder(&(temp->RC));

        }
    }
        /*
        if(head!=NULL)
        {
            inorder(&(head->LC));
            cout<<(*head)->INFO;
            inorder(&(head->RC));
        }
        */

};


int main()
{
    BST *B=new BST();
    Node* head=B->createBST();
    B->Insert_BST(&head,6);
    B->Insert_BST(&head,2);
    B->Insert_BST(&head,1);
    B->Insert_BST(&head,8);
    B->Insert_BST(&head,5);
    B->Insert_BST(&head,3);
    B->Insert_BST(&head,4);
    B->Insert_BST(&head,10);
    B->inorder(&head);
    cout<<"ALL GOOD";
    return 0;
}
