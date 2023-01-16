package Visitor;

import File.*;
import Directory.*;

public abstract class Visitor {
    public abstract void visit(File file);
    public abstract void visit(Directory Directory);
}