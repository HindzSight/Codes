class RD extends Duck{
    RD(){
        flyable = new NoFly();
        quackable = new Squeak();
    }
    public void display(){
        System.out.println("Rubber Duck");
    }
}