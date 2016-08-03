import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileNotFoundException;
import java.io.IOException;

public class moneyFinder {
	public static void main(String[] args) { //Main isnt everything!!
		if (args.length != 1) {
			System.out.println("ERROR!! Too few OR many Args!");
			System.exit(0);
		}
		try {
		new moneyFinder().parseFile(args[0]);
		} catch (FileNotFoundException e) {
			System.out.println("ERROR");
		}
	}
	
	public void parseFile(String filename) throws FileNotFoundException {
		System.out.println("Opening file: " + filename);
		
		//FileReader file = new FileReader(filename);
		//BufferedReader reader = new BufferedReader(file);
		//try {
			
		BufferedReader reader = new BufferedReader(new FileReader(filename));
		//}
		
		/*catch (FileNotFoundException e) {
			System.out.println("ERROR");	
			System.exit(0);
		}*/
		
		String line;
		try {
			while ((line = reader.readLine()) != null) {
				if (line.contains("$")) {
					System.out.print("$$$ - ");
				}
				System.out.println(line);
			}
			reader.close();
		}
		catch (IOException i) {
			System.out.println("Caught");
		}

	}
}