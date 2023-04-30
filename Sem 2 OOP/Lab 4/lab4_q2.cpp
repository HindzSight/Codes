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
        void assign();
        void deposit();
        void withdraw();
        void display();
        friend int choice();

}acc1;

void bank_account :: assign()
{
    cout<<"Enter the name of the depositor : "<<endl;
    cin>>acc1.Name_depositor;
    cout<<"Enter Account Number : "<<endl;
    cin>>Acc_No;
    cout<<"Enter account type : "<<endl;
    cin>>acc1.Acc_type;
    cout<<"Balance : $";
    cin>>acc1.Acc_balance;
}

void bank_account :: deposit()
{
	int money;
    cout<<"Enter amount to be deposited : $";
    cin>>money;
    acc1.Acc_balance=acc1.Acc_balance+money;
    cout<<"the updated balance is : $"<<acc1.Acc_balance;
}

void bank_account ::withdraw()
{
	int amt;
    cout<<"Enter amount to be withdrawn : $";
    cin>>amt;
    if(amt<acc1.Acc_balance)
    {
    acc1.Acc_balance=acc1.Acc_balance-amt;
    cout<<"the remaining balance is : $"<<acc1.Acc_balance;
	}
	else
	{
		cout<<"Low Account balance!"<<endl;
		exit(0);
	}

}

void bank_account :: display()
{
    cout<<"Name of the Account holder : "<<acc1.Name_depositor<<endl;
    cout<<"Balance available : $"<<acc1.Acc_balance;
}

int choice()
{
    int n;
    cout<<"What would you like to do ?"<<endl;
    cout<<"1.Your info"<<endl;
    cout<<"2.Deposit amount "<<endl;
    cout<<"3.Withdraw Amount"<<endl;
    cin>>n;
    switch (n)
    {
    case 1:
        acc1.display();
        break;
    case 2:
    	acc1.deposit();
    	break;
    case 3:
    	acc1.withdraw();
    	break;
    default:
        break;
    }
    
}

int main()
	{
    bank_account acc1;
    acc1.assign();
    choice();
    
}
