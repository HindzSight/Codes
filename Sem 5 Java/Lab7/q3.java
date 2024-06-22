class BookUnavailableException extends Exception{
    public BookUnavailableException(String s)
    {
        super(s);
    }
}

class Book{
    String Title="Mien Kampf";
    String Author="Adolf Hitler";
    int AvailableCopies=4;
    
    public int CopiesWanted(int a)
            throws BookUnavailableException{
                if(a>AvailableCopies)
                {
                    throw new BookUnavailableException("Sold Out !Check Again Tomorrow!");
                }
                System.out.println("Found the last one!");
                
                return AvailableCopies;
            }
            
}
public class q3
{
	public static void main(String[] args) {
		Book b=new Book();
		try{
		    int booksWanted=34;
		    System.out.println(b.CopiesWanted(booksWanted));
		}
		catch(BookUnavailableException e)
		{
		    System.out.println("Error:"+ e.getMessage());
		}
	}
}
