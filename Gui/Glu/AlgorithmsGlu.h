/**
 * Application: AbstractGraph
 * Module: GUI
 * File: Glu/AlgorithmsGlu.h
 * Description: Glue interface for algorithms library
 *    and the GUI application
 *
 * @author Dennis J. McWherter, Jr.
 * @version $Id$
 */

#ifndef GLU_ALGORITHMSGLU_H__
#define GLU_ALGORITHMSGLU_H__

#include "Algorithms.h"

// GraphiX Library
#include "graphix.h"

// AbstractGraph Library
#include "Graphs/Graph.h"
#include "Graphs/DiGraph.h"

class GLWindow;

class AlgorithmsGlu
{
public:
  /**
   * Constructor
   *
   * @param scene     The scene object to manipulate
   * @param parent    The parent widget to operate on
   * @param directed  Directed or undirected graph (default = false)
   */
  AlgorithmsGlu(GRAPHIX::Scene& scene, GLWindow* parent, bool directed = false);
  
  /**
   * Destructor
   */
  virtual ~AlgorithmsGlu();
  
  /**
   * Handle an action from GraphiX click handling
   *
   * @param action    The action which took place
   */
  virtual void handleAction(GRAPHIX::ACTION action);
  
  /**
   * Add a node
   *
   * @return  The node's id
   */
  virtual int addNode();
  
  /**
   * Add an edge
   *
   * @param n1      First node's id
   * @param n2      Second node's id
   * @param weight  The edge weight (default = 1)
   *
   * @return  Edge id
   */
  virtual int addEdge(int n1, int n2, int weight = 1);
  
  /**
   * Update edge weights for selected edges
   *
   * @param weight  New weight
   */
  virtual void updateEdgeWeight(int weight);
  
  /**
   * Remove selected components
   */
  virtual void removeSelected();
  
  /**
   * Run the specified algorithm
   *
   * @param alg   The algorithm to be run
   *
   * @return  Result of the algorithm. < 0 on error
   */
  virtual int runAlgorithm(ALGORITHMS alg);

protected:
  /**
   * Run the shortest path algorithm
   *
   * @return  The total weight of the shortest path. -1 on error
   */
  virtual int algorithmShortestPath();
  
private:  
  GRAPHIX::Scene& scene;
  GLWindow* parent;
  AbstractGraph* graph;
};

#endif /* GLU_ALGORITHMSGLU_H__ */
