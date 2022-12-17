package Idcard;

import java.util.*;
import FrameWork.*;

public class IDCardFactory extends Factory {
    private List<IDCard> owners = new ArrayList<IDCard>();
    private Integer length = 0;

    @Override
    protected Product createProduct(String owner) {
        return new IDCard(++this.length, owner);
    }

    @Override
    protected void registerProduct(Product product) {
        owners.add((IDCard) product);
    }

    public List<IDCard> getOwners() {
        return owners;
    }

}
