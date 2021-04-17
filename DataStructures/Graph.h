#pragma once
#include "Vertex.h"
#include "Queue.h"

class Graph {
public:
	Graph(int max = 50, int null = 0);
	~Graph();
	void addVertex(Vertex);
	void addEdge(Vertex, Vertex, int); //Implements edge weigth
	int getWeight(Vertex, Vertex);
	void getAdjacents(Vertex, Queue&); //Add in adjacency list
	void clearMasks();
	void markVertex(Vertex);
	bool isMarked(Vertex);
	void printMatrix();
	int getIndexByName(std::string name);
	Vertex getVertexByIndex(int);
private:
	int NULL_EDGE;
	int maxVertices;
	int numVertices;
	Vertex* vertices; //Arr with all vertices
	int** edges; //Adjacency matrix
	bool* marks;
	int getIndex(Vertex);
};
