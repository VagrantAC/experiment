package Singleton;

public class Singleton {
    private static Singleton singleton = new Singleton();

    private Singleton() {
        System.out.println("generate an instance");
    }

    public static Singleton getInstance() {
        return singleton;
    }
}
