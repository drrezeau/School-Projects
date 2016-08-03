import java.io.BufferedReader;
import java.io.InputStreamReader;


public class personTest {
	public static void main(String[] args) {
		person p = new person();
		
		changeName(p);
		
		System.out.println("p: " + p + ", p.name: " + p.name);
	}
	
	public static void changeName(person thePerson) {
		System.out.println("thePerson: " + thePerson + ", thePerson.name: " + thePerson.name);
		
		System.out.print("Enter a name: ");
		BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
		try {
			thePerson.name =(String) input.readLine();
		} catch (Exception e) {
		}
		
		//thePerson.name = "David";
		System.out.println("thePerson: " + thePerson + ", thePerson.name: " + thePerson.name);
	}
}