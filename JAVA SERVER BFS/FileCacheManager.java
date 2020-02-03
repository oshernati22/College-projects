package server_side;

import java.util.HashMap;
import java.util.Map;

public class FileCacheManager<problem, soultion> implements CacheManager<problem, soultion> // file cach manger not used this project
{
	

	Map<String, String> cach;
	
	public FileCacheManager() {
		cach=new HashMap<String, String>();
		}
	
	@Override
	public Boolean isSolutionExist(String p) {
		return cach.containsKey(p);
		
	}

	@Override
	public String getSolution(String p) {
		return cach.get(p);
	}

	@Override
	public void saveSolution(String p, String s) {
	cach.put(p,s);
		
	}

}
