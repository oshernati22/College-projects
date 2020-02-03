package server_side;

import java.util.ArrayList;
import java.util.HashSet;

public class Bfs extends CommonSearcher { // BFS searcher


	public Bfs() {
		super();
		// TODO Auto-generated constructor stub
	}

	@Override
	public String search(Searchable s) {
		addToOpenList(s.getInitialState()); // add to open
		ArrayList<State> closedSet=new ArrayList<State>();
		
		while(openList.size()>0){
		State n=popOpenList();// dequeue from the open
		closedSet.add(n);  // add to the close set
		 
		if(n.equals(s.getGoalState())) {
		return backTrace(s.getGoalState(), s.getInitialState());
		// private method, back traces through the parents
		}
		
		ArrayList<State> successors=s.getAllPossibleStates(n); //all the neibores of n
		  
		for(State state : successors){
		if(!closedSet.contains(state) && ! openListContains(state)){ //if it not in the open list add to open list
		state.setCameFrom(n);
		addToOpenList(state);
		} 
		else if(closedSet.contains(state)) { //if its in the close set remove from the open set
			openList.remove(state);
			continue;
		}
		else if(state.getCost() + state.getFather().getCost() > state.getCost() +n.getCost()  ) { //if we can improve the way we will change the father to the best way
				state.setCameFrom(n);
				openList.remove(state);
				state.setCameFrom(n);
				addToOpenList(state);
			}
		}
			
		}

		return null;
	}
	
	
	

	private boolean openListContains(State state) {
		
		return openList.contains(state);
	}
	
 

	private String backTrace(State goalState, State initialState) { //give us the way in words of right left up down.
         StringBuilder sb=new StringBuilder();
		int row,col,rowoffather,coloffather;
		while(!initialState.equals(goalState))
		{
	        row=goalState.getRow();
	        col=goalState.getCol();
	        rowoffather=goalState.getFather().getRow();
	        coloffather = goalState.getFather().getCol();
	        if(row>rowoffather) {
	        	sb.insert(0,",Down");
	        }
	        
	       if(row<rowoffather) {
	        	sb.insert(0,",Up");
	        }
	        if(col>coloffather) {
	        	sb.insert(0,",Right");
	        }
	       if(col<coloffather) {
	        	sb.insert(0,",left");
	        }
	        goalState=goalState.getFather();
		}
		 String answer =sb.substring(1);
		return answer;
	}

	private void addToOpenList(State initialState) {
	
		openList.add(initialState);
		
	}
	
	

	

}
