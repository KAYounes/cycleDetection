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

	class Node
	{
	public:
		Node(int data);
		Node();
		int index;
		Node* next;
	};
		
public:
	Graph(int vertices_count = 0);
	~Graph();
	void addEdge(int src, int dest);
	void printGraph();
	bool DFSUtil(int vertices_count, int color[]);
	bool isCyclic();
	void deleteEdge(int source_node_index, int destination_node_index);
	bool checkEdge(int source_node_index, int destination_node_index);
private:
	enum Color { WHITE, GRAY, BLACK };
	int vertices_count;
	Node** verticies;
};


	
ostream& operator <<(ostream& out, Graph& g);

istream& operator >>(istream& in, Graph& g);