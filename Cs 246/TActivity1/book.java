import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.LinkedList;
import java.util.Iterator;
import java.util.*;





public class book {
	public static void main(String[] args) {
		
		new book().checkArgs(args);
		
		
		
		try {
			LinkedList<String> list  = new book().readFile(args[0]);
			new book().displayList(list);
			
			Map<String, String> map = new book().readMap(args[0]);
			displayMap(map);
			
			TreeMap<String, LinkedList<String> > map2 = new book().readMapOfLists(args[0]);
			new book().displayMap2(map2);
		} catch (FileNotFoundException e) {
			System.out.println ("Error Reading '" + args[0] + "'...");
		}
		
		
		
	}
	
	public TreeMap<String, LinkedList<String> > readMapOfLists(String filename) throws FileNotFoundException {
		System.out.println("Opening file '" + filename + "'...\n");
		BufferedReader reader = new BufferedReader(new FileReader(filename));
		
		TreeMap<String, LinkedList<String> > map = new TreeMap<String, LinkedList<String > >();
		String line;
		
		
		try {
			while ((line = reader.readLine()) != null) {
				LinkedList<String> list = new LinkedList<String>();
				System.out.println(line);
				String[] temp = line.split(":"); // split key and subTopics into size:2 array
				String key = temp[0]; //save the key into a string
				System.out.println("Key: " + key);
				line = temp[1]; //line becomes all subTopics
				System.out.println("Subtopics: " + line);
				String[] subTopics = line.split(","); //split the subTopics by the comma
				for (int i = 0; i <subTopics.length; i++) { //save the topics into the list
					list.add(subTopics[i]);
				}
				System.out.println("");
				
				map.put(key, list); //insert key mapped to list into map
			}
		}
		catch(IOException i ) {
			
		}
		
		return map;
	}
	
	public void displayMap2(TreeMap<String, LinkedList<String > > file) {
		Set<String> keys = file.keySet();
		
		Iterator it = keys.iterator();
		while(it.hasNext()) {
			String temp = (String) it.next();
			System.out.println("\nKey: " + temp);
			LinkedList<String> list = file.get(temp);
			//Iterator it2 = list.iterator();
			System.out.print("Values: ");
			displayList(list);
			//System.out.println("");
		}
	}
	
	
	public TreeMap<String, String> readMap(String filename) throws FileNotFoundException {
		
		System.out.println("Opening file '" + filename + "'...\n");
		BufferedReader reader = new BufferedReader(new FileReader(filename));
		
		TreeMap<String, String> map = new TreeMap<String, String>();
		String line;
		try {
			while ((line = reader.readLine()) != null) {
				String[] words = line.split(":");
				map.put(words[0], words[1]);
			} 
		} catch (IOException i) {
			System.out.println("ERROR Reading file");
		}
		
		return map;
	}
	
	public static void displayMap(Map<String, String> file) {
				
		Set<String> keys = file.keySet();
		
		Iterator it = keys.iterator();
		while(it.hasNext()) {
			String temp = (String) it.next();
			System.out.println("Key: " + temp + "->Value: " + file.get(temp));
		}
	}
	
	
	/******************************************************************
	*readFile
	* parses the file and counts the number of words and displays it all
	*********************************************/
	public LinkedList<String> readFile(String filename) throws FileNotFoundException {
		
		System.out.println("Opening file '" + filename + "'...\n");
		BufferedReader reader = new BufferedReader(new FileReader(filename));
		
		LinkedList<String> list = new LinkedList<String>();
		//int wordCount = 0;
		String line;
		try {
			while ((line = reader.readLine()) != null) {
				list.add(line);
			} 
		} catch (IOException i) {
			System.out.println("ERROR Reading file");
		}
		
		return list;
	}
	
	public void displayList(LinkedList<String> file) {
		Iterator it = file.iterator();
		while(it.hasNext()) {
			String temp = (String) it.next();
			if (it.hasNext())
				System.out.print(temp + "-> ");
			else
				System.out.print(temp);
			System.out.println("");
		}
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