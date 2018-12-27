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
	// геттеры
	int getNumberOfVertexes() const;
	int getNumberOfEdges() const;
	std::set<int> getSetOfVertexes() const;
	int getEdgeWeight(int const vertex1, int const vertex2) const;
	// свойства графа
	bool isDirected() const;
	bool withLoops() const;

private:
	// заполнение данных
	void adjancencyMatrixToIncidence();
	// вспомогательное для заполнения матрицы инцидентности
	int numberOfEdges() const;
	void addEdge(int const row, int const column);
	void incidenceMatrixToAdjancency();
	// корректность данных
	void graphIsCorrect() const;
	void correctEdge(int const vertex1, int const vertex2) const;
	// хранение данных
	std::set<int> setOfVertexes;
	// матрица смежности хранится в виде вектора из строк
	std::vector<std::vector<int>> adjacencyMatrix;
	// матрица инцидентности хранится в виде вектора из столбцов
	std::vector<std::vector<int>> incidenceMatrix;
};