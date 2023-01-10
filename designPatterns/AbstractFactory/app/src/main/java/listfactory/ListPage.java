package listfactory;

import java.util.Iterator;
import factory.Item;
import factory.Page;

public class ListPage extends Page {
    public ListPage(String title, String author) {
        super(title, author);
    }

    public String makeHTML() {
        StringBuffer buffer = new StringBuffer();
        buffer.append("<html><head><title>" + title + "</title></head>\n");
        buffer.append("<body>\n");
        buffer.append("<h1>" + title + "</h1>\n");
        buffer.append("<ul>\n");
        Iterator<Item> it = content.iterator();
        while (it.hasNext()) {
            Item item = it.next();
            buffer.append(item.makeHTML());
        }
        buffer.append("</ul>");
        buffer.append("<hr><address>" + author + "</address>");
        buffer.append("</body></html>\n");
        return buffer.toString();
    }
}