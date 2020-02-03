package test;

import server_side.MyClientHandler;
import server_side.MySerialServer;
import server_side.Server;
import server_side.SolveTask;
import server_side.Solver;
import server_side.Bfs;
import server_side.CacheManager;
import server_side.ClientHandler;
import server_side.FileCacheManager;
import server_side.Searcher;

public class TestSetter {
	

	static Server s; 
	
	public static void runServer(int port) {  // Initialize the server
		
		Searcher search = new Bfs();
		Solver<String ,String> solve=new SolveTask(search); //  Initialize with hour bfs searcher
		CacheManager<String,String> cm =new FileCacheManager<String,String>();
		ClientHandler c = new MyClientHandler<String, String>(solve, cm);
		s=new MySerialServer(port,c); 
		s.open(c);
	
	}

	public static void stopServer() {
		s.stop();
	}
	

}
