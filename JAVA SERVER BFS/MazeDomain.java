package server_side;


import java.util.ArrayList;

public class MazeDomain implements Searchable { // build the maze

	State intialstate; // start point
	State goalstate;  // end point
	int arr[][] ;   //buffer
    State mat[][]; //the maze
	public MazeDomain(String[] buffer,String[] buffer2,int arr[][]) {
		super();
		this.arr = arr;
		mat = new State[4][4];
		this.createmaze();
		this.setniebores();
		this.setIntialstate(mat[Integer.parseInt(buffer[0])][Integer.parseInt(buffer[1])]);
		this.setGoalstate(mat[Integer.parseInt(buffer2[0])][Integer.parseInt(buffer2[1])]);
		
	}
 
	public void setIntialstate(State intialstate) {
		this.intialstate = intialstate;
	}


	public void setGoalstate(State goalstate) {
		this.goalstate = goalstate;
	}


	@Override
	public ArrayList<State> getAllPossibleStates(State s) {
	return  s.ListOfChildren;
	}
	
	public void createmaze() {
		for(int i =0;i<arr.length;i++)
		{ 	 
			for(int j=0;j<arr.length;j++) 
			{
				mat[i][j]=new State(i,j,arr[i][j]);
				 
			}
		}
			
		}
	public void setniebores() {
		for(int i =0;i<arr.length;i++)
		{ 	 
			for(int j=0;j<arr.length;j++) 
			{
				if(i!=0) {
					mat[i][j].addtoListOfChildren(mat[i-1][j]);
				}
				if(j!=0) {
					mat[i][j].addtoListOfChildren(mat[i][j-1]);
				}
				if(i!=arr.length-1) {
					mat[i][j].addtoListOfChildren(mat[i+1][j]);
				}
				if(j!=arr.length-1) {
					mat[i][j].addtoListOfChildren(mat[i][j+1]);
				}
				
			}
		}
		
	}

	@Override
	public State getInitialState() {
	return this.intialstate;
	}

	@Override
	public State getGoalState() {
		return this.goalstate;
	}
	
	}



