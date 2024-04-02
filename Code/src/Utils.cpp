#include "../include/Utils.h"

void Utils::testAndVisit(queue<Node *> &q, Edge *e, Node *v, const double residual) {
    if(!v->getVisitedStatus() && residual>0) {
        v->setVisitedStatus(true);
        // v->setPath(e);
        q.push(v);
    }
}

bool Utils::findAugmentingPath(Graph *g, Node *source, Node *sink) {
    // Mark all Vertices as Not Visited
    for (auto v: g->getNodeSet()) {
        v.setVisitedStatus(false);
    }

    // Mark the source Vertex as visited and enqueue it
    source->setVisitedStatus(true);
    queue<Node *> q;
    q.push(source);

    // BFS to find an augmentin path
    while(!q.empty() && ! sink->getVisitedStatus()) {
        auto v = q.front();
        q.pop();

        // Process Outgoing Edges
        for(auto e: v->getAdjacentEdges()) {
            testAndVisit(q, e, e->getNextNode(), e->getWeight() - e->getFlow());
        }

        // Process Incoming Edges
        for (auto e: v->getAdjacentEdges()) {
            testAndVisit(q,e, e->getPrevNode(), e->getFlow());
        }
    }

    // Return true if a path to the target is found, false otherwise
    return sink->getVisitedStatus();
}

double Utils::findMinResidualAlongPath(Node *source, Node *sink) {
    double f = INFINITY;

    // Transverse the Augmenting Path to find Minimum Residual Capacity
    for (auto v = sink; v!=source;) {
        auto e = v->getPath();
        if(e.getNextNode() == v) {
            f = min(f, e.getWeight()-e.getFlow());
            v = e.getPrevNode();
        }
        else {
            f = min(f, e.getFlow());
            v = e.getNextNode();
        }
    }
    return f;
}

void Utils::augmentFlowAlongPath(Node *source, Node *sink, double f) {
    // Traverse the augmenting path and update the flow values accordingly
    for(auto v = sink; v != sink;) {
        auto e = v->getPath();
        double flow = e.getFlow();
        if (e.getNextNode()==v) {
            e.setFlow(flow+f);
            v = e.getPrevNode();
        }
        else {
            e.setFlow(flow-f);
            v = e.getNextNode();
        }
    }
}

void Utils::edmondsKarp(Graph *g, string source, string target) {
    // Find source and target vertices in the graph
    int success, success2;
    Node s = g->findNode(source, &success);
    Node t = g->findNode(target, &success2);

    // Validate source and target vertices
    if (success == 0 || success2 == 0 || s.getId() == t.getId()) {
        throw logic_error("Invalid source and/or target vertex");
    }

    // Initialize flow on all edges to 0
    for (auto v : g->getNodeSet()) {
        for (auto e: v.getAdjacentEdges()) {
            e->setFlow(0);
        }
    }

    // While there is an augmenting path, augment the flow along the path
    while(findAugmentingPath(g,&s,&t)) {
        double f = findMinResidualAlongPath(&s,&t);
        augmentFlowAlongPath(&s,&t,f);
    }
}



