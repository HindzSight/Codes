class WD extends Duck{
    WD(){
        flyable = new NoFly();
        quackable = new Mute();
    }
    public void display(){
        System.out.println("Wooden Duck");
    }
}