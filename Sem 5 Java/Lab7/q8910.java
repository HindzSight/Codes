import java.util.*;

class invalidBalance extends Exception{
	public invalidBalance(String s){
		super(s);
	}
}

class invalidDeposit extends Exception{
	public invalidDeposit(String s){
		super(s);
	}
}

class InsufficientFundsException extends Exception{
	public InsufficientFundsException(String s){
		super(s);
	}
}

class transferException extends Exception{
	public transferException(String s){
		super(s);
	}
}

class BankAccount{
	int accountNumber;
	String accountHolder;
	double balance;
	public BankAccount(){}

	public BankAccount(int accountNumber, String accountHolder, double balance) throws invalidBalance{
		this.accountNumber = accountNumber;
		this.accountHolder = accountHolder;
		if(balance < 0){
			throw new invalidBalance("Balance cant be negative!");
		}else{
			this.balance = balance;
		}
	}

	public String toString(){
		return ("Account Info : "+"\n" + "A/C # : "+this.accountNumber +"\nA/C Holder Name : " + this.accountHolder + "\nA/C Balance : $"+this.balance+"\n");
	}

	public String deposit(double amount) throws invalidDeposit{
		if(amount <= 0){
			throw new invalidDeposit("Deposit Amount should be positive(+ $AMT) !\n");
		}else{
			this.balance = this.balance + amount;
		}
		return ("Deposit Succesful!\nNew Balance : $"+this.balance +"\n");
	}

	public String withdraw(double amount) throws InsufficientFundsException{
		if(amount > this.balance){
			throw new InsufficientFundsException("Insufficient Funds to withdraw!");
		}else if(amount <= 0){
			throw new InsufficientFundsException("Withdrawl Amount must be positive!");
		}else{
			this.balance = this.balance - amount;
		}
		return ("Withdraw Succesful!\nNew Balance : $"+this.balance +"\n");
	}

}

class accountException extends Exception{
	public accountException(String s){
		super(s);
	}
}

class Bank{
	private List<BankAccount> acLedger = new ArrayList<>();
	public Bank(){
		System.out.println("Bank Opened!");
	}

	public void addAccount(BankAccount account){
		if(!acLedger.contains(account)){
			acLedger.add(account);
		}else{
			System.out.println("Account already Exists!");
		}
	}

	public void getAccount(BankAccount account) throws accountException{
		if(!acLedger.contains(account)){
			throw new accountException("Account Does not exist");
		}else{
			System.out.println(account.toString());
		}
	}

	public void removeAccount(BankAccount account) throws accountException{
		if(!acLedger.contains(account)){
			throw new accountException("Account does not exist in Bank Ledger!");
		}else{
			acLedger.remove(account);
			System.out.println("Account removed Successfully!");
		}
	}

	public void transfer(int fromAccountNumber, int toAccountNumber, double amount) throws transferException{
		boolean fA = false;
		boolean tA = false;
		BankAccount fAb = new BankAccount();
		BankAccount tAb = new BankAccount();
		for(BankAccount ac : acLedger){
			if(ac.accountNumber == fromAccountNumber){
				fA = true;
				fAb = ac;
			}else if(ac.accountNumber == toAccountNumber){
				tA = true;
				tAb = ac;
			}
		}
		if(fA && tA){
			if(fAb.balance < amount){
				throw new transferException("Sender does not have enough Balance!");
			}else{
				fAb.balance = fAb.balance - amount;
				tAb.balance = tAb.balance + amount;
				System.out.println("Transfer of Amount $"+amount+" Successful!");
			}
		}else{
			throw new transferException("Enter Valid Account number!");
		}
	}

}



public class q8910{
	public static void main(String[] args) {
		try{


			BankAccount gH = new BankAccount(1,"GeoHotz",100);
			System.out.println(gH.toString());
			System.out.println(gH.deposit(100));
			System.out.println(gH.withdraw(29.89));

			BankAccount sM = new BankAccount(11,"TBSM",1000000);
			System.out.println(sM.toString());



			Bank SBI = new Bank();
			SBI.addAccount(gH);
			// SBI.getAccount(gH);
			// SBI.removeAccount(gH);
			// SBI.getAccount(sM);

			SBI.addAccount(sM);
			SBI.transfer(1,11,10);
			SBI.getAccount(gH);
			SBI.getAccount(sM);



		}catch(invalidBalance iB){
			System.out.println("Error Occured : " + iB.getMessage());
		}catch(invalidDeposit iD){
			System.out.println("Error Occured : " + iD.getMessage());
		}catch(InsufficientFundsException iFE){
			System.out.println("Error Occured : " + iFE.getMessage());
		}catch(accountException aE){
			System.out.println("Error Occured : " + aE.getMessage());
		}catch(transferException tE){
			System.out.println("Error Occured : " + tE.getMessage());
		}
	}
}