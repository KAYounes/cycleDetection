#pragma once
#include<iostream>
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

private:

	class AdjListNode
	{
	public:
		AdjListNode(int d);
		AdjListNode();
		int index;
		AdjListNode* next;
	};
		
public:
	Graph(int v = 0);
	~Graph();
	void addEdge(int, int);
	void printGraph();
	bool DFSUtil(int v, int color[]);
	bool isCyclic();
	void fetchEdge();
	void deleteEdge(int src, int des);
	bool checkEdge(int src, int dest);
private:
	enum Color { WHITE, GRAY, BLACK };
	int V;
	AdjListNode** verticies;
};


	
ostream& operator <<(ostream& out, Graph& g);

istream& operator >>(istream& in, Graph& g);