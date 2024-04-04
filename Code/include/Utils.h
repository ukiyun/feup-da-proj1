#ifndef UTILS_H
#define UTILS_H

// C++ Libraries
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <math.h>

// Project Files
#include "Reservoirs.h"
#include "Stations.h"
#include "Cities.h"
#include "Pipes.h"
#include "Graph.h"

using namespace std;

class Utils {
public:
    /// @brief Function to test the given Node 'v' and visit if conditions are met
    void testAndVisit(queue<Vertex*> &q, Edge *e, Vertex *v, double residual);

    /// @brief Function to find an Augmenting Path using BFS
    bool findAugmentingPath(Graph *g, Vertex *source, Vertex *sink);

    /// @brief Function to find the Minimum Residual Capacity along the Augmenting Path
    double findMinResidualAlongPath(Vertex *source, Vertex *sink);

    /// @brief Function to Augment Flow along the Augmenting Path with the given Flow Value
    void augmentFlowAlongPath(Vertex *source, Vertex *sink, double f);

    /// @brief Function implementing the Edmonds-Karp Algorithm
    void edmondsKarp (Graph *g, string source, string target);

    /// @brief Function implementing Dijkstra's Algorithm
    void dijkstra (Vertex * source, Vertex* dest);
};



#endif //UTILS_H
