class Singleton
{
  private static Singleton uniqueInstance = null;
  public static int count = 0;

  private Singleton ()
  {
      count++;
  }

  public static Singleton getInstance (){
    if(uniqueInstance == null){
        uniqueInstance = new Singleton();
    }
	return uniqueInstance;
  }

}
