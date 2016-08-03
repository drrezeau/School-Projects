public class ThreadCounter implements Runnable {
	
	int start;
	
	public ThreadCounter(int start) {
		this.start = start;
	}
	
	
	@Override
	public void run() {
		for (int i = start; i < 101; i += 2) {
			if(start == 1)
				System.out.print("Odd");
			else
				System.out.print("Even");
			
			System.out.println(i);
			
			try {
				Thread.sleep(500);
			}
			catch (Exception x) {
			}
		}
	}
}