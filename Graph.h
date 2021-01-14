#pragma once
#include<iostream>
#include<cstdlib>
using namespace std;
/*
|Verticies|         |<---                adjacency list                 --->|

+---------+         
|         |         +------+------+------+------+------+------+------+------+
| pointer |-------->| node | node | node | node | node | node | node | node |
|         |         +------+------+------+------+------+------+------+------+
+---------+
|         |         +------+------+------+------+------+------+------+------+
| pointer |-------->| node | node | node | node | node | node | node | node |
|         |         +------+------+------+------+------+------+------+------+
+---------+
|         |         +------+------+------+------+------+------+------+------+
| pointer |-------->| node | node | node | node | node | node | node | node |
|         |         +------+------+------+------+------+------+------+------+
+---------+
|         |         +------+------+------+------+------+------+------+------+
| pointer |-------->| node | node | node | node | node | node | node | node |
|         |         +------+------+------+------+------+------+------+------+
+---------+
*/
class Graph {

	//colors used to detect cycles
	enum Color { WHITE, GRAY, BLACK };

	//struct for an adjacency list node
private:
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
	static void exe(); // user input 
	//void getEdge(int& src, int& des);
};

ostream& operator <<(ostream& out, Graph& g);
//istream& operator >>(istream& out, Graph& g);