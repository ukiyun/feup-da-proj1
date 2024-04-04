#include "../include/Graph.h"

//======================== Vertex Functions ============================\\

Vertex::Vertex(string id) {
    this->id_ = id;
}

string Vertex::getId() const {
    return this->id_;
}

vector<Edge *> Vertex::getAdjacentEdges() const {
    return this->adjacentEdges_;
}

bool Vertex::isVisited() const {
    return this->visited_;
}

Edge *Vertex::getPath() const {
    return this->path_;
}

vector<Edge *> Vertex::getIncomingEdges() const {
    return  this->incomingEdges_;
}

void Vertex::setId(string id) {
    this->id_ = id;
}

void Vertex::setVisited(bool visited) {
    this->visited_ = visited;
}

void Vertex::setPath(Edge *path) {
    this->path_ = path;
}

Edge *Vertex::addEdge(Vertex *nextVertex, double weight) {
    auto newEdge = new Edge(this, nextVertex, weight);
    adjacentEdges_.push_back(newEdge);
    nextVertex->incomingEdges_.push_back(newEdge);
    return newEdge;
}

bool Vertex::removeEdge(string id) {
    bool removedEdge = false;
    auto iter = adjacentEdges_.begin();
    while(iter!= adjacentEdges_.end()){
        Edge *currentEdge = *iter;
        Vertex *outgoingVertex = currentEdge->getNextVertex();
        if (outgoingVertex->getId() == id){
            iter = adjacentEdges_.erase(iter);
            deleteEdge(currentEdge);
            removedEdge = true;
        }
        else{
            iter++;
        }
    }

    return removedEdge;
}

void Vertex::removeOutgoingEdges() {
    auto iter = adjacentEdges_.begin();
    while(iter != adjacentEdges_.end()){
        Edge *currentEdge = *iter;
        iter = adjacentEdges_.erase(iter);
        deleteEdge(currentEdge);
    }
}

void Vertex::deleteEdge(Edge *edge) {
    Vertex *nextVertex = edge->getNextVertex();
    auto iter = nextVertex->incomingEdges_.begin();
    while(iter != nextVertex->incomingEdges_.end()){
        if((*iter)->getPrevVertex()->getId() == id_){
            iter = nextVertex->incomingEdges_.erase(iter);
        }
        else{
            iter++;
        }
    }
    delete edge;
}

//======================== Edge Functions ============================\\

Edge::Edge(Vertex *prevVertex, Vertex *nextVertex, double weight) {
    this->prevVertex_ = prevVertex;
    this->nextVertex_ = nextVertex;
    this->weight_ = weight;
}

Vertex *Edge::getNextVertex() const {
    return this->nextVertex_;
}

double Edge::getWeight() const {
    return this->weight_;
}

bool Edge::isSelected() const {
    return this->selected_;
}

Vertex *Edge::getPrevVertex() const {
    return this->prevVertex_;
}

Edge *Edge::getReverse() const {
    return this->reverse_;
}

double Edge::getFlow() const {
    return this->flow_;
}

void Edge::setSelected(bool selected) {
    this->selected_ = selected;
}

void Edge::setReverse(Edge *reverse) {
    this->reverse_ =  reverse;
}

void Edge::setFlow(double flow) {
    this->flow_ = flow;
}

void Edge::setWeight(double weight) {
    this->weight_ = weight;
}

//======================== OldGraph Functions ============================\\

Vertex *Graph::findVertex(const string &id) const {
    for (auto vertex: vertices_){
        if(vertex->getId()==id){
            return vertex;
        }
    }
    return nullptr;
}

bool Graph::addVertex(const string &id){
    if(findVertex(id) != nullptr){
        return false;
    }
    vertices_.push_back(new Vertex(id));
    return true;
}

bool Graph::removeVertex(const string &id) {
    for (auto iter = vertices_.begin(); iter != vertices_.end(); iter++) {
        if((*iter)->getId() == id){
            auto v = *iter;
            v->removeOutgoingEdges();
            for (auto u: vertices_){
                u->removeEdge(v->getId());
            }
            vertices_.erase(iter);
            delete v;
            return true;
        }
    }
    return false;
}

bool Graph::addEdge(const string &prevVertex, const string &nextVertex, double weight) {
    auto vertex1 = findVertex(prevVertex);
    auto vertex2 = findVertex(nextVertex);
    if (vertex1 == nullptr || vertex2== nullptr){
        return false;
    }
    vertex1->addEdge(vertex2, weight);
    return true;
}

bool Graph::removeEdge(const string &prevVertex, const string &nextVertex) {
    auto previousVertex = findVertex(prevVertex);
    if (previousVertex == nullptr){
        return false;
    }
    return previousVertex->removeEdge(nextVertex);
}

int Graph::getVertexTotal() const {
    return vertices_.size();
}

vector<Vertex *> Graph::getVertexSet() const {
    return vertices_;
}

int Graph::findVertexIdx(const std::string &id) const {
    for(unsigned i = 0; i<vertices_.size(); i++){
        if (vertices_[i]->getId() == id){
            return i;
        }
    }
    return -1;
}

vector<string> Graph::bfs(const string &source) const {
    vector<string> res;
    // Get the source vertex
    auto s = findVertex(source);
    if(s == nullptr){
        return res;
    }

    // Set that no vertex has been visited yet
    for (auto vertex: vertices_){
        vertex->setVisited(false);
    }

    // Perform the actual BFS using a queue
    queue<Vertex *> q;
    q.push(s);
    s->setVisited(true);
    while(!q.empty()){
        auto v = q.front();
        q.pop();
        res.push_back(v->getId());
        for(auto & e: v->getAdjacentEdges()){
            auto w = e->getNextVertex();
            if(!w->isVisited()){
                q.push(w);
                w->setVisited(true);
            }
        }
    }

    return res;
}

vector<string> Graph::dfs() const {
    vector<string> res;
    for (auto v: vertices_){
        v->setVisited(false);
    }
    for(auto v: vertices_){
        if(!v->isVisited()){
            dfsVisit(v, res);
        }
    }
    return res;
}

vector<string> Graph::dfs(const string &source) {
    vector<string> res;

    // Get the source vertex
    auto s = findVertex(source);
    if (s == nullptr){
        return res;
    }

    // Set that no vertex has been visited yet
    for (auto v: vertices_){
        v->setVisited(false);
    }

    // Perform the actual DFS using recursion
    dfsVisit(s, res);

    return res;
}

void Graph::dfsVisit(Vertex *v, vector<string> &res) const {
    v->setVisited(true);
    res.push_back(v->getId());
    for (auto & e: v->getAdjacentEdges()){
        auto w = e->getNextVertex();
        if(!w->isVisited()){
            dfsVisit(w,res);
        }
    }
}