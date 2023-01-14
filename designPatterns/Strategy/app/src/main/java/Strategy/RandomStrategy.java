package Strategy;

import java.util.Random;
import Hand.Hand;

public class RandomStrategy implements Strategy {
    private Random random;
    public RandomStrategy(int seed) {
        random = new Random(seed);
    }
    public Hand nextHand() {
        return Hand.getHand(random.nextInt(3));
    }

    public void study(boolean win) {
    }
}
