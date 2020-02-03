package server_side;

import java.awt.List;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.ArrayList;

public class MyClientHandler<problem, soultion> implements ClientHandler {// 

	Solver<problem, soultion> solve;
	private CacheManager<String, String> cm;
	
	public MyClientHandler(Solver<problem, soultion> solve, CacheManager<String, String> cm) {
		super();
		this.solve=solve;
		this.cm = cm;
	}

	@Override // protocol 
	public void handleClient(InputStream inputStream, OutputStream outputStream) throws IOException { // client handler who get specific problem of mat and start and end point and return the short way to exite.
		PrintWriter out = null;
		BufferedReader in = null;
		out = new PrintWriter(outputStream); // sending information form Ram to the outpotstream.
		in = new BufferedReader(new InputStreamReader(inputStream)); //Extract information to Ram
		int mat[][]=new int [4][4];
		String line;
		String[] startpoint,endpoint;
		String[] buffer;
		int i=0;
		int num=0;
		while (!(line = in.readLine() ).equals("end")) { //Extract thw mat from the buffer
			buffer= line.split(",");
			for(int j=0;j<mat.length;j++)
			{
				mat[i][j]=Integer.parseInt(buffer[num]);
				num++;
			}	
			num=0;
			i++;
		}
		line=in.readLine();//extract the start point
		startpoint=line.split(",");
		line=in.readLine(); //extract the end point
		endpoint=line.split(",");
		
		Searchable maze= new MazeDomain(startpoint,endpoint,mat); // craete amaze
		Searcher search= new Bfs(); //create feet searcher
		String realanswer=search.search(maze); // get the answer
		out.println(realanswer);// send answer to the client
		out.flush();

		in.close();
		out.close();
		
		inputStream.close();
		outputStream.close();
		}
	

		
	}


