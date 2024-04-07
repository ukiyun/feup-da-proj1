#include "../include/Utils.h"


void Utils::testAndVisit(queue<Vertex *> &q, Edge *e, Vertex *v, const double residual) {
    if(!v->isVisited() && residual>0) {
        v->setVisited(true);
        // v->setPath(e);
        q.push(v);
    }
}

bool Utils::findAugmentingPath(Graph *g, Vertex *source, Vertex *sink) {
    // Mark all Vertices as Not Visited
    for (auto v: g->getVertexSet()) {
        v->setVisited(false);
    }

    // Mark the source Vertex as visited and enqueue it
    source->setVisited(true);
    queue<Vertex *> q;
    q.push(source);

    // BFS to find an augmenting path
    while(!q.empty() && ! sink->isVisited()) {
        auto v = q.front();
        q.pop();

        // Process Outgoing Edges
        for(auto e: v->getAdjacentEdges()) {
            testAndVisit(q, e, e->getNextVertex(), e->getWeight() - e->getFlow());
        }

        // Process Incoming Edges
        for (auto e: v->getAdjacentEdges()) {
            testAndVisit(q,e, e->getPrevVertex(), e->getFlow());
        }
    }

    // Return true if a path to the target is found, false otherwise
    return sink->isVisited();
}

double Utils::findMinResidualAlongPath(Vertex *source, Vertex *sink) {
    double f = INFINITY;

    // Transverse the Augmenting Path to find Minimum Residual Capacity
    for (auto v = sink; v!=source;) {
        auto e = v->getPath();
        if(e->getNextVertex() == v) {
            f = min(f, e->getWeight()-e->getFlow());
            v = e->getPrevVertex();
        }
        else {
            f = min(f, e->getFlow());
            v = e->getNextVertex();
        }
    }
    return f;
}

void Utils::augmentFlowAlongPath(Vertex *source, Vertex *sink, double f) {
    // Traverse the augmenting path and update the flow values accordingly
    for(auto v = sink; v != sink;) {
        auto e = v->getPath();
        double flow = e->getFlow();
        if (e->getNextVertex()==v) {
            e->setFlow(flow+f);
            v = e->getPrevVertex();
        }
        else {
            e->setFlow(flow-f);
            v = e->getNextVertex();
        }
    }
}

void Utils::edmondsKarp(Graph *g, string source, string target) {
    // Find source and target vertices in the graph
    Vertex *s = g->findVertex(source);
    Vertex *t = g->findVertex(target);

    // Validate source and target vertices
    if (s->getId() == t->getId()) {
        throw logic_error("Invalid source and/or target vertex");
    }

    // Initialize flow on all edges to 0
    for (auto v : g->getVertexSet()) {
        for (auto e: v->getAdjacentEdges()) {
            e->setFlow(0);
        }
    }

    // While there is an augmenting path, augment the flow along the path
    while(findAugmentingPath(g,s,t)) {
        double f = findMinResidualAlongPath(s,t);
        augmentFlowAlongPath(s,t,f);
    }
}

void Utils::dijkstra(Vertex *source, Vertex *dest) {

}


