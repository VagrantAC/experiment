package Strategy;

import Hand.Hand;

public interface Strategy {
    public abstract Hand nextHand();
    public abstract void study(boolean win);
}
