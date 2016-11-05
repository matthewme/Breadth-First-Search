//NAME: Matthew Martinez
//CLASS: CSCI 3333
//INSTRCUTOR: Dr. Schweller
//DATE:3/28/16
#pragma once
#include <iostream>
#include <string>
#include <list>
using namespace std;

class graph
{
private:

	class vertex
	{
	public:
		string data;
		bool visited = false;
		list<vertex*> neighbors;
		vertex* predecessor = NULL;

		vertex(string x)
		{
			data = x;
		}
	};

	list<vertex*> verticeList;

	vertex* findVertex(string x)
	{
		for (list<vertex*>::iterator itr = verticeList.begin(); itr != verticeList.end(); ++itr)
		{
			if ((*itr)->data == x)
				return *itr;
		}
		return NULL;
	}

public:

	void addVertex(string x)
	{
		vertex* newVertex = new vertex(x);
		verticeList.push_back(newVertex);
	}

	void addEdge(string x, string y)
	{
		vertex* v1 = findVertex(x);
		vertex* v2 = findVertex(y);
		
		v1->neighbors.push_back(v2);
		v2->neighbors.push_back(v1);
	}

	//list all vertices, and who each vertex is connect to
	void testDisplay()
	{
		//Display vertex
		for (list<vertex*>::iterator itr = verticeList.begin(); itr != verticeList.end(); ++itr)
		{
			cout << (*itr)->data << ":" << endl << "     N: ";

			//Display neighbors
			for (list<vertex*>::iterator itr2 = (*itr)->neighbors.begin(); itr2 != (*itr)->neighbors.end(); ++itr2)
			{
				cout << (*itr2)->data << ", ";
			}

			//Display Predecessor
			if ((*itr)->predecessor != NULL)
			{
				cout << endl << "     P: ";
				cout << (*itr)->predecessor->data;
			}
			cout << endl;
		}
	}

	void breadthFirstSearch(vertex *s)
	{
		list<vertex*> q;//Create a queue

		s->visited = true;

		q.push_back(s);//First In

		while (!q.empty())
		{
			vertex* x = q.front();//Return front item value
			q.pop_front();//First out(removed from queue)

			for (list<vertex*>::iterator itr = x->neighbors.begin(); itr != x->neighbors.end(); ++itr)
			{
				if ((*itr)->visited == false)
				{
					(*itr)->visited = true;
					q.push_back(*itr);//Add to queue
					(*itr)->predecessor = x;//Add to predecessor
				}
			}
		}
	}

	string shortestPath(string first, string second)
	{
		//Set all vertices to not visited
		for (list<vertex*>::iterator itr = verticeList.begin(); itr != verticeList.end(); ++itr)
		{
			(*itr)->visited = false;

			//Set neighbors to not visited
			for (list<vertex*>::iterator itr2 = (*itr)->neighbors.begin(); itr2 != (*itr)->neighbors.end(); ++itr2)
			{
				(*itr2)->visited = false;
			}

			//Erase predecessors
			(*itr)->predecessor = NULL;
		}

		string path;

		vertex* start = findVertex(first);//Locate the first vertex(This is the starting point)
		vertex* end = findVertex(second);//Locate the second vertex(This is the end point)
		breadthFirstSearch(start);//Find adjecencies of all vertices starting from first vertex

		//If there is only one jump return the path
		if (end->predecessor->data == first)
			path = first + "-> " + second + ".\n";
		else
		{
			path = second;
			//read end's predecessor, go to that vertex and repeat and until there is no predecessor
			while (end->predecessor != NULL)
			{
				path += + " <-" + end->predecessor->data ;
				end = end->predecessor;
 			}
			
		}
		
		cout << endl;
		return path;
	}


};