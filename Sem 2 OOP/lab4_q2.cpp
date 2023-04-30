#include<iostream>
using namespace std;
int choice();
class bank_account 
{
    string Name_depositor;
    int Acc_No;
    string Acc_type;
    int Acc_balance;

    public:
        void assign(string, int,string ,int);
        void deposit(int);
        void withdraw(int);
        void display();

};

void bank_account :: assign(string Name_depositor, int Acc_No,string Acc_typ,int Acc_balance)
{
    cout<<"Enter the name of the depositor : "<<endl;
    cin>>Name_depositor;
    cout<<"Enter Account Number : "<<endl;
    cin>>Acc_no;
    cout<<"Enter account type : "<<endl;
    cin>>Acc_type;
    cout<<"Balance : ";
    cin>>Acc_balance;
}

void bank_account :: deposit(int money)
{
    cout<<"Enter amount to be deposited : $";
    cin>>money;
    Acc_balance=Acc_balance+money;
}

void bank_account ::withdraw(int amt)
{
    cout<<"Enter amount to be withdrawn : $";
    cin>>amt;
    Acc_balance=Acc_balance-amt;
}

void bank_account :: display()
{
    cout<<"Name of the Account holder : "<<Name_depositor<<endl;
    cout<<"Balance available : $"<<Acc_balance;
}

int choice()
{
    int n;
    cout<<"What would you like to do"<<endl;
    cout<<"1.See Balance"<<endl;
    cout<<"2.Deposit amount "<<endl;
    cout<<"3.Withdraw Amount"<<endl;
    cin>>n;
    switch (n)
    {
    case 1:
        
        break;
    
    default:
        break;
    }
    
}

int main()
{
    
}