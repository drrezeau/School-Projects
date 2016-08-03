package com.company;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;

public class Main {

    String wordsToRemove[] = {"the", "a", "but", "to", "that", "it", "for", "what"};

    public static void main(String[] args) {
	// write your code here

        String filename;
        if (args.length == 0) {
            System.out.println("USAGE: [file location]");
            return;
        }

        int i = 0;
        try {
            filename = args[0];
            BufferedReader reader = new BufferedReader(new FileReader(filename));
            String line;
            while ((line = reader.readLine())!= null) {
                if (line.length() != 6) {
                    String tokens[] = line.split(",");
                    tokens[1] = new Main().removeWords(tokens[1]);
                    for (int k = 0; k < tokens.length; k++)
                        System.out.println(k + " " + tokens[k]);

                }
                i++;
                if(i >20)
                    return;
            }
        } catch (Exception e) {
            System.out.println(e);
        }

    }

    public String removeWords(String userInput) {
        String returnString = "";
        String splitString[] = userInput.split(" ");
        boolean remove = false;

        for (int k = 0; k < splitString.length; k++) {
            for (int i = 0; i < wordsToRemove.length; i++) {
                if (splitString[k].equalsIgnoreCase(wordsToRemove[i])) { //also removes the letters inside words... gotta fix this
                    remove = true;
                }
            }
            if (!remove) {
                returnString += splitString[k] + " ";
            }
            remove = false;
        }



        return  returnString;
    }
}
