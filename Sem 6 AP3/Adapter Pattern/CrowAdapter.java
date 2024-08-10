public class CrowAdapter implements Swan{
    private Crow crow;
    public CrowAdapter(Crow crow){
        this.crow = crow;
    }
    
    public void eat(){
        crow.eat();
    }
    
    public void sing(){
        crow.cry();
    }
    public void swim(){
        crow.fly();
    }
    
}