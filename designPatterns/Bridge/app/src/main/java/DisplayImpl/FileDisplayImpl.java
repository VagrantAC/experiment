package DisplayImpl;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class FileDisplayImpl extends DisplayImpl {

    File file;

    public FileDisplayImpl(String filename) {
        file = new File(filename);
    }

    public void rawOpen() {
    }

    public void rawPrint() {
        Scanner myReader;
        try {
            myReader = new Scanner(file);
            while (myReader.hasNextLine()) {
                String data = myReader.nextLine();
                System.out.println(data);
            }
            myReader.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    public void rawClose() {
    }
}
