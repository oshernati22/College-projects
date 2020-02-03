package server_side;

public class SolveTask implements Solver {  //object adapther.

	Searcher search;
	
	@Override
	public String solve(Searchable s) {
		return search.search(s);
	}

	public SolveTask(Searcher search) {
		super();
		this.search = search;
	}

}
