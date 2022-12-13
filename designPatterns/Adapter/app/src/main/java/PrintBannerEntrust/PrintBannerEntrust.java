package PrintBannerEntrust;

import Banner.Banner;
import Print.Print;

public class PrintBannerEntrust implements Print {

    Banner banner;

    public PrintBannerEntrust(String string) {
        banner = new Banner(string);
    }

    @Override
    public void printWeak() {
        banner.showWithParen();
    }

    @Override
    public void printStrong() {
        banner.showWithAster();
    }

}
