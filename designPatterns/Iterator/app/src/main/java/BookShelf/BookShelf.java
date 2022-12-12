package BookShelf;

import java.util.ArrayList;

import Aggregate.Aggregate;
import Book.Book;
import BookShelfIterator.BookShelfIterator;
import Iterator.Iterator;

public class BookShelf implements Aggregate {
    private ArrayList<Book> books = new ArrayList<>();

    public BookShelf(int maxSize) {
        this.books.ensureCapacity(maxSize);
    }

    public Book getBookAt(int index) {
        return this.books.get(index);
    }

    public void appendBook(Book book) {
        this.books.add(book);
    }

    public int getLength() {
        return this.books.size();
    }

    public Iterator iterator() {
        return new BookShelfIterator(this);
    }
}