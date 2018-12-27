#pragma once
#include <vector>

class Graph
{
public:
	Graph(std::vector<std::vector<int>> const & adjacencyMatrix);
	Graph(std::vector<std::vector<int>> const & incidenceMatrix);
	~Graph();

	int getNumberOfVertexes() const;
	int getNumberOfEdges() const;

private:
	void adjancencyMatrixToIncidence();
	void incidenceMatrixToAdjancency();

	std::vector<std::vector<int>> adjacencyMatrix;
	std::vector<std::vector<int>> incidenceMatrix;
};