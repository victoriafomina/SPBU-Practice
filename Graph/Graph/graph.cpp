#include "graph.h"
#include <cassert>

using namespace std;

// ������������ � ����������
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
	for (int vertex = 0; vertex < getNumberOfVertexes(); ++vertex)
	{
		setOfVertexes.insert(vertex);
	}
}
Graph::~Graph()
{}
// ������� � �������
int Graph::getNumberOfVertexes() const
{
	return adjacencyMatrix.size();
}
int Graph::getNumberOfEdges() const
{
	return incidenceMatrix[0].size();
}
set<int> Graph::getSetOfVertexes() const
{
	return setOfVertexes;
}
// �������� �����
bool Graph::isDirected() const
{
	for (int row = 0; row < getNumberOfVertexes() - 1; ++row)
	{
		for (int column = row + 1; column < getNumberOfVertexes(); ++column)
		{
			if (getEdgeWeight(row, column) != getEdgeWeight(column, row))
			{
				return true;
			}
		}
	}
	return false;
}
bool Graph::withLoops() const
{
	for (int row = 0; row < getNumberOfVertexes(); ++row)
	{
		if (getEdgeWeight(row, row) != 0)
		{
			return true;
		}
	}
	return false;
}
// ���������� ������
void Graph::adjancencyMatrixToIncidence()
{
}
void Graph::incidenceMatrixToAdjancency()
{}
// ������������ ������
void Graph::graphIsCorrect() const
{}