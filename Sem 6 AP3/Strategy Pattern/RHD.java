class RHD extends Duck{
    RHD(){
        flyable = new FlyHigh();
        quackable = new LoudQuack();
    }
    public void display(){
        System.out.println("Red Head Duck");
    }
}