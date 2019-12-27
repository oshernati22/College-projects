#pragma once
/*
Arik Zohar Saadi, Id: 205441264
Osher Nati, Id: 312468739
*/

#include <iostream>
#include <list>
#include<string>
using namespace std;

class Vertex
{
private:

	string name;
	int numOfniebors;
	list <Vertex>* nieborsList; // list of all the "children" of the vertex
	Vertex *dad = NULL;  // who is the vertex dad;
	int enterTime, exitTime;   // dfs viarebls
	int *color;// dfs viarebls


public:
	Vertex(int num, string name);
	void addVertex(Vertex ver);

	void printVertex(Vertex v);
	void printNeibours();
	void operator<<(Vertex* it) {cout << it->name;}
	string getName() {return this->name;}
	int* getColor() { return this->color; }
	void setColor(int color) { *(this->color) = color; }
	void setEterTime(int time) { this->enterTime=time; }
	void setExiTime(int time) { this->exitTime=time; }
	list <Vertex>* getList() { return this->nieborsList; }
	void setDady(Vertex v) { this->dad = &v; }
	int getEntertime() { return this->enterTime; }
	int getExittime() { return this->exitTime; }
	int getNumOfNiebores() { return this->numOfniebors; };

};


Vertex::Vertex(int num , string name) {
	this->color=new int(1);
	enterTime = 0;
	this->numOfniebors = num;
	this->name = name;
	if (this->numOfniebors != 0) {
		this->nieborsList = new list<Vertex>[numOfniebors];
	}
}


void Vertex::addVertex(Vertex ver){
	this->nieborsList->push_back(ver);
	ver.dad = this;
}

void Vertex::printVertex(Vertex v) {
	cout << v.name;
	
}


void Vertex::printNeibours() {
	if (this->numOfniebors != 0) {
		list<Vertex>::iterator it = this->nieborsList->begin();
		while (it != this->nieborsList->end()) {
			printVertex(*it);
			cout << ","<<"";
			it++;
		}
	}
	else { cout << "none"; }
}

