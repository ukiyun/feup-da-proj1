#ifndef DA_PROJECT_GRAPH_H
#define DA_PROJECT_GRAPH_H

#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
#include <string>

using namespace std;

class Edge;

//======================== Vertex Class ============================\\

/// @struct Vertex
/// @brief Represents Vertices in a Directed OldGraph
class Vertex{
public:
    /// @brief Vertex Constructor
    /// @param id String with the Unique Identifier of the Vertex
    Vertex(string id);

    //****************** Getters ******************\\

    /// @brief A Function used to get the ID of a Vertex
    /// @return Returns the String of the ID of a Vertex
    string getId() const;

    /// @brief A Function to get the Outgoing Edges of a Vertex
    vector<Edge *> getAdjacentEdges() const;

    /// @brief A Function used to get if Vertex has been Visited or Not
    /// @return Returns the 0 if Vertex has not been Visited, 1 otherwise
    bool isVisited() const;

    // bool isProcessing() const;
    // unsigned int getIndegree() const;
    // double getDist() const;

    /// @brief A Function to get the Edge Path
    Edge *getPath() const;

    /// @brief A Function to get the Incoming Edges of a Vertex
    vector<Edge *> getIncomingEdges() const;

    //****************** Setters ******************\\

    /// @brief A Function used to set the Vertex ID
    void setId(string id);

    /// @brief A Function used to set the Vertex Visited Status
    void setVisited(bool visited);

    // void setProcessing(bool processing)
    // void setIndregree(unsigned int indegree)
    // void setDist(double dist);

    /// @brief A Function used to set the Edge Path
    void setPath(Edge *path);

    /// @brief A Function used to add Adjacent Edges to Vertex
    Edge * addEdge(Vertex *nextVertex, double weight);

    /// @brief A Function used to remove an Edge
    bool removeEdge (string id);

    /// @brief A Function used to remove All Outgoing Edges
    void removeOutgoingEdges();

protected:
    /// @brief Vertex Name, i.e, Unique Identifier
    string id_;

    /// @brief Outgoing Edges
    vector<Edge *> adjacentEdges_;

    /// @brief Visited Status for use in Utils Algorithms
    bool visited_ = false;

    // bool processsing = false -> used to check if DAG
    // unsigned int indegree -> used by topsort
    // double dist = 0;

    /// @brief Edge Path
    Edge *path_ = nullptr;

    /// @brief Incoming Edges
    vector<Edge *> incomingEdges_;


    // int queueIndex_ = 0; // used by mut prio queue and ufds

    /// @brief Delete an Edge
    void deleteEdge(Edge *edge);
};

//======================== Edge Class ============================\\

/// @struct Edge
/// @brief Represents the Edges of a Directed OldGraph, i.e., the Connections between Vertices
class Edge{
public:
    /// @brief Edge Constructor
    /// @param prevNode String with the ID of the Previous Vertex
    /// @param nextNode String with the ID of the Next Vertex
    /// @param weight   Integer with the Edge Weight/Capacity
    Edge(Vertex *prevVertex, Vertex *nextVertex, double weight);

    //****************** Getters ******************\\

    /// @brief A Function used to get the Next Vertex
    /// @return Returns the Next Vertex
    Vertex * getNextVertex() const;

    /// @brief A Function used to get the Weight of the Edge
    /// @return Returns the Integer of the Weight of the Edge
    double getWeight() const;

    /// @brief A Function used to check the Selected Status
    /// @return Returns the bool indicating whether Edge is selected or not
    bool isSelected() const;

    /// @brief A Function used to get the Previous Vertex
    /// @return Returns the Previous Vertex
    Vertex * getPrevVertex() const;

    /// @brief A Function used to get the Reverse Edge, i.e., other direction
    Edge *getReverse() const;

    /// @brief A Function used to get the Edge Flow
    double getFlow() const;

    //****************** Setters ******************\\

    /// @brief A Function used to set the Selected Status
    void setSelected(bool selected);

    /// @brief A Function used to set the Reverse Edge
    void setReverse(Edge *reverse);

    /// @brief A Function used to set the Edge Flow
    void setFlow(double flow);

    /// @brief A Function used to set the Edge Weight
    void setWeight(double weight);

protected:
    /// @brief Destination Vertex of the Edge
    Vertex *nextVertex_;

    /// @brief Source Vertex of the Edge
    Vertex *prevVertex_;

    /// @brief Edge Weight
    double weight_;

    /// @brief Auxiliary field to check if Edge is selected/visited
    bool selected_ = false;

    /// @brief Used for Bidirectional Edges
    Edge *reverse_ = nullptr;

    /// @brief Flow of the Edge
    double flow_;
};

//======================== OldGraph Class ============================\\

class Graph {
public:
    ~Graph();

    /// @brief Function used to find a Vertex through its id
    Vertex *findVertex(const string &id) const;

    /// @brief Function to add a Vertex to the Graph
    /// @brief Returns 0 if Vertex has not been added, 1 otherwise
    bool addVertex(const string &id);

    /// @brief Function to remove a Vertex from the Graph
    /// @brief Returns 0 if Vertex has not been removed, 1 otherwise
    bool removeVertex(const string &id);

    /// @brief Function to add an Edge to the Graph
    /// @brief Returns 0 if Edge has not been added, 1 otherwise
    bool addEdge(const string &prevVertex, const string &nextVertex, double weight);

    /// @brief Function to remove an Edge from the Graph
    /// @brief Returns 0 if Edge has not been removed, 1 otherwise
    bool removeEdge(const string &prevVertex, const string &nextVertex);

    // bool addBidirectionalEdge(const string &prevVertex, const string &nextVertex, double weight);

    /// @brief Function used to get the Ammount of Vertices in OldGraph
    int getVertexTotal() const;

    /// @brief Function used to get the Vertices Vector
    /// @brief Return a vector with all the Vertices in the OldGraph
    vector<Vertex *> getVertexSet() const;

    /// @brief Function implementing Breadth-First Search
    vector<string> bfs(const string & source) const;

    /// @brief Function implementing Depth-First Search
    vector<string> dfs() const;

    /// @brief Function implementing Depth-First Search from a source node
    vector<string> dfs(const string & source);

    /// @brief Auxiliary Function that visits vertex and its adjacent recursively
    void dfsVisit(Vertex *v, vector<string> & res) const;

protected:
    /// @brief Vector with All the Vertices in the OldGraph
    vector <Vertex *> vertices_;

    // double ** distMatrix = nullptr -> dist matrix for Floyd Warshall
    // int **pathMatrix = nullptr -> path matrix for Floyd Warshall

    /// @brief Function that finds the index of the vertex with a given content (id)
    int findVertexIdx(const string &id) const;
};


#endif //DA_PROJECT_GRAPH_H
