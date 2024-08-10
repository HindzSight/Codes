abstract class Animal{
    public abstract void makeVoice();
}

class Cow extends Animal {
    public void makeVoice() {
        System.out.println("Moo!");
    }
}

class Dog extends Animal {
    public void makeVoice() {
        System.out.println("Woof!");
    }
}

class Pig extends Animal {
    public void makeVoice() {
        System.out.println("Oink!");
    }
}

class Goat extends Animal {
    public void makeVoice() {
        System.out.println("Baa!");
    }
}

class Lion extends Animal {
    public void makeVoice() {
        System.out.println("Roar!");
    }
}