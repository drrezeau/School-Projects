public class Threads {

	
	public static void main(String[] args) throws InterruptedException {
		new Threads().run();	
	}
	
	
	public void run() throws InterruptedException {
		Thread t1 = new Thread(new ThreadCounter(1));
		Thread t2 = new Thread(new ThreadCounter(2));
		Running run = new Running();
		Thread t3 = new Thread(run);
			

		t1.start();
		t2.start();
		t3.start();
		
		
		t1.join();
		
		t2.join();
		
		if (t3 != null)
			run.terminate();
			
		System.out.println("All Finished!");
	}
}
