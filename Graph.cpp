#include <iostream>
#include "Graph.h"
using namespace std;

void printGuide(int v);

Graph::AdjListNode::
AdjListNode(int d):data(d), next(0) {};

Graph::
Graph(int v) : V(v)
{
	arr = new AdjList[V];
	for (int i = 0; i < V; i++) {
		arr[i].head = NULL;
	}
}
Graph::
~Graph()
{

	//loop over ech adjacency list node with 2 pointer root and nextNode
	//delete vertices @root then move to nextNode, then move nextNode
	//first check that adjaceny list is not NULL, if NULL then skip this list.
	for (int i = 0; i < V; i++) {
		if (arr[i].head == NULL)
			continue;
		AdjListNode* root = arr[i].head;
		AdjListNode* nextNode = arr[i].head->next;
		while (nextNode != NULL) {
			delete(root);
			root = nextNode;
			nextNode = nextNode->next;
		}
		delete(root);
	}
	delete[] arr; // delete the graph at the end.
}


void Graph::
addEdge(int src, int dest) 
{

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
void Graph::
printGraph() 
{
	//loop over each adjacent list
	for (int i = 0; i < V; i++) {
		AdjListNode* root = arr[i].head;
		cout << "Vertex " << i << " is connected to:";
		//loop over each node in list
		while (root != NULL) {
			cout << endl << "[" << i << "] -->" <<  "[" << root->data << "]";
			root = root->next;
		}
		cout << endl;
	}
}

// Recursive function to find if there is back edge 
// in DFS subtree tree rooted with 'u' 
bool Graph::
DFSUtil(int v, int color[])
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


void Graph::exe()
{
	int src, des;
	char cont = 0;
	int vertices;

	//Prompt user to create a new graph
	//
	cout << " <New Graph?>" << endl <<  "1: yes" << endl << "0: no" << endl << " >>>  ";
	cin >> cont;
	cout << endl;

	//loop until the user wishes to stop creating ghraph
	//
	while (cont)
	{
		cout << "############################____Initializing a new graph____############################" << endl << endl;
		vertices = 0;

		//loop until <vertices> is more than 1
		//
		while (vertices < 1) {
			cerr << "<How many vertices?>";
			cout << endl <<  " Between 1 and 100";
			cout << endl << " >>>  ";
			cin >> vertices;
			cout << endl;
		}

		Graph g(vertices);
		printGuide(vertices);

		cout << "      _____Create edges between vertices____"<< endl;
		cout << "	__NEGATIVE <Destination> ends graph__" << endl;
		cout << ">> Source index" << endl << "  >>>  ";
		cin >> src;
		cout << endl << ">> Destination index" << endl << "  >>>  ";
		cin >> des;
		cout << endl;

		while (src >= 0 && des >= 0) {
			g.addEdge(src, des);

			cout << endl << "        ____UPDATES____";
			cout << endl << endl << " __Updated Gprah__";
			cout <<  endl << g << endl;
			if (g.isCyclic()) {
				cout << "__Cycles__";
				cout << endl << ">> YES" << endl << endl;
			}
			else
			{
				cout << "__Cycles__";
				cout << endl << ">> NO" << endl << endl;
			}

			cout << "      _____Create edges between vertices____" << endl;
			cout << "	__NEGATIVE <Destination> endS graph__" << endl;
			cout << ">> Source index" << endl << "  >>>  ";
			cin >> src;
			cout << endl << ">> Destination index" << endl << "  >>>  ";
			cin >> des;
			cout << endl;

		};

		cout << "***************************" << endl;
		cout << " <New Graph?>" << endl << "1: yes" << endl << "0: no" << endl << " >>>  ";
		cin >> cont;
		cout << endl;
	}

	cout << "< !! Programm has finished !!>" << endl;
	exit(0);

}

ostream& operator <<(ostream& out, Graph& g)
{
	g.printGraph();
	return out;
}

//istream& operator >>(istream& out, Graph& g)
//{
//	g.getEdge();
//	return out;
//}
//void Graph::getEdge(int& src, int& des) {
//	cout << "      _____Create edges between vertices____" << endl;
//	cout << "	__NEGATIVE <Destination> ends graph__" << endl;
//	cout << ">> Source index" << endl << "  >>>  ";
//	cin >> src;
//	cout << endl << ">> Destination index" << endl << "  >>>  ";
//	cin >> des;
//	cout << endl;
//}

void printGuide(int v) {
	cout << endl << "        ___________Guide___________";
	cout << endl << "       Input must be between 1 and " << v;
	cout << endl << "    Enter a NEGATIVE <Destination> to exit";
	cout << endl << endl << "                Examble code";
	cout << endl << "    *************************************";
	cout << endl << "              Source index: 2 ";
	cout << endl << "              Destination index: " << v;
	cout << endl << "    *************************************";
	cout << endl << endl << " An edge will be created between vertex 2 and " << v;
	cout << endl << "              [2] --- > [" << v << "]";
	cout << endl << "        ___________   ___________";
	cout << endl << "                   END" << endl << endl;
}