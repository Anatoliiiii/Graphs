#pragma once
#include <vector>
#include <iterator>
#include <memory>
#include"MyIterator.h"


using namespace std;



template <class T>
class CGraph
{

friend class Iterator<T, CGraph>;

public:
	CGraph()
	{

	}
	CGraph(int a)
	{
		numberOfVertex = 0;
	}
	bool AddVertex(T vertex)
	{
		int CellNumber = getVertexIndex(vertex);

		if (CellNumber >= 0)
		{
			return false;
		}

		vertexList.push_back(vertex);

		vector<int> row;

		for (int i = 0; i < numberOfVertex; i++)
		{
			matrix[i].push_back(0);
		}
		numberOfVertex++;

		for (int i = 0; i < numberOfVertex; i++)
			row.push_back(0);
		matrix.push_back(row);

		return true;
	}
	int getVertexIndex(T vertex)
	{

		for (int i = 0; i < numberOfVertex; i++)
		{
			if (vertexList[i] == vertex) {
				return i;
			}
		}
		return -1;
	}
	bool checkArc(T vertex1, T vertex2)
	{
		if (getVertexIndex(vertex1) == -1 || getVertexIndex(vertex2) == -1)
			return false;

		if (matrix[getVertexIndex(vertex1)][getVertexIndex(vertex2)] == 1 && matrix[getVertexIndex(vertex2)][getVertexIndex(vertex1)] == 1)
		{
			return true;
		}
		else
			return false;
	}
	bool addArc(T vertex1, T vertex2)
	{
		if (getVertexIndex(vertex1) == -1 || getVertexIndex(vertex2) == -1)
			return false;

		matrix[getVertexIndex(vertex1)][getVertexIndex(vertex2)] = 1;
		matrix[getVertexIndex(vertex2)][getVertexIndex(vertex1)] = 1;

		return true;
	}
	bool deleteVertex(T vertex)
	{
		int index = getVertexIndex(vertex);
		if (index == -1)
		{
			return false;
		}
		for (int i = 0; i < numberOfVertex; i++)
		{
			if (matrix[i][index] == 1)
			{
				matrix[i][index] = 0;
			}

			if (matrix[index][i] == 1)
			{
				matrix[index][i] = 0;
			}
		}

		vertexList.erase(vertexList.begin() + index);

		for (int i = 0; i < numberOfVertex; i++)
		{
			matrix[i].erase(matrix[i].begin() + index);
		}
		matrix.erase(matrix.begin() + index);

		numberOfVertex--;

		return true;
	}
	bool deleteVertex(Iterator<T, CGraph> it) {

		return deleteVertex(*it.Current());

	}

	bool deleteArc(T vertex1, T vertex2)
	{
		if (getVertexIndex(vertex1) == -1 || getVertexIndex(vertex2) == -1)
			return false;

		matrix[getVertexIndex(vertex1)][getVertexIndex(vertex2)] = 0;

		matrix[getVertexIndex(vertex2)][getVertexIndex(vertex1)] = 0;

		return true;
	}
	int getNumberOfVertex()
	{
		return numberOfVertex;
	}
	int getNumberOfArc()
	{
		int count = 0;
		for (int i = 0; i < numberOfVertex; i++)
		{
			for (int j = 0; j < numberOfVertex; j++)
			{
				if (matrix[i][j] == 1)
				{
					count++;
				}

			}
		}
		return count;
	}
	int getVertexDegree(T vertex)
	{
		int index = getVertexIndex(vertex);
		int count = 0;
		for (int i = 0; i < numberOfVertex; i++)
		{
			if (matrix[index][i] == 1)
			{
				count++;
			}
		}
		return count;
	}


	Iterator<T, CGraph>* CreateIterator() {

		return new Iterator<T, CGraph>(this);
	}



private:

	int numberOfVertex;
	vector<T> vertexList;
	vector<vector<int>> matrix;


};
