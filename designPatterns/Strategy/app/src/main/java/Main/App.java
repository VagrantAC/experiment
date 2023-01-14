package Main;

import Hand.Hand;
import Player.Player;
import Strategy.ProbStrategy;
import Strategy.WinningStrategy;

public class App {
    public static void main(String[] args) {
        int seed1 = 314;
        int seed2 = 15;
        Player player1 = new Player("Taro", new WinningStrategy(seed1));
        Player player2 = new Player("Hanna", new ProbStrategy(seed2));
        for (int i = 0; i < 10000; i ++) {
            Hand nextHand1 = player1.nextHand();
            Hand nextHand2 = player2.nextHand();
            if (nextHand1.isStrongerThan(nextHand2)) {
                System.out.println("Winner:" + player1);
                player1.win();
                player2.lose();
            } else if (nextHand2.isStrongerThan(nextHand1)) {
                System.out.print("Winner:" + player2);
                player1.lose();
                player2.win();
            } else {
                System.out.println("Event...");
                player1.event();
                player2.event();
            }
        }
        System.out.println("Total result:");
        System.out.println(player1.toString());
        System.out.println(player2.toString());
    }
}
