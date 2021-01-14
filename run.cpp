#include <iostream>
#include <string>
#include <fstream>
#include "Graph.h"
using namespace std;

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

void promtAdd(int* src, int* dest) {
	cout << endl << "Addge edge";
	cout << endl << "> from node "; cin >> *src; cout << "> to node "; cin >> *dest; cout;
}

void promtDelete(int* src, int* dest) {
	cout << endl << "Remove edge";
	cout << endl << "> from node "; cin >> *src; cout << "> to node "; cin >> *dest; cout;
}

int main()
{
	int src = -2;
	int dest = -2;
	bool cont = 0;
	int vertices;

		//Prompt user to create a new graph
		//
		cout << "___<New Graph?>";
		cout << endl << "1: yes";
		cout << endl << "0: no";
		cout << endl << "> ";
		cin >> cont;
		cout << endl;

		//loop until the user wishes to stop creating ghraph
		//
		while (cont)
		{
			cout << "#### Initializing a new graph" << endl << endl;
			vertices = 0;

			//loop until <vertices> is more than 1
			//
			while (vertices < 1) {
				cerr << "<Specify number of vertices?>  [min_1 <--> max_100]";
				cout << endl << "> ";
				cin >> vertices;
			}


			Graph g(vertices);
			printGuide(vertices);

			char action= 'c';
			while (action != 'q')
			{
				
				cout << endl << "<choose action>";
				cout << endl << "a: add_edge   d: delete_edege   q: quit   p: print";
				cout << endl << "action > ";  cin >> action; cout << endl;
				switch (action){
				case 'a': 
					promtAdd(&src, &dest);
					g.addEdge(src - 1, dest - 1);
					cout << "edge added ___ ";
					cout << endl << "Cycle detected?  >" << (g.isCyclic() ? "YES" : "NO");
					break;

				case 'd':
					promtDelete(&src, &dest);
					g.deleteEdge(src - 1, dest - 1);
					cout << "edge deleted" << endl;
					break;

				case 'c' :
					continue;
					break;

				case 'p':
					cout << g;
					break;

				default:
					continue;
				}

			};

			cout << " <New Graph?>" << endl << "1: yes" << endl << "0: no" << endl << " >>>  ";
			cin >> cont;
			cout << endl;
		}

		cout << "< !! Programm has finished !!>" << endl;
		exit(0);
	}
			//promtAdd(&src, &dest);

			//while (src != -2 || dest != -2){
			//	if (src > 0 && dest > 0) {
			//		g.addEdge(src, dest);
			//	}
			//	cout << endl << "___Updated Gprah";
			//	cout << endl << g << endl;

			//	cout << "___Cycles Found";
			//	cout << endl << ">> " << (g.isCyclic() ? "YES" : "NO");

			//	promtDelete(&src, &dest);

			//	if (src > 0 && dest > 0) {
			//		g.deleteEdge(src, dest);
			//		
			//		cout << endl << "___Updated Gprah";
			//		cout << endl << g << endl;
			//	}

			//		promtAdd(&src, &dest);

			//};



