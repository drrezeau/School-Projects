import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Shoe {
	
	//member variables
	private float size;
	private boolean isMens;
	private String shoeName;

	//Main
	public static void main(String[] args) {
		Shoe runningShoe = new Shoe();
		runningShoe.setSize(9.5f);
		System.out.println("Running Shoe Size: " + runningShoe.getSize()); // since it is a apart of the class, it CAN access the privates, 
																								 // but dont get use to it.
		//User Input example!! :)
		
		System.out.print("Enter a name of shoe: ");
		BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
		try {
			runningShoe.setShoeName((String) input.readLine());
		} catch (Exception e) {
		}
		//runningShoe.setShoeName(System.in.read());
		System.out.println("Name of shoe: " + runningShoe.getShoeName());
	}
	
	//default constructor
	//If you do a non-default, but not a default you should get an error.
	public Shoe() {
		size = 0;
		shoeName = "Blank";
		isMens = false;
	}
	
	public void setShoeName(String name) {
		this.shoeName = name; 
	}
	
	public String getShoeName() {
		return shoeName; 
	}
	
	//return the size of the shoe
	public float getSize() {
		return size;
	}
	
	//sets the size of the shoe
	public void setSize(float size) {
		this.size = size;
	}

}