//
//  Prim.cpp
//  AbstractGraph
//
//  Created by Jiageng Li on 4/8/12.
//  Copyright (c) 2012 University of Illinois at Urbana-Champaign. All rights reserved.
//

#include "../../include/Algorithms/Prim.h"

using namespace std;



Prim::Prim(AbstractGraph * g, vector<int> * path){
	
	G = new priority_queue<Vertex*, vector<Vertex*>, comp>();
	
	V = new map<int, Vertex*>;
	
	this->path = path;
	
	this->g = g;
	
	initVertexStructure();
}


void Prim::initVertexStructure(){
	
	initVertices();
	
	map<int, AbstractNode*> * N = g->getNodes();
	map<int, Vertex*>::iterator it = V->begin();
	
	while (it != V->end()){
		
		Vertex * vertex = it->second;
		
		AbstractNode * node = (*N)[it->first];
		
		initAdjacent(vertex, node);
		
		G->push(it->second);
		
		it++;
	}
}



void Prim::initAdjacent(Vertex * v, AbstractNode * n){
	
	map<AbstractEdge*, AbstractNode*> * adjacent = n->getAdjacent();
	map<AbstractEdge*, AbstractNode*>::iterator it = adjacent->begin();
	
	while (it != adjacent->end()) {
		
		AbstractEdge * edge = it->first;
		AbstractNode * to = it->second;
		map<int, Vertex*>::iterator curr = v->adj->find(to->id);
		
		if (curr == v->adj->end()){
			
			// this node has not been included
			(*v->adj)[to->id] = (*V)[to->id];
			(*v->cost)[to->id] = edge->value;
			(*v->edgeId)[to->id] = edge->id;
			
		}else if ((*v->cost)[to->id] > edge->value) {
			
			// this node has been visited but the new edge offer
			// lower cost
			(*v->cost)[to->id] = edge->value;
			(*v->edgeId)[to->id] = edge->id;
		}
		
		it++;
	}
}



void Prim::initVertices(){
	
	map<int, AbstractNode*> * N = g->getNodes();
	map<int, AbstractNode*>::iterator it = N->begin();
	
	s = it->first;
	
	while ( it != N->end() ){
		(*V)[it->first] = initVertex(it->second);
		it++;
	}
}


Prim::Vertex * Prim::initVertex(AbstractNode * node){
	
	Vertex * v = new Vertex();
    
    v->id = node->id;
    v->adj = new map<int, Vertex*>;
    v->cost = new map<int, int>;
    v->visited = false;
    v->dist = INFINITY;
    v->next = NULL;
    v->edgeId = new map<int, int>;
	
    return v;
}


int Prim::solve(){
    
	//	init src node
    (*V)[s]->dist = 0;
    refreshMin(G);
    
	//	keep updating distances while there is node left
    while (G->size() > 0){
        
        Vertex * u = G->top();
		
		//	the node with smallest cost is dist, meaning
		//	it is disconnected from the src, break
        if (u->dist == INFINITY){
            break;
        }
        
		//	mark visited, and remove from queue
        u->visited = true;
        G->pop();
		
		//	placeholders
        int uwCost = 0;
        Vertex * w = NULL;
		
		map<int, Vertex*>::iterator it = u->adj->begin();
		
		//	for each adjacent node:
		while (it != u->adj->end()) {
			
			//	if w is unvisited, update corresponding
			//	values of w depending on prim or Prim	
			w = it->second;
			uwCost = (*u->cost)[it->first];
			
			if ( !w->visited ){
				handleUnvisited(uwCost, w, u);
            }
			
			it++;
		}
		
		// update the priority queue
		refreshMin(G);
    }
	
	// construct MST and return the total weight
	return constructMST();
}



void Prim::handleUnvisited(int uwCost, Vertex * w, Vertex * u){
	
	if (w->dist > uwCost){
		w->dist = uwCost;
		w->next = u;
	}
}



void Prim::refreshMin(priority_queue<Vertex*, vector<Vertex*>, comp> * G){
	
	Vertex * v = G->top();
    G->pop();
    G->push(v);
}



int Prim::constructMST(){
	
	int totalWeight = 0;
	Vertex * curr;
	Vertex * ancestor;
	map<int, Vertex*>::iterator it = V->begin();
	
	while (it != V->end()) {
		
		if (it->second->next == NULL){
			it++;
			continue;
		}
		
		curr = it->second;
		ancestor = (*V)[curr->next->id];
		
		path->push_back( (*(ancestor)->edgeId)[curr->id] );
		totalWeight += (*(ancestor)->cost)[curr->id];
		
		it++;
	}
	
	return totalWeight;
}











