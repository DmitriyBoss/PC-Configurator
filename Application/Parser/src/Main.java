import org.jsoup.Jsoup;
import org.jsoup.nodes.Document;
import org.jsoup.nodes.Element;
import org.jsoup.select.Elements;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
/**
 * Данное мини-приложение предназначено для получения HTML-разметки сайта с комплектующими
 * и преобразования данной разметки к виду, готовому для использования в основной программе.
 */
public class Main {

    public static void main(String[] args) {
        parseInfo();
    }

    /**
     * Метод непосредственно записывающий преобразованную информацию в файлы приложения
     * Входные параметры: String filename(имя файла),
     * String[] buffer(массив строк, содержащий названия и цены комплектующих)
     * */
    private static void fileWrite(String filename, String[] buffer) {
        File work = new File("System//" + filename);
        try {
            if(!work.exists()) work.createNewFile();
            BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(work));
            for (String s : buffer) {
                bufferedWriter.write(s);
                bufferedWriter.newLine();
            }
            bufferedWriter.close();

         } catch (IOException e) {
                e.printStackTrace();
         }
    }

    /**
     * Метод, получающий HTML код страницы и преобразующий его к требуемуему виду
     * */
    private static void parseInfo(){
        Document[] sharesDocs = new Document[12];
        String[] Urls = {
                "https://www.ttn.by/kompyutery-i-seti/computer_hardware/motherboard/?item_status=0",
                "https://www.ttn.by/kompyutery-i-seti/computer_hardware/processor/?item_status=0",
                "https://www.ttn.by/kompyutery-i-seti/computer_hardware/fan/?item_status=0",
                "https://www.ttn.by/kompyutery-i-seti/computer_hardware/ram/?item_status=0",
                "https://www.ttn.by/kompyutery-i-seti/computer_hardware/videocard/?item_status=0",
                "https://www.ttn.by/kompyutery-i-seti/computer_hardware/hdd/?item_status=0",
                "https://www.ttn.by/kompyutery-i-seti/computer_hardware/SSD/?item_status=0",
                "https://www.ttn.by/kompyutery-i-seti/computer_hardware/Bloki_pitaniya/?item_status=0",
                "https://www.ttn.by/kompyutery-i-seti/computer_hardware/atxcase/?item_status=0",
                "https://www.ttn.by/kompyutery-i-seti/computer_hard/display/?item_status=0",
                "https://www.ttn.by/kompyutery-i-seti/input_devices/Keyboards/?item_status=0",
                "https://www.ttn.by/kompyutery-i-seti/input_devices/computer_Mouse/?item_status=0"};

        for (int i = 0; i < Urls.length; i++) {
            try {
                sharesDocs[i] = Jsoup.connect(Urls[i]).get();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }

        String str;
        String[] split_str;
        String[] buffer = new String[24];
        for(int j = 0; j < 12; j++) {
            Elements el1 = sharesDocs[j].getElementsByTag("button");
            Element el2;
            int k = 0;
            for (int i = 9; i < 33; i++) {
                el2 = el1.eq(i).get(0);
                str = el2.outerHtml();
                split_str = str.split("'");
                buffer[k] = split_str[9] + ";" + split_str[25] + ";";
                k++;
            }

            switch (j){
                case 0:
                    fileWrite("Motherboard.txt", buffer);
                    break;
                case 1:
                    fileWrite("Processor.txt", buffer);
                    break;
                case 2:
                    fileWrite("Cooler.txt", buffer);
                    break;
                case 3:
                    fileWrite("RAM.txt", buffer);
                    break;
                case 4:
                    fileWrite("Videocard.txt", buffer);
                    break;
                case 5:
                    fileWrite("HDD.txt", buffer);
                    break;
                case 6:
                    fileWrite("SSD.txt", buffer);
                    break;
                case 7:
                    fileWrite("Powerblock.txt", buffer);
                    break;
                case 8:
                    fileWrite("Systemblock.txt", buffer);
                    break;
                case 9:
                    fileWrite("Monitor.txt", buffer);
                    break;
                case 10:
                    fileWrite("Keyboard.txt", buffer);
                    break;
                case 11:
                    fileWrite("Mouse.txt", buffer);
                    break;
            }
        }
    }
}
