#pragma once

#include"Graph.h"
#include"Graph.h"
#include<stack>
class Dfs
{
public:

	int time;
	list<Vertex>* listtoprint; // list of the topological sort algoritem
	Dfs(Graph g)
	{
		this->time = 0;
		this->listtoprint = new list<Vertex>[g.getNumOfVertex()];
	}

	void dfs(Graph graph) {   //dfs algoritem
		while (!this->listtoprint->empty())
		{
			this->listtoprint->pop_front();
		}
		vector<Vertex>::iterator iter;
		for (iter = graph.getGraph()->begin(); iter != graph.getGraph()->end(); iter++) {
			if (*(iter->getColor()) == 1) {
				time = 0;
				dfsVisit(*iter);
			}
		}
	}
	void dfsVisit(Vertex ver) {  // helping function to dfs 

		ver.setColor(2);
		this->time++;
		ver.setEterTime(this->time);
		if (ver.getNumOfNiebores() == 0)
		{
			this->listtoprint->push_front(ver);
			return;

		}
		list<Vertex>::iterator it ;
		for (it = ver.getList()->begin(); it != ver.getList()->end();it++) {
			if (*it->getColor() == 1)
			{
				it->setDady(ver);
				dfsVisit(*it);
			}
		}
		ver.setColor(3);
		this->time++;
		ver.setExiTime(time);
		if (*(ver.getColor()) == 3)
		{
			this->listtoprint->push_front(ver);
		}
	}

	void toplogicalSort(Graph graph) {  // funtction who call dfs and print the topological sort
		this->dfs(graph);
		list<Vertex>::iterator it2;
		for (it2 = listtoprint->begin(); it2 != listtoprint->end(); it2++) {
			it2->printVertex(*it2);
			cout << "-->";

		}
	}
};