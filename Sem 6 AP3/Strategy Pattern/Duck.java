abstract class Duck{
    Flyable flyable;
    Quackable quackable;
    public void swim(){
        System.out.println("I Swim");
    }
    
    public void performFly(){
        flyable.fly();
    }
    
    public void performQuack(){
        quackable.quack();
    }
    
    abstract public void display();
    
    public void setQuackable(Quackable quackable){
        this.quackable = quackable;
    }
    
    public void setFlyable(Flyable flyable){
        this.flyable = flyable;
    }
    
}