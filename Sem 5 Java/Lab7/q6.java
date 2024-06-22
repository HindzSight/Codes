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

class BankAccount{
	int accountNumber;
	String accountHolder;
	double balance;

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

}

public class q6{
	public static void main(String[] args) {
		try{
			BankAccount gH = new BankAccount(1,"GeoHotz",100);
			System.out.println(gH.toString());
			System.out.println(gH.deposit(100));
		}catch(invalidBalance iB){
			System.out.println("Error Occured : " + iB.getMessage());
		}catch(invalidDeposit iD){
			System.out.println("Error Occured : " + iD.getMessage());
		}
	}
}