package com.company;

import java.util.Scanner;

public class Main {

    String wordsToRemove[] = {"the", "a", "but", "to", "that"};
    public static void main(String[] args) {
	// write your code here
        String userInput;
        Scanner input = new Scanner(System.in);
        System.out.println("Please input a line to be cleaned");
        System.out.print(">");
        userInput = input.nextLine();

        System.out.println(userInput);

        userInput = new Main().removeWords(userInput);

        System.out.println(userInput);
    }

    public String removeWords(String userInput) {
        for (int i = 0; i < wordsToRemove.length; i++) {
            if (userInput.contains(wordsToRemove[i])) { //also removes the letters inside words... gotta fix this
                userInput = userInput.replaceAll(wordsToRemove[i], "");
            }
        }
        return  userInput;
    }

}
