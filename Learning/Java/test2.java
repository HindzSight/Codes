//HEAD SECTION OF THE CODE
package Java;

abstract class Pizza{
    abstract void getName();
    abstract void delivery();
    abstract void packaging();
}

abstract class PizzaStore{
    PizzaStore p;
    public void orderPizza(String type){
        Pizza pizza = p.createPizza(type);
        pizza.getName();
        pizza.delivery();
        pizza.packaging();
    }

    abstract Pizza createPizza(String type);
}

//JUETPizzaStore 3 VegPizza ChickenPizza and JainPizza
//WRITE CODE HERE
class VegPizza extends Pizza{
    VegPizza(){}
    void getName(){
        System.out.println("JUETPizzaStore: VegPizza");
    }
    void delivery(){
        System.out.println("Delivery in 30 minutes");
    }
    void packaging(){
        System.out.println("Good Packing");
    }
}

class ChickenPizza extends Pizza{
    ChickenPizza(){}
    void getName(){
        System.out.println("JUETPizzaStore: ChickenPizza");
    }
    void delivery(){
        System.out.println("Delivery in 45 minutes");
    }
    void packaging(){
        System.out.println("Packed in Red box");
    }
}

class JainPizza extends Pizza{
    JainPizza(){}
    void getName(){
        System.out.println("JUETPizzaStore: JainPizza");
    }
    void delivery(){
        System.out.println("Delivery before sunset");
    }
    void packaging(){
        System.out.println("Packed in green box");
    }
}

class JUETPizzaStore extends PizzaStore{
    Pizza pizza;
    Pizza createPizza(String type){
        if(type.equals("VegPizza")){
            pizza = new VegPizza();
        }else if (type.equals("ChickenPizza")){
            pizza = new ChickenPizza();
        }else if(type.equals("JainPizza")){
            pizza = new JainPizza();
        }
        return pizza;
    }
}

// TAIL SECTION OF THE CODE

public class test2 {
    public static void main(String args[]){
        JUETPizzaStore PS = new JUETPizzaStore();
        PS.orderPizza("VegPizza");
    }
}
