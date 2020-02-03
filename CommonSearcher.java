package server_side;

import java.util.PriorityQueue;

public abstract class CommonSearcher implements Searcher{ //abstract class of same function in common searchers
	
    protected PriorityQueue<State> openList;
	private int evaluatedNodes;
	public CommonSearcher() {
	openList=new PriorityQueue<State>(100,new StateComprator());
	evaluatedNodes=0;
	}
	protected State popOpenList() { //number of nodes that we finished to handle;
	evaluatedNodes++;
	return openList.poll();
	} 
	@Override
	public abstract String search(Searchable s);
	@Override
	public int getNumberOfNodesEvaluated() {
	return evaluatedNodes;
	}



}
