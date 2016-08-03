import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileNotFoundException;
import java.io.IOException;

/*********************************************
*wordCounter
*the class to use a word counter. Takes any file given by 
*the user and parses it while counting the words and
*displays the number of words per line. 
**********************************************/
public class wordCounter {
	/*************************************
	*main
	* main method for the class wordCounter
	**************************************/
	public static void main(String[] args) {
		new wordCounter().checkArgs(args);
		try {
			new wordCounter().parseFile(args[0]);
		} catch (FileNotFoundException e) {
			System.out.println ("Error Reading '" + args[0] + "'...");
		}
	}
	
	/********************************************
	*parseFile
	* parses the file and counts the number of words and displays it all
	*********************************************/
	public void parseFile(String filename) throws FileNotFoundException {
		
		System.out.println("Opening file '" + filename + "'...\n");
		BufferedReader reader = new BufferedReader(new FileReader(filename));
		
		String line;
		int wordCount = 0;
		try {
			while ((line = reader.readLine()) != null) {
				String[] words = line.split(" "); //takes the whole string and splits the string into seperate words to count them
				wordCount += words.length;
				System.out.println(words.length + ": " + line);
			} 
		} catch (IOException i) {
			System.out.println("ERROR Reading file");
		}
		
		System.out.println("Total Words for file: " + wordCount);
	}
	
	/**********************************
	*checkArgs
	* This method takes the number of args and checks it to make sure it is right
	************************************/
	public void checkArgs(String[] args) {
		if (args.length > 1) {
			System.out.println("ERROR! Too many Args.");
			System.exit(0);
	  	} else if(args.length == 0) {
			System.out.println("Please declare a filename");
			System.exit(0);
		}
	}
}