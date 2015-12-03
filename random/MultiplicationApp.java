import java.util.ArrayList;


public class MultiplicationApp {
    public static void main(String[] args) {
        new MultiplicationApp().run(args);
    }

    public void run(String[] args) {    
        if (args.length <= 1) {
            System.out.println("Enter two numbers on command line");
            return;
        }
        int first = Integer.parseInt(args[0]);
        int second = Integer.parseInt(args[1]);
        
        System.out.println("Russian Peasant Multiplication");
        russianPeasantMult(first, second);
        
        System.out.println("Egyptian Multiplication");
        egyptianMultiplication(first, second);
    }
    
    
    static void russianPeasantMult(int a, int b) {
        int temp1 = a, temp2 = b;
        ArrayList<Integer> result = new ArrayList<Integer>();
        System.out.printf("%3d || %3d\n", a, b);
        if (a % 2 == 1) {
            result.add(b);
        }
        
        while(a > 1) {
            a /= 2;
            b *= 2;
            
            System.out.printf("%3d || %3d\n", a, b);
            
			//If it's even
            if (a % 2 == 1) {
                result.add(b);
            }
        }
        
        int total = 0;
        for (int i = 0; i < result.size(); i++) {
            total += result.get(i);
			
			if (i == result.size() - 1){
				System.out.print(result.get(i));
			}else {
				System.out.print(result.get(i) + " + ");
			}
				
        }
        
        System.out.printf(" = %4d\n", total);
    }
    
    
    static void egyptianMultiplication(int a, int b) {
        int powOf2 = 0;
        int i = 0;
		ArrayList<Integer> result = new ArrayList<Integer>();
        do {
            powOf2 = (int)Math.pow(2, i);
			result.add(powOf2);
            System.out.printf("%4d || %4d\n", powOf2, (powOf2 * a));
            i++;
        } while(powOf2 < b);
		
		int total = 0;
		int product = 0;
		for (; i >= 0; i--) {
			int temp = (int)Math.pow(2, i);
			
            // System.out.println(i);
            // System.out.println(total + temp);
            if (temp < b && (total + temp <= b)){
				total += temp;
				product += temp * a;
				if (i == 0 || total == b){
					System.out.println(temp * a + " = " + product);
				}else{
					System.out.print(temp * a + " + ");
				}
			}		
		}
    }
}