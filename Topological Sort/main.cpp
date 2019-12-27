#include "Vertex.h"
#include "Graph.h"
#include"DFS.h"
int main() {
	Vertex bdida1(1, "bdida1");                            // 
	Vertex bdida2(1, "bdida2");										//
	Vertex algo2(0, "Algo2");										
	Vertex algo1(2, "Algo 1");                                            // make all the vertex
	Vertex mivnenetonim(1, "Mivne Netonim");
	Vertex mavo(1, "Mavo");											//
	Vertex modelimheshovim(1, "modelim Heisovim");
	Vertex hishoviot(0, "hishoviot");						//

	bdida1.addVertex(bdida2);						//
	bdida2.addVertex(algo2);								//
	algo1.addVertex(algo2);										
	mivnenetonim.addVertex(algo1);									// conect all the vertex 
	mavo.addVertex(mivnenetonim);									
	algo1.addVertex(modelimheshovim);						//
	modelimheshovim.addVertex(hishoviot);			//

	Graph g(8);
	g.addToGraph(bdida1);
	g.addToGraph(bdida2);
	g.addToGraph(algo2);
	g.addToGraph(algo1);                     // biuld graph
	g.addToGraph(mivnenetonim);
	g.addToGraph(mavo);
	g.addToGraph(modelimheshovim);
	g.addToGraph(hishoviot);

	g.printAllGraph();

	Dfs newdfs(g);
	newdfs.toplogicalSort(g); // run topological on the graph


	return 0;
}
