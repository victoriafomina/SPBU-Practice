#pragma once
#include <vector>
#include <set>
#include <string>

class Graph
{
public:
	// ������������ � ����������
	Graph(std::vector<std::vector<int>> const & matrix, std::string const & matrixType);
	~Graph();
	// �������
	int getNumberOfVertexes() const;
	int getNumberOfEdges() const;
	std::set<int> getSetOfVertexes() const;
	int getEdgeWeight(int const vertex1, int const vertex2) const;
	// �������� �����
	bool isDirected() const;
	bool withLoops() const;

private:
	// ���������� ������
	void adjancencyMatrixToIncidence();
	// ��������������� ��� ���������� ������� �������������
	int numberOfEdges() const;
	void addEdge(int const row, int const column);
	void incidenceMatrixToAdjancency();
	// ������������ ������
	void graphIsCorrect() const;
	void correctEdge(int const vertex1, int const vertex2) const;
	// �������� ������
	std::set<int> setOfVertexes;
	// ������� ��������� �������� � ���� ������� �� �����
	std::vector<std::vector<int>> adjacencyMatrix;
	// ������� ������������� �������� � ���� ������� �� ��������
	std::vector<std::vector<int>> incidenceMatrix;
};