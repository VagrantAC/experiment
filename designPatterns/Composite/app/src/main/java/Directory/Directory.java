package Directory;

import java.util.ArrayList;
import java.util.Iterator;

import Entry.Entry;

public class Directory extends Entry {
    private String name;
    private ArrayList<Entry> directory = new ArrayList<>();
    public Directory(String name) {
        this.name = name;
    }

    public String getName() {
        return name;
    }

    public int getSize() {
        int size = 0;
        Iterator<Entry> it = directory.iterator();
        while (it.hasNext()) {
            Entry entry = it.next();
            size += entry.getSize();
        }
        return size;
    }

    public Entry add(Entry entry) {
        entry.setRootEntry(this);
        directory.add(entry); 
        return this;
    }

    public void printList(String prefix) {
        System.out.println(prefix + "/" + this);
        Iterator<Entry> it = directory.iterator();
        while (it.hasNext()) {
            Entry entry = it.next();
            entry.printList(prefix + "/" + name);
        }
    }
}
