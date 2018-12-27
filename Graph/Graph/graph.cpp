#include "graph.h"
#include <cassert>

using namespace std;

Graph::Graph(std::vector<std::vector<int>> const & matrix, string const & matrixType)
{
	if (matrixType != "adjacency" && matrixType != "incidence")
	{
		bool invalidMatrixType = false;
		assert(invalidMatrixType);
	}
	if (matrixType == "adjacency")
	{
		this->adjacencyMatrix = matrix;
		adjancencyMatrixToIncidence();
	}
	if (matrixType == "incidence")
	{
		this->incidenceMatrix = incidenceMatrix;
		incidenceMatrixToAdjancency();
	}
	graphIsCorrect();
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
void Graph::graphIsCorrect()
{}