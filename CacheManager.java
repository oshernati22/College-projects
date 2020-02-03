package server_side;

public interface CacheManager<problem,soultion>
{
	public Boolean isSolutionExist(String p);
	
	public String getSolution(String p);
	
	public void saveSolution(String p, String s);

}
