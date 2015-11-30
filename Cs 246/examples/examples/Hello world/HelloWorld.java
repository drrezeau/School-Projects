 public class HelloWorld {
	//you have to label each method or variable with private or public, depending on you want. if not declared, its semi inbetween.
     
     import java.io.bufferedReader;
	
	//static means it is shared amongst all instances of the class.
	public static void main(String[] args) {
		System.out.println("Hello World!");
		for (int i = 0; i < args.length; i++) {
			System.out.println("Hello " + args[i]);
		}	
		
		System.out.println ("Using the enhanced for loop");
		for (String arg : args) {
			System.out.print(arg + " ");
		}
		System.out.println("");
	}	
}