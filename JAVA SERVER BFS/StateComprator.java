package server_side;

import java.util.Comparator;


public class StateComprator implements Comparator<State>{

	@Override
	public int compare(State o1, State o2) {
		if(o1.getCost()+o1.getFather().getCost() > o2.getCost()+o2.getFather().getCost())
		{
			return 1;
		}
		else if(o1.getCost() + o1.getFather().getCost() < o2.getCost()+ o2.getFather().getCost()) {
			return -1;
		}
		return 0;
	}

	
	

}
