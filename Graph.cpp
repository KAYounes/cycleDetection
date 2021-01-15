#include <iostream>
#include "Graph.h"
using namespace std;

void printGuide(int vertices_count);

Graph::Node::
Node(int i):index(i), next(0) {};

Graph::Node::
Node():next(0) {};

Graph::
Graph(int vertices_count) : vertices_count(vertices_count)
{
	if (vertices_count < 1) {
		cout << endl << "At least 1 vertices is needed" << endl;
		exit(-1);
	}

	verticies = new (nothrow) Graph::Node* [vertices_count]; 
	if (verticies == NULL) {
		cerr << "Cannot allocate memory";
		exit(-1);
	}
	
	for (int i = 0; i < vertices_count; i++) {
		verticies[i] = NULL;
	}
}
Graph::
~Graph()
{

	//loop over ech adjacency list node with 2 pointer root and nextNode
	//delete vertices @root then move to nextNode, then move nextNode
	//first check that adjaceny list is not NULL, if NULL then skip this list.
	for (int i = 0; i < vertices_count; i++) {
		if (verticies[i] == NULL)
			continue;
		Node* root = verticies[i];
		Node* nextNode = verticies[i]->next;
		while (nextNode != NULL) {
			delete(root);
			root = nextNode;
			nextNode = nextNode->next;
		}
		delete(root);
	}
	delete[] verticies; // delete the graph at the end.
}


void Graph::
addEdge(int source_node_index, int destination_node_index) 
{
	 
	if (checkEdge(source_node_index, destination_node_index)) {
		Node* nptr = new (nothrow) Node(destination_node_index);
		if (nptr == NULL) {
			cerr << "Cannot allocate memory";
			exit(-1);
		}

		nptr->next = verticies[source_node_index];
		verticies[source_node_index] = nptr;
		return;
	}
	
	cerr << endl << "!! >> src or dest is out of bound << !!" << endl;
	exit(-1);
}

//function to print the graph
void Graph::
printGraph() 
{
	//loop over each adjacent list
	for (int i = 0; i < vertices_count; i++) {
		Node* root = verticies[i];
		cout << "Vertex _" << i + 1 << "_ is connected to:";
		//loop over each node in list
		while (root != NULL) {
			cout << endl << "[" << i + 1<< "] --> " <<  "[" << (root->index) + 1 << "]";
			root = root->next;
		}
		cout << endl;
	}
}

// Recursive function to find if there is back edge 
// in DFS subtree tree rooted with 'u' 
bool Graph::
DFSUtil(int vertex, int color[])
{
	// GRAY :  This vertex is being processed (DFS 
	//         for this vertex has started, but not 
	//         ended (or this vertex is in function 
	//         call stack) 
	color[vertex] = GRAY;

	// Iterate through all adjacent vertices 
	Node* myNode = verticies[vertex];
	while (myNode != NULL)
	{
		// If there is 
		if (color[myNode->index] == GRAY)
			return true;

		// If v is not processed and there is a back 
		// edge in subtree rooted with v 
		if (color[myNode->index] == WHITE && DFSUtil(myNode->index, color))
			return true;
		myNode = myNode->next;

	}

	// Mark this vertex as processed 
	color[vertex] = BLACK;

	return false;
}

// Returns true if there is a cycle in graph 
bool Graph::isCyclic()
{
	// Initialize color of all vertices as WHITE 
	int* color = new (nothrow) int[vertices_count];
	if (verticies == NULL) {
		cerr << "Cannot allocate memory";
		exit(-1);
	}
	for (int i = 0; i < vertices_count; i++)
		color[i] = WHITE;

	// Do a DFS traversal beginning with all 
	// vertices 
	for (int i = 0; i < vertices_count; i++)
		if (color[i] == WHITE)
			if (DFSUtil(i, color) == true)
				return true;

	return false;
}

void Graph::deleteEdge(int src, int dest)
{
	if (!checkEdge(src, dest)) {
		cerr << endl << "invalid edge coordinates" << endl;
		exit(-1);
	}

	// Store head node 
	Graph::Node* temp = verticies[src];
	Graph::Node* prev = NULL;

	// If head node itself holds 
	// the key to be deleted 
	if (temp != NULL && temp->index == dest)
	{
		verticies[src] = temp->next; // Changed head 
		delete temp;            // free old head 
		return;
	}

	// Else Search for the key to be deleted,  
	// keep track of the previous node as we 
	// need to change 'prev->next' */ 
	while (temp != NULL && temp->index != dest)
	{
		prev = temp;
		temp = temp->next;
	}

	// If key was not present in linked list 
	if (temp == NULL)
		return;

	// Unlink the node from linked list 
	prev->next = temp->next;

	// Free memory 
	delete temp;
}

bool Graph::checkEdge(int src, int dest) {
	return (-1 < src && src < vertices_count && -1 < dest && dest < vertices_count);
}
ostream& operator <<(ostream& out, Graph& g)
{
	g.printGraph();
	return out;
}

//void Graph::fetchEdge() {
//	while (1) {
//		int src, dest;
//
//		cout << endl << endl << "#### FORM LINKS";
//		cout << endl << " > from node "; cin >> src; cout << " > to node "; cin >> dest;
//		cout << endl;
//
//		if (0 < src < V + 1) {
//			addEdge(src, dest);
//			cout << "__Edge added__";
//			cout << endl << endl << "___Updated Gprah";
//			cout << endl << *this << endl;
//
//			cout << "___Cycles Found";
//			cout << endl << ">> " << (isCyclic() ? "YES" : "NO");
//			continue;
//		}
//
//		cout << endl << "Verticies start from 1 to " << V;
//		continue;		
//	}
//}
//
//istream& operator >>(istream& in, Graph& g) {
//
//	g.fetchEdge();
//	return in;
//}
