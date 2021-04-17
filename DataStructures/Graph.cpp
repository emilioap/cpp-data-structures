#include "Graph.h"
#include <iostream>

Graph::Graph(int max, int nullEdge) {
	NULL_EDGE = nullEdge;
	maxVertices = max;
	numVertices = 0;

	vertices = new Vertex[maxVertices];
	marks = new bool[maxVertices];
	edges = new int*[maxVertices];

	for (int row = 0; row < maxVertices; row++)
		edges[row] = new int[maxVertices];

	//Populating the matrix cells with null values
	for (int row = 0; row < maxVertices; row++)
		for (int col = 0; col < maxVertices; col++)
			edges[row][col] = NULL_EDGE;
}

Graph::~Graph() {
	delete[] vertices;
	delete[] marks;

	//Deallocate all lines
	for (int row = 0; row < maxVertices; row++) {
		delete[] edges[row];
	}
	delete[] edges;
}

int Graph::getIndex(Vertex vertex) {
	int index = 0;

	//Simple sequential search
	while (!(vertex.getName() == vertices[index].getName()))
		index++;
	return index;
}

Vertex Graph::getVertexByIndex(int index) {
	return vertices[index];
}

int Graph::getIndexByName(std::string name) {
	int index = 0;
	while (!(name == vertices[index].getName()))
		index++;
	return index;
}

void Graph::addVertex(Vertex vertex) {
	vertices[numVertices] = vertex;
	numVertices++;
}

void Graph::addEdge(Vertex from, Vertex to, int weigth) {
	int row = getIndex(from);
	int col = getIndex(to);
	edges[row][col] = weigth;
	edges[col][row] = weigth;
}

int Graph::getWeight(Vertex from, Vertex to) {
	int row = getIndex(from);
	int col = getIndex(to);
	return edges[row][col];
}

void Graph::getAdjacents(Vertex vertex, Queue& adjVertices) {
	int fromIndex = getIndex(vertex);
	int toIndex;

	for (toIndex = 0; toIndex < numVertices; toIndex++) {
		//If exists the adjacency vertex
		if (edges[fromIndex][toIndex] != NULL_EDGE)
			adjVertices.enqueue(vertices->getName()[toIndex]);
	}
}

void Graph::clearMasks() {
	for (int i = 0; i < numVertices; i++)
		marks[i] = false;
}

void Graph::markVertex(Vertex vertex) {
	int index = getIndex(vertex);
	marks[index] = true;
}

bool Graph::isMarked(Vertex vertex) {
	int index = getIndex(vertex);
	return marks[index];
}

void Graph::printMatrix() {
	for (int i = 0; i < numVertices; i++) {
		for (int j = 0; j < numVertices; j++)
			std::cout << edges[i][j] << ",";
		std::cout << std::endl;
	}
}