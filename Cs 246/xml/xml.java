import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import org.w3c.dom.Document;
import org.w3c.dom.NodeList;
import org.w3c.dom.Node;
import org.w3c.dom.Element;
import java.io.File;
import org.xml.sax.*;
import java.io.*;

public class XML {
	public static void main(String[] args) {
	
		try {
			//builds the xml document builder
			DocumentBuilderFactory DBF = DocumentBuilderFactory.newInstance();
			DocumentBuilder DB = DBF.newDocumentBuilder();
			
			//builds the actual document in the program
			File file = new File("conference.xml");
			Document dom = DB.parse(file);
			
			//displays the information for the conference itself
			System.out.println("Month: " + dom.getDocumentElement().getAttribute("month"));
			System.out.println("Year: " + dom.getDocumentElement().getAttribute("year"));
			NodeList nList = dom.getElementsByTagName("session");
			
			//displays the sessions
			for (int temp = 0; temp < nList.getLength(); temp++) {
				Element a = (Element) nList.item(temp);
				NodeList nList2 = a.getElementsByTagName("speaker");
				System.out.println("Session: " + a.getAttribute("name"));
				
				//displays the speakers for the session given
				for (int i = 0; i < nList2.getLength(); i++) {
					Element e = (Element) nList2.item(i);
					System.out.println(e.getAttribute("name"));
				}
				System.out.println("");
			}
			System.out.println("Done");
		}
		catch (Exception s) {
		}

	}
	
	
}