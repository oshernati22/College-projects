package server_side;

public interface Searcher {
	
	public String search(Searchable s);
	public int getNumberOfNodesEvaluated();

}
