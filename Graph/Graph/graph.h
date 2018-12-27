#pragma once
#include <vector>
#include <set>
#include <string>

class Graph
{
public:
	// конструкторы и деструктор
	Graph(std::vector<std::vector<int>> const & matrix, std::string const & matrixType);
	~Graph();
	// сеттеры и геттеры
	int getNumberOfVertexes() const;
	int getNumberOfEdges() const;
	std::set<int> getSetOfVertexes() const;
	int getEdgeWeight(int const vertex1, int const vertex2) const;
	int & setEdgeWeight(int const vertex1, int const vertex2);
	// свойства графа
	bool isDirected() const;
	bool withLoops() const;

private:
	// заполнение данных
	void adjancencyMatrixToIncidence();
	void incidenceMatrixToAdjancency();
	// корректность данных
	void graphIsCorrect() const;
	// хранение данных
	std::set<int> setOfVertexes;
	std::vector<std::vector<int>> adjacencyMatrix;
	std::vector<std::vector<int>> incidenceMatrix;
};