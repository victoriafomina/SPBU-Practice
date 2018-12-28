#include "graph.h"
#include <cassert>
#include <iostream>

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
		this->incidenceMatrix = matrix;
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
	return incidenceMatrix.size();
}
set<int> Graph::getSetOfVertexes() const
{
	return setOfVertexes;
}
int Graph::getEdgeWeight(int const vertex1, int const vertex2) const
{
	correctEdge(vertex1, vertex2);
	return adjacencyMatrix[vertex1][vertex2];
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
// ����� ������
void Graph::printAdjancencyMatrix() const
{
	for (int row = 0; row < getNumberOfVertexes(); ++row)
	{
		for (int column = 0; column < getNumberOfVertexes(); ++column)
		{
			cout << adjacencyMatrix[row][column] << " ";
		}
		cout << endl;
	}
}
void Graph::printIncidenceMatrix() const
{
	for (int row = 0; row < getNumberOfVertexes(); ++row)
	{
		for (int column = 0; column < getNumberOfEdges(); ++column)
		{
			cout << incidenceMatrix[column][row] << " ";
		}
		cout << endl;
	}
}
// ���������� ������
void Graph::adjancencyMatrixToIncidence()
{
	int const numberOfVertexes = getNumberOfVertexes();
	for (int row = 0; row < numberOfVertexes; ++row)
	{
		for (int column = row; column < numberOfVertexes; ++column)
		{
			if (getEdgeWeight(row, column) != 0 || getEdgeWeight(column, row) != 0)
			{
				addEdge(row, column);
			}
		}
	}
}
// ��������������� ��� ���������� ������� �������������
void Graph::addEdge(int const row, int const column)
{
	int const numberOfVertexes = getNumberOfVertexes();
	vector<int> edge(numberOfVertexes);
	if (getEdgeWeight(row, column) == getEdgeWeight(column, row))
	{
		edge[row] = getEdgeWeight(row, column);
		edge[column] = edge[row];
	}
	else
	{
		if (getEdgeWeight(row, column) == 0)
		{
			edge[row] = -getEdgeWeight(column, row);
			edge[column] = getEdgeWeight(column, row);
		}
		else
		{
			edge[row] = getEdgeWeight(row, column);
			edge[column] = -getEdgeWeight(row, column);
		}
	}
	incidenceMatrix.push_back(edge);
}
int Graph::numberOfEdges() const
{
	int numberOfEdges = 0;
	if (isDirected())
	{
		for (int row = 0; row < getNumberOfVertexes(); ++row)
		{
			for (int column = 0; column < getNumberOfVertexes(); ++column)
			{
				if (getEdgeWeight(row, column) != 0)
				{
					++numberOfEdges;
				}
			}
		}
	}
	else
	{
		for (int row = 0; row < getNumberOfVertexes(); ++row)
		{
			for (int column = row; column < getNumberOfVertexes(); ++column)
			{
				if (getEdgeWeight(row, column) != 0)
				{
					++numberOfEdges;
				}
			}
		}
	}
	return numberOfEdges;
}
void Graph::incidenceMatrixToAdjancency()
{
	int const numberOfVertexes = incidenceMatrix[0].size();
	adjacencyMatrix.resize(numberOfVertexes);
	for (int row = 0; row < numberOfVertexes; ++row)
	{
		adjacencyMatrix[row].resize(numberOfVertexes);
	}
	for (int edge = 0; edge < incidenceMatrix.size(); ++edge)
	{
		vector<int> edgeVector = incidenceMatrix[edge];
		int vertex1 = 0;
		int vertex2 = 0;
		int weight1 = 0;
		int weight2 = 0;
		for (int vertex = 0; vertex < numberOfVertexes; ++vertex)
		{
			if (edgeVector[vertex] != 0)
			{
				if (vertex1 == 0)
				{
					vertex1 = vertex;
					weight1 = edgeVector[vertex];
				}
				else
				{
					vertex2 = vertex;
					weight2 = edgeVector[vertex];
				}
			}
		}
		if (weight1 > 0)
		{
			if (weight2 == 0)
			{
				adjacencyMatrix[vertex1][vertex1] = weight1;
			}
			if (weight2 > 0)
			{
				adjacencyMatrix[vertex1][vertex2] = weight1;
				adjacencyMatrix[vertex2][vertex1] = weight1;
			}
			else
			{
				adjacencyMatrix[vertex1][vertex2] = weight1;
			}
		}
		else
		{
			adjacencyMatrix[vertex2][vertex1] = weight2;
		}
	}
}
// ������������ ������
void Graph::graphIsCorrect() const
{}
void Graph::correctEdge(int const vertex1, int const vertex2) const
{}