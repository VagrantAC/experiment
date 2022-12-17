package Main;

import FrameWork.Factory;
import FrameWork.Product;
import Idcard.IDCardFactory;

public class App {
    public static void main(String[] args) {
        Factory factory = new IDCardFactory();
        Product card1 = factory.create("xiaoming");
        Product card2 = factory.create("xiaohong");
        Product card3 = factory.create("xiaogang");
        card1.use();
        card2.use();
        card3.use();
    }
}
