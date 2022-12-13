package Main;

import Print.Print;
import PrintBanner.PrintBanner;
import PrintBannerEntrust.PrintBannerEntrust;

public class App {
    public static void main(String[] args) {
        Print p = new PrintBanner("Hello");
        p.printWeak();
        p.printStrong();

        Print p1 = new PrintBannerEntrust("Hello");
        p1.printWeak();
        p1.printStrong();
    }
}
