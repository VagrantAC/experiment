package Entry;

import java.util.Iterator;
import Element.Element;
import FileTreatmentException.FileTreatmentException;

public abstract class Entry implements Element {
    public abstract String getName();
    public abstract int getSize();
    public Entry add(Entry entry) throws FileTreatmentException {
        throw new FileTreatmentException();
    }

    public Iterator<Entry> iterator() throws FileTreatmentException {
        throw new FileTreatmentException();
    }

    public String toString() {
        return getName() + " (" + getSize() + ")";
    }
}