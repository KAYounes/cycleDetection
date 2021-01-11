#include <iostream>
#include "Graph.h"
using namespace std;
//create a new node
/*
Graph::AdjListNode* Graph::newAdjListNode(int data) {
	AdjListNode* nptr = new AdjListNode;
	nptr->data = data;
	nptr->next = NULL;
	return nptr;
}
*/

Graph::AdjListNode::AdjListNode(int d) :data(d), next(0)
{

}
// our constructor 
Graph::Graph(int v) : V(v)
{
	//create an array of adjacency list. size of array - V
	arr = new AdjList[V];
	//initialize with NULL (e.g root=NULL)
	for (int i = 0; i < V; i++) {
		arr[i].head = NULL;
	}
}
Graph::~Graph()
{
	for (int i = 0; i < V; i++) {
		// two pointers 
		AdjListNode* root = arr[i].head;
		AdjListNode* nextNode = arr[i].head->next;
		//loop over each node in list
		while (nextNode != NULL) {
			delete(root);
			root = nextNode;
			nextNode = nextNode->next;
		}
		delete(root);
	}
	delete[] arr;
}

//add an edge to an undirected Graph
void Graph::addEdge(int src, int dest) {
	//Add an edge from src to dest. A new node added to the adjacency list of src
	//node added at beginning
	if (src < V && dest < V && V > 0) {
		AdjListNode* nptr = new AdjListNode(dest);
		nptr->next = arr[src].head;
		arr[src].head = nptr;
	}
	else cout << "<<Cannot Connect>>" << endl;
	//connect from dest to src (since undirected)
   /* nptr = newAdjListNode(src);
	nptr->next = arr[dest].head;
	arr[dest].head = nptr;
	*/
}

//function to print the graph
void Graph::printGraph() {
	//loop over each adjacent list
	for (int i = 0; i < V; i++) {
		AdjListNode* root = arr[i].head;
		cout << "Adjacency list of vertex " << i << endl;
		//loop over each node in list
		while (root != NULL) {
			cout << root->data << " -> ";
			root = root->next;
		}
		cout << endl;
	}
}

// Recursive function to find if there is back edge 
// in DFS subtree tree rooted with 'u' 
bool Graph::DFSUtil(int v, int color[])
{
	// GRAY :  This vertex is being processed (DFS 
	//         for this vertex has started, but not 
	//         ended (or this vertex is in function 
	//         call stack) 
	color[v] = GRAY;

	// Iterate through all adjacent vertices 
	AdjListNode* myNode = arr[v].head;
	while (myNode != NULL)
	{
		// If there is 
		if (color[myNode->data] == GRAY)
			return true;

		// If v is not processed and there is a back 
		// edge in subtree rooted with v 
		if (color[myNode->data] == WHITE && DFSUtil(myNode->data, color))
			return true;
		myNode = myNode->next;

	}

	// Mark this vertex as processed 
	color[v] = BLACK;

	return false;
}

// Returns true if there is a cycle in graph 
bool Graph::isCyclic()
{
	// Initialize color of all vertices as WHITE 
	int* color = new int[V];
	for (int i = 0; i < V; i++)
		color[i] = WHITE;

	// Do a DFS traversal beginning with all 
	// vertices 
	for (int i = 0; i < V; i++)
		if (color[i] == WHITE)
			if (DFSUtil(i, color) == true)
				return true;

	return false;
}


void Graph::userInterface()
{
	int src, des;

	do {
		cout << "##Enter edges between different vertices##" << endl;
		cout << "Enter any Negative number to STOP :L" << endl;
		cout << "Enter Source: ";
		cin >> src;
		cout << endl << "Enter Destination: ";
		cin >> des;
		cout << endl;
		addEdge(src, des);
		cout << "-------------------------------------------------------------------------------" << endl;
		cout << "-------------------------------------------------------------------------------" << endl;
		cout << "**Graph Represenation**" << endl;
		cout << *this << endl;
		cout << endl;
		if (isCyclic()) {
			cout << "*Answer*" << endl;
			cout << "Graph contains cycle" << endl << endl;
		}
		else
		{
			cout << "*Answer*" << endl;
			cout << "Graph doesn't contain cycle" << endl << endl;
		}
		cout << "-------------------------------------------------------------------------------" << endl;
		cout << "-------------------------------------------------------------------------------" << endl;
	} while (src >= 0 && des >= 0);

}

ostream& operator <<(ostream& out, Graph& g)
{
	g.printGraph();
	return out;
}