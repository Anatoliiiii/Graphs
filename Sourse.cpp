#include<iostream>
#include <vector>
#include "Graph.h"


using namespace std;

int main()
{
	CGraph<int> * graph = new CGraph<int>(1);

	graph->AddVertex(1);

	graph->AddVertex(2);

	graph->AddVertex(3);

	graph->AddVertex(4);

	graph->AddVertex(5);

	graph->AddVertex(6);

	Iterator<int, CGraph<int>> *it = graph->CreateIterator();

	it->Next();

	it->Next();

	graph->deleteVertex(*it);

	for (it->setCurrentToBegin(); !it->FromBegineToEnd(); it->Next())
	{
		cout << *it->Current() << endl;
	}



	cout << graph->getNumberOfVertex();

	cout << "";


	for (it->setCurrentToEnd(); it->Current() != (it->First()); )
	{
		it->Prev();

		cout << *it->Current() << endl;
	}







	graph->addArc(1, 2);
	graph->addArc(2, 3);

	graph->deleteVertex(2);





	return 0;
}