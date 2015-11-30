/*************************************************
* Program: Collections and Interfaces
* Author: David Lambertson
* Collaborators: Kendall Wahnschaffe
* Summary:
*
*
**************************************************/


import java.util.*;
import java.io.IOException;
import java.io.File;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileNotFoundException;

public class finder {
	public static void main(String[] args) {
		finder item = new finder();
		
		//item.checkArgs(args);
		item.run(args);
	}
	
	/***************************
	*Run
	*
	**************************/
	public void run(String[] args) {
		//grab the commands from the finder.properties
		Properties prop = new Properties();
		try {
			prop.load(new BufferedReader(new FileReader("finder.properties")));
		}
		catch(IOException i) {
		}
		
		String topicFile = prop.getProperty("topics");
		String Directory = prop.getProperty("directory");
				
		File folder = new File(Directory);
		File[] listOfFiles = folder.listFiles();
		
		for (File file : folder.listFiles()) {
			String filename = file.toString();
			if (filename.contains(".txt")) {
				System.out.println("Filename: " + filename);
				TreeSet<String> topics = new finder().checkFile(filename, topicFile);
				new finder().displayTopics(topics);
			}
		}
	}
	
	/*****************
	* Display Topics
	*****************/
	public void displayTopics(TreeSet<String> topics) {
		Iterator it = topics.iterator();
		
		System.out.println("The chapter contains the following topics:");
		while(it.hasNext()) {
			String topic = (String) it.next();
			if (it.hasNext())
				System.out.print(topic + ", ");
			else
				System.out.print(topic);
		}
		System.out.println("\n");
	}
	
	
	/****************
	* Check File
	*
	*
	*********************/
	public TreeSet<String> checkFile(String filename, String topicFile)  {
		TreeSet<String> topicsContained= new TreeSet<String>();
		try {
			BufferedReader reader = new BufferedReader(new FileReader(filename));
		
			TreeMap<String, LinkedList<String> > myMap = new topic().readMap(topicFile);
			String line;
		
			while ((line = reader.readLine()) != null) {
								
				Set<String> keys = myMap.keySet();
		
				Iterator it = keys.iterator();
				while(it.hasNext()) {
					String temp = (String) it.next();
					LinkedList<String> list = myMap.get(temp);
					Iterator it2 = list.iterator();
					while(it2.hasNext()) {
						String temp2 = (String) it2.next();
						if (line.contains(temp2))
							topicsContained.add(temp);
					}
				}	
			}
			reader.close();
		}
		catch (IOException i) { 
		}
		
		return topicsContained;	
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