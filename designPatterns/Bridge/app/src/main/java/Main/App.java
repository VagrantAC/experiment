package Main;

import Display.CountDisplay;
import Display.Display;
import DisplayImpl.FileDisplayImpl;
import DisplayImpl.StringDisplayImpl;

public class App {
    public static void main(String[] args) {
        Display d1 = new Display(new StringDisplayImpl("Hello, China."));
        Display d2 = new CountDisplay(new StringDisplayImpl("Hello, World."));
        CountDisplay d3 = new CountDisplay(new StringDisplayImpl("Hello, Universe."));
        Display d4 = new CountDisplay(new FileDisplayImpl("settings.gradle"));
        d1.display();
        d2.display();
        d3.display();
        d3.multiDisplay(5);
        d3.randomDisplay();
        d4.display();
    }
}
