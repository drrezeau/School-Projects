import java.util.ArrayList;
import org.w3c.dom.Document;
import org.w3c.dom.NodeList;
import org.w3c.dom.Node;
import org.w3c.dom.Element;
import java.io.BufferedReader;
import java.util.Iterator;

public class Entry {
	
	//member variables for all the data of an entry
	private ArrayList<Annotation> list;
	private String date;
	private String content;
	
	/**
	*Takes one entry and parses it for the 
	*different scriptures and topics and the content.
	**/
	public Entry parseEntries(Element entry) {
		list = new ArrayList<Annotation>();
	
		//gets the one entry tag we want to work with.	
		date = (String) entry.getAttribute("date");
				
		
		//get the scripture tags
		NodeList nScripture = entry.getElementsByTagName("scripture");
		for (int i = 0; i < nScripture.getLength(); i++) {
			Scripture scripture1 = new Scripture();
			Element eScripture = (Element) nScripture.item(i);
			list.add(scripture1.parseScriptures(eScripture));
		}
		
		//get the topic tags
		NodeList nTopic = entry.getElementsByTagName("topic");
		for (int i = 0; i < nTopic.getLength(); i++) {
			Topic topic1 = new Topic();
			Node nNode = nTopic.item(i);
			list.add(topic1.parseTopics(nNode));
		}	
		
		//get the content tag
		NodeList lContent = entry.getElementsByTagName("content");
		Node nContent = lContent.item(0);
		content = nContent.getTextContent();
		
		return this;
	}
	
	//display the whole entry
	public void display() {
		System.out.println("------------------------------\nEntry'\nDate: " + date);
		System.out.println("'\nContent:'\n");
		System.out.println(content +'\n');
		System.out.println("Annotations:\n");
		for (Annotation temp: list) {
			System.out.println("-" + temp.getDisplayText() + '\n');
		}
	}
}