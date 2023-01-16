package Visitor;

import java.util.Iterator;

import Directory.Directory;
import Entry.Entry;
import File.File;

public class ListVisitor extends Visitor {
    private String currentdir = "";
    public void visit(File file) {
        System.out.println(currentdir + "/" + file);
    }

    public void visit(Directory directory) {
        System.out.println(currentdir + "/" + directory);
        String saveDir = currentdir;
        currentdir = currentdir + "/" + directory.getName();
        Iterator<Entry> it = directory.iterator();
        while (it.hasNext()) {
            Entry entry = it.next();
            entry.accept(this);
        }
        currentdir = saveDir;
    }
}
