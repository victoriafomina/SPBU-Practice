#include "graph.h"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	/*vector<vector<int>> adj(4);
	for (int i = 0; i < 4; i++)
	{
		adj[i].resize(4);
	}
	adj[0][0] = 0; adj[0][1] = 6; adj[0][2] = 0; adj[0][3] = 5;
	adj[1][0] = 6; adj[1][1] = 0; adj[1][2] = 4; adj[1][3] = 0;
	adj[2][0] = 3; adj[2][1] = 4; adj[2][2] = 0; adj[2][3] = 0;
	adj[3][0] = 0; adj[3][1] = 2; adj[3][2] = 0; adj[3][3] = 0;
	Graph g(adj, "adjacency");
	g.printAdjancencyMatrix();
	g.printIncidenceMatrix();*/

	vector<vector<int>> inc(5);
	for (int i = 0; i < 5; i++)
	{
		inc[i].resize(4);
	}
	inc[0][0] = 6; inc[1][0] = -3; inc[2][0] =  5; inc[3][0] = 0; inc[4][0] =  0;
	inc[0][1] = 6; inc[1][1] =  0; inc[2][1] =  0; inc[3][1] = 4; inc[4][1] = -2;
	inc[0][2] = 0; inc[1][2] =  3; inc[2][2] =  0; inc[3][2] = 4; inc[4][2] =  0;
	inc[0][3] = 0; inc[1][3] =  0; inc[2][3] = -5; inc[3][3] = 0; inc[4][3] =  2;
	Graph g(inc, "incidence");
	g.printAdjancencyMatrix();
	g.printIncidenceMatrix();
	return 0;
}