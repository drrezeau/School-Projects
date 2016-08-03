import java.math.*;

public class Vastness {

    public static void main (final String[] args) {	
		new Vastness().run(args);
    }
    
	public void run(final String[] args){
		Thread t1 = new Thread(new Runnable() {
			@Override
			public void run() {
				Long start_time = System.nanoTime();
				int whatever = args[0].length();
		
				for (int i = 100000; i <= 500000; i++){
					System.out.println(i);
					BigInteger result = new BigInteger("2"); 
					result = result.pow(i);
					String stringResult = result.toString();
			
					int res = new BigInteger(args[0]).compareTo(result);
					if (res == -1 || res == 0){
				
						if(args[0].equals(stringResult.substring(0, whatever))){
							System.out.println("Found in first thread: 2^" + i);
							break;
						}
					}
				}
		
				float diff_time = System.nanoTime() - start_time;
				System.out.println("Thread one Time elapsed: " + diff_time / 1000000000);
			}
		});
		t1.start();
		
		Thread t2 = new Thread(new Runnable() {
			@Override
			public void run() {
				Long start_time = System.nanoTime();
		
				for (int i = 500000; i <= 700000; i++){
					System.out.println(i);
					BigInteger result = new BigInteger("2"); 
					result = result.pow(i);
					String stringResult = result.toString();
			
					int res = new BigInteger(args[0]).compareTo(result);
					if (res == -1 || res == 0){
				
						if(args[0].equals(stringResult.substring(0, args[0].length()))){
							System.out.println("Found in second thread: 2^" + i);
							break;
						}
					}
				}
		
				float diff_time = System.nanoTime() - start_time;
				System.out.println("Thread two Time elapsed: " + diff_time / 1000000000);
			}
		});
		t2.start();
	}
}