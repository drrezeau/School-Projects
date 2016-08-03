/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package csv.parser;

import com.opencsv.CSVReader;
import java.io.FileReader;
import java.util.List;

/**
 *
 * @author david_000
 */
public class CSVParser {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        try {
            CSVReader reader = new CSVReader(new FileReader("C:\\Users\\david_000\\Google Drive\\School\\Grad Schools.csv"));
            List myEntries = reader.readAll();
            
            for (int i = 0; i < myEntries.size(); i++) {
                String temp[] = (String[]) myEntries.get(i);
//                System.out.println(temp[0] + " || " + temp[1] + " || " + temp[2]);
                System.out.printf("%12s || %16s || %7s\n", temp[0], temp[1], temp[2]);
            }
        } catch (Exception E) {
            E.printStackTrace();
        }
    }
    
}
