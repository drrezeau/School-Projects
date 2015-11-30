public class Running implements Runnable {
	boolean running = true;
	
	public void terminate() {
		running = false;
	}
	
	@Override
	public void run() {
		while(running) {
			System.out.println("Running!!");
			
			try {
				Thread.sleep(500);
			}
			catch (Exception x) {
			}
		}
	}
}