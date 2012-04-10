//
//  graphTest.cpp
//  AbstractGraph
//
//  Created by Jiageng Li on 4/8/12.
//  Copyright (c) 2012 University of Illinois at Urbana-Champaign. All rights reserved.
//

#include <stdio.h>
#include <vector>

#include "include/Graphs/AbstractGraph.h"
#include "include/Graphs/Graph.h"
#include "include/Graphs/DiGraph.h"

using namespace std;



void printVector(vector<int> * v){
	
	vector<int>::iterator it;
	
	for (it = v->begin(); it != v->end(); it++){
		printf("%i ", *it);
	}
}



void shortestPathTest(){
	
	DiGraph g(8);
	
	g.addEdge(1,1,1);
	g.removeEdge(0);
	
	g.addEdge(1,2,2);
	g.addEdge(1,4,1);
	g.addEdge(2,4,3);
	g.addEdge(2,5,10);
	g.addEdge(3,1,4);
	g.addEdge(3,6,5);
	g.addEdge(4,3,2);
	g.addEdge(4,5,2);
	g.addEdge(4,6,8);
	g.addEdge(4,7,4);
	g.addEdge(5,7,6);
	g.addEdge(7,6,1);
	
	g.addEdge(4,7,2);
	
	printf("\n");
	g.printGraph();
    
    vector<int> * path = new vector<int>();
	
	int from = 1;
	int to = 7;
    
	printf("\nshortest path from %i to %i: \ndistance: %i \npath: ", from, to, g.shortestPath(from, to, path));
	
	printVector(path);
	
	printf("\n");
	
	delete path;
}

void mstTest(){
	
	Graph g(8);
	
	g.removeNode(0);
	
	g.addEdge(1,2,2);
	g.addEdge(1,4,1);
	g.addEdge(2,4,3);
	g.addEdge(2,5,10);
	g.addEdge(3,1,4);
	g.addEdge(3,6,5);
	g.addEdge(4,3,2);
	g.addEdge(4,5,7);
	g.addEdge(4,6,8);
	g.addEdge(4,7,4);
	g.addEdge(7,5,6);
	g.addEdge(7,6,1);
	
	printf("\n");
	g.printGraph();
	
	vector<int> * mstEdges = new vector<int>();
	
	printf("\nMST: \ntotal weight: %i \ntree edges: ", g.mst(mstEdges));
	
	printVector(mstEdges);
	
	printf("\n");
	
	delete mstEdges;
}



void bipartiteTest(){
	
	Graph g(30);
	
	g.addEdge(1,3);
	g.addEdge(1,4);
	g.addEdge(1,5);
	g.addEdge(2,3);
	g.addEdge(2,4);
	g.addEdge(2,5);
	
//	g.addEdge(1,2);
//	g.addEdge(2,3);
//	g.addEdge(1,3);
	
	printf("\n");
	g.printGraph();
	
	vector<int> * partX = new vector<int>;
	vector<int> * partY = new vector<int>;
	
	int isBipartite = g.bipartite(partX, partY);
	
	if (isBipartite){
		
		printf("partite set X: ");
		printVector(partX);
		
		printf("\n");
		
		printf("partite set Y: ");
		printVector(partY);
		
		printf("\n");
	}else{
		printf("Not Bipartite \n");
	}
	
}



int main(){
	
	shortestPathTest();
	
	mstTest();
	
	bipartiteTest();
	
	return 0;
}








