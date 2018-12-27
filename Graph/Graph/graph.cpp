#include "graph.h"
#include <cassert>

using namespace std;

// конструкторы и деструктор
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
// сеттеры и геттеры
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
// свойства графа
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
// заполнение данных
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
// вспомогательное для заполнения матрицы инцидентности
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
	adjacencyMatrix.push_back(edge);
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
{}
// корректность данных
void Graph::graphIsCorrect() const
{}
void Graph::correctEdge(int const vertex1, int const vertex2) const
{}