#pragma once
/*
	Graph implementation following  tutorial http://www.geeksforgeeks.org/graph-and-its-representations/
*/
#include<iostream>
#include<cstdlib>
using namespace std;
//TO BE ADDED !!!!!!!!!!!!!!!!!!!!!!!
// constructor 
// destructor 
// some operator overrloading for dr. 
class Graph {
	enum Color { WHITE, GRAY, BLACK };

	//struct for an adjacency list node
public:
	class AdjListNode {
	public:
		AdjListNode(int d);
		int data;
		AdjListNode* next;
	};


	//struct for an adjacency list
	class AdjList {
	public:
		AdjListNode* head;  //pointer to head node of list
	};

	//struct for a graph. A graph as an array of adjacency lists
	//Size of array will be V (total vertices)
		// memeber variables 
	int V;
	AdjList* arr;

public:
	Graph(int v = 0);
	~Graph();
	void addEdge(int, int);
	void printGraph();
	bool DFSUtil(int v, int color[]);
	bool isCyclic();
	static void userInterface(); // user input 
};

ostream& operator <<(ostream& out, Graph& g);