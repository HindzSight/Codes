class Soda extends Decorator{
    public Soda(Offering offering){
        this.offering = offering;
    }
    String getName(){
        return offering.getName() + " with Soda";
    }
    int getPrice(){
        return offering.getPrice() + 25;
    }
}