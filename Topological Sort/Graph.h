#pragma once
#include "Vertex.h"
#include <vector>

using namespace std;
class Graph {

private:
	vector <Vertex>* graph;     //list of the vertex of the graph
	int numofvertex;

public:
	Graph(int num);        
	void addToGraph(Vertex ver);
	void printAllGraph();
	void	printJustName(Vertex v) { cout << v.getName(); }
	void callToneibor(Vertex v) { v.printNeibours(); };
	vector<Vertex>* getGraph() { return this->graph; }
	int getNumOfVertex() { return this->numofvertex; }

	
};

Graph::Graph(int num) {
	numofvertex = num;
	this->graph = new vector<Vertex>[num];
}



void Graph::addToGraph(Vertex ver) {
	this->graph->push_back(ver);
}

void Graph::printAllGraph() {
	vector<Vertex>::iterator iter = this->graph->begin();
	while (iter != this->graph->end()) {
		printJustName(*iter);
		cout << "-->" ;
		callToneibor(*iter);

		cout << "\n" << "\n";
		iter++;
	}

}

