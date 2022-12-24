package Director;

import Builder.Builder;

public class Director {
    private Builder builder;

    public Director(Builder builder) {
        this.builder = builder;
    }

    public void construct() {
        builder.makeTitle("Greeting");
        builder.makeString("Morning to afternoon");
        builder.makeItems(new String[] {
                "Good evening",
                "Good night",
                "Goodbye",
        });
        builder.close();
    }
}
