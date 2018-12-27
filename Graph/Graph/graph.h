#pragma once
#include <vector>
#include <string>

class Graph
{
public:
	Graph(std::vector<std::vector<int>> const & matrix, std::string const & matrixType);
	~Graph();

	int getNumberOfVertexes() const;
	int getNumberOfEdges() const;

private:
	void adjancencyMatrixToIncidence();
	void incidenceMatrixToAdjancency();
	void graphIsCorrect();

	std::vector<std::vector<int>> adjacencyMatrix;
	std::vector<std::vector<int>> incidenceMatrix;
};