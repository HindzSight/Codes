class invalidBalance extends Exception{
	public invalidBalance(String s){
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
}

public class q4{
	public static void main(String[] args) {
		try{
			BankAccount b = new BankAccount(1,"GeoHotz",10);
			System.out.println(b.toString());
		}catch(invalidBalance iB){
			System.out.println("Error Occured : " + iB.getMessage());
		}

	}
}