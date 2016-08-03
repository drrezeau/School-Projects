
import org.w3c.dom.Node;


public class Topic implements Annotation {
	
	private String topic;

	//overrides the function from Annotation class
	@Override
	public String getDisplayText() {
		
		return topic;
	}
	
	//gets the information of topics.
	public Topic parseTopics(Node nTopic) {		
		
		topic = (nTopic.getTextContent() +'\n');
			
		return this;
	}
}

