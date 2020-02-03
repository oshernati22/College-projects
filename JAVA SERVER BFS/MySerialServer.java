package server_side;


import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.SocketTimeoutException;

public class MySerialServer implements Server //Initializes the specific server according to the client and call for the feet client handler to solve the problem.
{

	private int port;
	private ClientHandler ch;
	private volatile boolean stop;
	
	public MySerialServer(int port,ClientHandler c) {
	this.port=port;
	this.ch=c;
	stop=false;
	}
	
	
	@Override
	public void open(ClientHandler c) {
		new Thread(()->{
			try {
				runaServer(c);
			} catch (Exception e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}).start(); 
	}

	@Override
	public void stop() {
		stop= true;
	}
	
	
	private void runaServer(ClientHandler c) throws Exception  {
		
		ServerSocket server= new ServerSocket(port);
		server.setSoTimeout(1000);
		while(!stop) {
		try {
			Socket aclient=server.accept();
		try {
			c.handleClient(aclient.getInputStream(), aclient.getOutputStream());
			aclient.close();
			} catch (IOException e) {}
			} catch(SocketTimeoutException e) {}
		}
			server.close();
		
	}
}

			