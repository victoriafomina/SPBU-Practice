#include "graph.h"

using namespace std;

Graph::Graph(std::vector<std::vector<int>> const & adjacencyMatrix)
{
	this->adjacencyMatrix = adjacencyMatrix;
	adjancencyMatrixToIncidence();
}
Graph::Graph(std::vector<std::vector<int>> const & incidenceMatrix)
{
	this->incidenceMatrix = incidenceMatrix;
	incidenceMatrixToAdjancency();
}
Graph::~Graph()
{}

int Graph::getNumberOfVertexes() const
{
	return adjacencyMatrix.size();
}
int Graph::getNumberOfEdges() const
{
	return incidenceMatrix[0].size();
}

void Graph::adjancencyMatrixToIncidence()
{}
void Graph::incidenceMatrixToAdjancency()
{}