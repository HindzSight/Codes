public class Main
{
	public static void main(String[] args) {
		System.out.println("------------------------STRATEGY DESIGN PATTERN------------------------");
    
    	
    	Duck duck = new RHD();
    	duck.display();
    	duck.performQuack();
    	duck.performFly();
    	duck.swim();

        System.out.println();
    	
    	duck = new WD();
    	duck.display();
    	duck.performQuack();
    	duck.performFly();
    	duck.swim();
    	
    	System.out.println();
    	
    	duck = new RD();
    	duck.display();
    	duck.performQuack();
    	duck.performFly();
    	duck.swim();
    	
    	System.out.println();
    	
    	duck = new GID();
    	duck.display();
    	duck.performQuack();
    	duck.performFly();
    	duck.swim();
    	
    	Flyable flyable = new NoFly();
    	
    	duck.setFlyable(flyable);
    	duck.performFly();
	
	}
}
