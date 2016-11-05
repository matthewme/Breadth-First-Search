#include "graph.h"
#include <iostream>

using namespace std;

int main()
{
	graph world;

	world.addVertex("woods");
	world.addVertex("snake pit");
	world.addVertex("secret cave");
	world.addVertex("winding path");
	world.addVertex("scary cemetary");
	world.addVertex("abandoned chainsaw factory");
	world.addVertex("laboratory");
	world.addVertex("crystal lake");
	world.addVertex("elm street");
	world.addVertex("last house on the left");
	world.addVertex("cloverfield lane");
	world.addVertex("smurf village");

	world.addEdge("woods", "secret cave");
	world.addEdge("woods", "snake pit");
	world.addEdge("snake pit", "winding path");
	world.addEdge("snake pit", "elm street");
	world.addEdge("elm street", "scary cemetary");
	world.addEdge("elm street", "laboratory");
	world.addEdge("scary cemetary", "winding path");
	world.addEdge("scary cemetary", "last house on the left");
	world.addEdge("secret cave", "winding path");
	world.addEdge("secret cave", "crystal lake");
	world.addEdge("winding path", "crystal lake");
	world.addEdge("crystal lake", "abandoned chainsaw factory");
	world.addEdge("crystal lake", "smurf village");
	world.addEdge("laboratory", "abandoned chainsaw factory");
	world.addEdge("laboratory", "cloverfield lane");
	world.addEdge("smurf village", "cloverfield lane");

	////part 1: make sure graph got built correctly
	world.testDisplay();
	////woods: secret cave, snake pit
	////laboratory: cloverfield lane, abandoned chainsaw factory, elm stree
	////etc...

	////part 2: Implement breadth first search to find shortest paths
	string path1 = world.shortestPath("woods", "smurf village");
	cout << path1 << endl; //woods, secret cave, crystal lake, smurf village.

	string path2 = world.shortestPath("last house on the left", "laboratory");
	cout << path2 << endl; //????

	cout << endl;
	world.testDisplay();

	return 0;
}