package Entry;

import FileTreatmentException.FileTreatmentException;

public abstract class Entry {
    public Entry rootEntry = null;
    public abstract String getName();
    public abstract int getSize();
    public Entry add(Entry entry) throws FileTreatmentException {
        throw new FileTreatmentException();
    }

    public void setRootEntry(Entry entry) {
        this.rootEntry = entry;
    }

    public String getRootPath() {
        String path = "";
        if (this.rootEntry != null) {
            path = this.rootEntry.getRootPath();
        }
        return path + "/" + this.getName();
    }

    public void printList() {
        printList("");
    }

    public abstract void printList(String prefix);

    public String toString() {
        return getName() + " (" + getSize() + ")";
    } 
}
