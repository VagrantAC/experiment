package Idcard;

import FrameWork.Product;

public class IDCard extends Product {
    private String owner;
    private Integer id;

    IDCard(Integer id, String owner) {
        System.out.println("create {id:" + id + ", owner:" + owner + "} ID card.");
        this.id = id;
        this.owner = owner;
    }

    @Override
    public void use() {
        System.out.println("register {id:" + id + ", owner:" + owner + "} ID card.");
    }

    public String getOwner() {
        return this.owner;
    }

    public Integer getId() {
        return this.id;
    }
}
