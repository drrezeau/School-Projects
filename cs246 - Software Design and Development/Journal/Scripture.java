import org.w3c.dom.Element;

public class Scripture implements Annotation {
	
	private String scripture;

	//overrides the getDisplayText from the Annotation class
	@Override
	public String getDisplayText() {
		return scripture;
	}
	
	/**
	*Parses the scripture and gets the information 
	**/
	public Scripture parseScriptures(Element eScripture) {
		String book;
		String chapter;
		String startverse;
		String endverse;
		
		book = (String) eScripture.getAttribute("book");
		chapter = (String) eScripture.getAttribute("chapter");
		startverse = (String) eScripture.getAttribute("startverse");
		endverse = (String) eScripture.getAttribute("endverse");
		
		//handles the issue of no startverse and no end verse.
		if (startverse.equals("")){
			scripture = (book + " " + chapter);
		}
		else if (endverse.equals("")) {
			scripture = (book + " " + chapter + ":" + startverse);
		}
		else	{
			scripture = (book + " " + chapter + ":" + startverse + "-" + endverse);
		}
		return this;
	}
}