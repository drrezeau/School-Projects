/************************************
*Assignment: Journal Xml parsing
*Author: David Lambertson
*Collaborators: Kendall Wahnschaffe
*Summary: This program lets you take a 
* spiritual xml journal and parse the file
* grabbing the information and saving it into
* each given spot. Then displays then information
* at the very end from the list of entries. 
****************************************/
import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import org.w3c.dom.Document;
import org.w3c.dom.NodeList;
import org.w3c.dom.Element;
import java.io.File;
import org.xml.sax.*;
import java.io.*;
import java.util.ArrayList;


public class Journal {
	
	//private list of entries for the journal
	private ArrayList<Entry> entries;
	
	//calls run
	public static void main(String[] args) {
	
		new Journal().run();
	}
	
	/**
	*RUN
	*runs the entire program
	**/
	public void run() {

		
		//Entry entryOne = new Entry();
		Journal journal = new Journal().parseFile();

		
		//displays through all the journal entries
		for(Entry temp: journal.entries) {
			temp.display();
		}
	}
	
	/********
	* parseFile
	* Opens the xml file and pulls the first entry tag out.
	* Passes the tag to the Entry parseEntry method.
	********/
	public Journal parseFile() {
	
		try {
			//builds the xml document builder
			DocumentBuilderFactory DBF = DocumentBuilderFactory.newInstance();
			DocumentBuilder DB = DBF.newDocumentBuilder();
			
			//builds the actual document in the program
			File file = new File("burtonJournal.xml");
			Document dom = DB.parse(file);			
			
			//allocates the ArrayList of entries
			entries = new ArrayList<Entry>();
			
			//Takes each entry tag and goes through each one.
			NodeList nEntry = dom.getElementsByTagName("entry");
			for (int temp = 0; temp < nEntry.getLength(); temp++) {
				Entry entry1 = new Entry();
				Element entry = (Element) nEntry.item(temp);
				entries.add(entry1.parseEntries(entry));
			}
		}
		catch(Exception e) {
			System.out.println("Error! Check your file or yourself");
		}
		
		return this;
	}
	
}