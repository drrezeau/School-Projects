import java.util.*;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileNotFoundException;
import java.io.IOException;


public class topic {

	public TreeMap<String, LinkedList<String> > readMap(String filename) throws FileNotFoundException {
		//System.out.println("Opening file '/collections1/topics.txt '...\n");
		BufferedReader reader = new BufferedReader(new FileReader(filename));
		
		TreeMap<String, LinkedList<String> > map = new TreeMap<String, LinkedList<String > >();
		String line;
		
		
		try {
			while ((line = reader.readLine()) != null) {
				LinkedList<String> list = new LinkedList<String>();
				String[] temp = line.split(":"); // split key and subTopics into size:2 array
				String key = temp[0]; //save the key into a string
				line = temp[1]; //line becomes all subTopics
				String[] subTopics = line.split(","); //split the subTopics by the comma
				for (int i = 0; i <subTopics.length; i++) { //save the topics into the list
					list.add(subTopics[i]);
				}
									
				map.put(key, list); //insert key mapped to list into map
			}
		}
		catch(IOException i ) {
			
		}
		
		return map;
	}
	
	
}