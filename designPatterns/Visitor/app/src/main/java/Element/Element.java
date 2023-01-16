package Element;

import Visitor.Visitor;

public interface Element {
    public abstract void accept(Visitor v);
}