#include "../include/Graph.h"

//======================== Node Functions ============================\\

Node::Node(const string &id) {
    id_ = id;
}

string Node::getId() const {
    return  id_;
}

bool Node::getVisitedStatus() const {
    return visited_;
}

void Node::setId(string id) {
    id_ = id;
}

void Node::setVisitedStatus(bool visited) {
    visited_ = visited;
}

vector<Edge *> Node::getAdjacentEdges() const {
    return adjacentEdges_;
}

Edge Node::addEdge(Node *source, Node *sink, int weight) {
    auto newEdge = Edge(source, sink, weight);
    adjacentEdges_.push_back(&newEdge);
    return newEdge;
}

Edge Node::getPath() const {
    return *path_;
}

void Node::setPath(Edge *path) {
    path_ = path;

}


//======================== Edge Functions ============================\\

Edge::Edge(Node *prevNode, Node *nextNode, const int weight) {
    prevNode_ = prevNode;
    nextNode_ = nextNode;
    weight_ = weight;
    flow_ = 0;
}

Node *Edge::getPrevNode() const {
    return prevNode_;
}

Node *Edge::getNextNode() const {
    return nextNode_;
}

int Edge::getWeight() const {
    return weight_;
}

void Edge::setPrevNode(Node *prevNode) {
    prevNode_ = prevNode;
}

void Edge::setNextNode(Node *nextNode) {
    nextNode_ = nextNode;
}

void Edge::setWeight(int weight) {
    weight_ = weight;
}

double Edge::getFlow() {
    return flow_;
}

void Edge::setFlow(const double flow) {
    flow_ = flow;
}


//======================== Graph Functions ============================\\

bool Graph::addNode(const string &id) {
    int nodeSuccess;                        // If Integer = 0 means Node wasn't found in vertex vector, 1 otherwise
    Node foundNode = findNode(id, &nodeSuccess);
    if (nodeSuccess) {
        return false;                       // Node already exists in Graph, therefore is not added to vector
    }

    vertexes_.push_back(Node(id));
    return true;                            // Node added successfully to the Nodes Vector
}

Node Graph::findNode(const string &id, int *success) {
    for(auto node : vertexes_) {
        if(id == node.getId()) {
            *success = 1;
            return node;                // If node exists in vector
        }
    }

    *success = 0;
    return Node(nullptr);           // If it doesnt exist return null Node
}

int Graph::getNodeTotal() {
    const int totalNodes = vertexes_.size();
    size_ = totalNodes;
    return totalNodes;
}

vector<Node> Graph::getNodeSet() {
    return vertexes_;
}

