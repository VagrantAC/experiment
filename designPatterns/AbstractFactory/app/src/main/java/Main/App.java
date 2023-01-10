package Main;

import factory.Factory;
import factory.Link;
import factory.Page;
import factory.Tray;

public class App {
    public static void main(String[] args) {
        String classname = "tablefactory.TableFactory";
        Factory factory = Factory.geFactory(classname);
        Link people = factory.createLink("People's Daily", "http://www.people.com.cn/");
        Link gmw = factory.createLink("Guangming Daily", "http://www.gmw.cn/");
        Link us_yahoo = factory.createLink("Yahoo!", "http://www.yahoo.com/");
        Link jp_yahoo = factory.createLink("Yahoo!Japan", "http://www.yahoo.co.jp");
        Link excite = factory.createLink("Excite", "http://www.excite.com/");

        Tray traynews = factory.createTray("Daily");
        traynews.add(people);
        traynews.add(gmw);
        
        Tray trayyahoo = factory.createTray("Yahoo!");
        trayyahoo.add(us_yahoo);
        trayyahoo.add(jp_yahoo);

        Tray traysearch = factory.createTray("search engine");
        traysearch.add(trayyahoo);
        traysearch.add(excite);

        Page page = factory.createPage("TablePage", "VagrantAC");
        page.add(traynews);
        page.add(traysearch);
        page.output();
    }
}
