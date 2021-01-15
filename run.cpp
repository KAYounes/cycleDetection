#include <iostream>
#include <string>
#include <fstream>
#include "Graph.h"
using namespace std;

void printGuide(int v) {
	cout << endl << "<_#_> User Guide <_#_>";
	cout << endl << "> The index of verticies starts from 1 up to " << v;
	cout << endl << "> input 'a' to add an edge between 2 vertices";
	cout << endl << "> input 'd' to remove an edge between 2 vertices";
	cout << endl << "> input 'p' to print the connections in the graph";
	cout << endl << "> input 'q' to finish the editing the graph";
	cout << endl << "> The code checks for a cycle each time an edge is added";
	cout << endl;
}

void promtAdd(int* src, int* dest) {
	cout << endl << "Add edge";
	cout << endl << "> from node >> "; cin >> *src; cout << "> to node >> "; cin >> *dest; cout;
}

void promtDelete(int* src, int* dest) {
	cout << endl << "Remove edge";
	cout << endl << "> from node >> "; cin >> *src; cout << "> to node >> "; cin >> *dest; cout;
}

int main()
{
	int src, dest, vertices;
	bool cont = 1;

	//loop until the user wishes to stop creating ghraph
	//
	while (cont)
	{
		cout << "<_###_> Initializing a new graph <_###_>" << endl << endl;
		vertices = 0;

		//loop until <vertices> is more than 1
		//
		cout << "<_#_> Specify number of vertices in this graph ?<_#_>";
		cout << endl << "# V >> ";
		cin >> vertices;

		while (vertices < 1 || vertices > 50) {
			cerr << "!__RANGE BETWEEN [1] --> [50]__!";
			cout << endl << "Number of verticies > ";
			cin >> vertices;
		}


		Graph g(vertices);
		printGuide(vertices);

		char action= 'c';
		while (action != 'q')
		{
			cout << endl << "**********************";
			cout << endl << "<> Choose Action <>";
			cout << endl << "a: add_edge   d: delete_edge   q: quit   p: print";
			cout << endl << "action > ";  cin >> action; cout << endl;
			switch (action){
			case 'a': 
				promtAdd(&src, &dest);
				if (!(g.checkEdge(src - 1, dest - 1))) {
					cout << "!___EDGE INDEX OUT OF BOUND - EDGE NOT Added!" << endl;
					break;
				}
				g.addEdge(src - 1, dest - 1);
				cout << ">> Adding edge <<";
				cout << endl << "Cycle detected?  >> " << (g.isCyclic() ? "YES" : "NO") << endl;
				if (g.isCyclic()) {
					action = 'q';
					cout << "!__CYCLE DETECTED TERMINATING GRAPH, FINAL GRAPH FORM __!" << endl;
					cout << g << endl;
				}
				break;

			case 'd':
				promtDelete(&src, &dest);
				if (!(g.checkEdge(src - 1, dest - 1))) {
					cout << "!___EDGE INDEX OUT OF BOUND - EDGE NOT DELETED___!" << endl;
					break;
				}
				g.deleteEdge(src - 1, dest - 1);
				cout << ">> Deleting edge <<"<< endl;
				break;

			case 'c' :
				continue;
				break;

			case 'p':
				cout << g;
				break;

			case 'q':
				cout << "!___TERMINATING GRAPH___!" << endl;
				continue;

			default:
				cout << endl << "!___INVALID ACTION___!" << endl;
				continue;
			}

		};

		cout << endl << "<_#_> New Graph? <_#_>";
		cout << endl << " 1: yes / 0: no >> ";
		cin >> cont;
		cout << endl;
	}

		cout << "!___TERMINATING APP___!" << endl;
		exit(0);
	}



