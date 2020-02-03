package server_side;

import java.util.ArrayList;

public class State {

	private int row;
	private int col;
	private int cost; // cost to reach this state
	private State Father; // the state we came from to this state
	ArrayList<State> ListOfChildren; // list of the neighbors states
	
	
	public State(int row,int col,int cost){ // CTOR
	this.col=col;
	this.row=row;
	this.cost=cost;
	this.ListOfChildren=new ArrayList<State>();
	}
	
	public boolean equals(State s){ // it’s easier to simply overload
		if(this.col==s.col && this.row==s.row) {return true;}
		return false;
		}
	public int getCost() {
		return cost;
	}
	public void setCost(int d) {
		this.cost = d;
	}
	public State getFather() {
		return Father;
	}
	public void setFather(State father) {
		Father = father;
	}
	public void setCameFrom(State n) {
		this.Father = n;
		
	} 

	public int getRow() {
		return this.row;
	}

	public void setRow(int row) {
		this.row = row;
	}

	public int getCol() {
		return this.col;
	}

	public void setCol(int col) {
		this.col = col;
	}

	public void addtoListOfChildren(State s) {
		this.ListOfChildren.add(s);
	}

	public ArrayList<State> getListofniebors() {
		return this.ListOfChildren;
	}


	
}
