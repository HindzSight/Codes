class GID extends Duck{
    GID(){
        flyable = new FlyHigh();
        quackable = new LoudQuack();
    }
    public void display(){
        System.out.println("Great Indian Duck");
    }
}