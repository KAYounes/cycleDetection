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

/*
	This header file defines the graph class.

	# Member variables:
		- Node			 : a signle node in the adjacency list
		- Color			 : enumirations of the colors used to detect a cycle
		- vertices_count : total number of verticies in the graph
		- verticies		 : a 1D array of a Node pointer

	# Basic operations are:
		- Constructor	 : allocates a graph in memory
		- Destructor	 : deletes the graph from memory
		- addEdge		 : adds an edge between two verticies
		- printGraph	 : prints a formated graph
		- DFSUtil		 : performs a Depth first search
		- isCyclic		 : detects cycles in the graph
		- deleteEdge	 : removes an edge between two verticies
		- checkEdge		 : checks the source verticies and destination verticies of an edge is valid/within bound
		- <<			 : output operator overloading
*/


class Graph {

private:
	/*
	Node class

		# Member variables :
			- index		:index of the vertex
			- next		: a pointer to a Node 
		# Basic operations are :
			- constructors : allocates a Node in the memory
	*/
	class Node
	{
	public:
		//takes index and initialization a node with index [i] and next [NULL];
		Node(int data);
		Node();
		int index;
		Node* next;
	};
	enum Color { WHITE, GRAY, BLACK };
	int vertices_count;
	Node** verticies;

	bool DFSUtil(int vertices_count, int color[]);
	/*----------------------------------------------------------------------


	definiton: helper function, performs a recursive DFS on graph

	fails:

	condition:
	-----------------------------------------------------------------------*/

public:
	Graph(int vertices_count = 0);
	/*----------------------------------------------------------------------

	definiton: take <vertices_count> and construct a graph with <vertices_count> verticies
	
	fails: no free contiguous memory

	condition: <vertices_count> is more than one
	-----------------------------------------------------------------------*/


	~Graph();
	/*----------------------------------------------------------------------

	definiton: deallocates a graph from memory

	fails: 

	condition: 
	-----------------------------------------------------------------------*/

	void addEdge(int source_node_index, int destination_node_index);
	/*----------------------------------------------------------------------

	definiton: takes the src node and dest node, and addes a node with index[destination_node_index] to the adjacency list of vertix[source_node_index]

	fails: no free contiguous memory for a new node

	condition: <source_node_index> and <destination_node_index> are between 0 and (V - 1)
	-----------------------------------------------------------------------*/

	void printGraph();
	/*----------------------------------------------------------------------

	definiton: visualise the connections between a graph

	fails: 

	condition: 
	-----------------------------------------------------------------------*/

	bool isCyclic();
	/*----------------------------------------------------------------------

	definiton: assigns a <WHITE> color to all verticies in <color> array. calls <DFSUtil> for each <WHITE> node

	fails: no free contiguous memory

	condition:

	return: true if cycle is detected, false otherwise
	-----------------------------------------------------------------------*/

	void deleteEdge(int source_node_index, int destination_node_index);
	/*----------------------------------------------------------------------

	definiton: removes node [destination_node_index] from the adjacency list of node [source_node_index]

	fails: 

	condition: <source_node_index> and <destination_node_index> are between 0 and (V - 1)
	-----------------------------------------------------------------------*/

	bool checkEdge(int source_node_index, int destination_node_index);
	/*----------------------------------------------------------------------

	definiton: checks the range of the edge

	fails:

	condition: 

	returns: true if <source_node_index> and <destination_node_index> are between 0 and (V - 1); false otherwise
	-----------------------------------------------------------------------*/
};
	
ostream& operator <<(ostream& out, Graph& g);
