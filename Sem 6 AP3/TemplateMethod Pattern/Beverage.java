abstract class Beverage{
    protected void pour(int qty){
        System.out.println("Add " + qty + " ml of Beverage");
    }
    
    abstract void addCondiment();
    
    private void stir(){
        System.out.println("Stir of 30 seconds");
    }
    
    private void serve(){
        System.out.println("Serve with manners");
    }
    
    final void templateMethod(int qty){
        pour(qty);
        addCondiment();
        if(hook()) stir();
        serve();
    }
    
    boolean hook(){
        return true;
    }
    
}