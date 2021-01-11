#include<iostream>
#include"Graph.h"
using namespace std;
void user();
int main()
{
	Graph::userInterface();
}

//void user()
////{
////	cout << "Do you want to create a Graph ? Enter y: yes  or n:no" << endl;
////	cout << "Your Answer: ";
////	char c;
////	cin >> c;
////	cout << endl;
////	while (c == 'y' || c == 'Y')
////	{
////		cout << "Lets GO !" << endl;
////		// vertices 
////		cout << "Enter number of vertices: ";
////		int vertices;
////		cin >> vertices;
////		if (vertices > 0) {
////			cout << endl;
////			/************/
////			Graph g(vertices);
////			g.userInterface();
////			cout << "***************************" << endl;
////
////			cout << "Do you want to create a Graph ? Enter y: yes  or n:no" << endl;
////			cout << "Your Answer: ";
////			cin >> c;
////			cout << endl;
////		}
////	}
////
////	cout << "Thanks for using our Program :>" << endl;
//
//	
//}