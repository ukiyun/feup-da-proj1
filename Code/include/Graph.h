#ifndef GRAPH_H
#define GRAPH_H

// C++ Libraries
#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
#include <list>
#include <string>
#include <map>


// Project Files
#include "Reservoirs.h"
#include "Stations.h"
#include "Cities.h"
#include "Pipes.h"


class Edge;
using namespace std;

/// @struct Node
/// @brief Represents Nodes in a Directed Graph
class Node {
public:
    /// @brief Node Constructor
    /// @param id String with the Unique Identifier of the Node
    Node(const string &id);

    /// @brief A Default Empty Constructor for the Node
    Node() = default;

    /// @brief A Function used to get the ID of a Node
    /// @return Returns the String of the ID of a Node
    string getId() const;

    /// @brief A Function used to get if Node has been Visited or Not
    /// @return Returns the 0 if Node has not been Visited, 1 otherwise
    bool getVisitedStatus() const;

    /// @brief A Function used to set the Node Name
    void setId(string id);

    /// @brief A Function used to set the Node Visited Status
    void setVisitedStatus(bool visited);

    /// @brief A Function to get the Outgoing Edges of a Node
    vector<Edge*> getAdjacentEdges () const;

    /// @brief A Function to add Adjacent Edges to Node
    Edge addEdge(Node *source, Node *sink, int weight);

    /// @brief A Function to get the Path
    Edge getPath() const;

    /// @brief A Function to set the Path
    void setPath(Edge *path);
private:
    /// @brief Node Name, i.e, Unique Identifier
    string id_;

    /// @brief Visited Status for use in Utils Algorithms
    bool visited_ = false;

    /// @brief Outgoing Edges
    vector<Edge *> adjacentEdges_;

    /// @brief Edge Path
    Edge *path_ = nullptr;

};

/// @struct Edge
/// @brief Represents the Edges of a Directed Graph, i.e., the Connections between Nodes
class Edge {
public:
    /// @brief Edge Constructor
    /// @param prevNode String with the ID of the Previous Node
    /// @param nextNode String with the ID of the Next Node
    /// @param weight   Integer with the Edge Weight/Capacity
    Edge(Node *prevNode, Node *nextNode, int weight);

    /// @brief A Default Empty Constructor for the Edge
    Edge() = default;

    /// @brief A Function used to get the Previous Node
    /// @return Returns the Previous Node
    Node *getPrevNode() const;

    /// @brief A Function used to get the Next Node
    /// @return Returns the Next Node
    Node *getNextNode() const;

    /// @brief A Function used to get the Weight of the Edge
    /// @return Returns the Integer of the Weight of the Edge
    int getWeight() const;

    /// @brief A Function used to set the Previous Node
    void setPrevNode(Node *prevNode);

    /// @brief A Function used to set the Next Node
    void setNextNode(Node *nextNode);

    /// @brief A Function used to set the Edge Weight
    void setWeight(int weight);

    /// @brief A Function used to get the Flow
    double getFlow();

    /// @brief A Function used to set the Flow
    void setFlow(double flow);
private:
    /// @brief Source Node of the Edge
    Node *prevNode_;

    /// @brief Destination Node of the Edge
    Node *nextNode_;

    /// @brief Edge Weight
    int weight_;

    /// @brief Flow of the Edge
    double flow_;
};

/// @class Graph
/// @brief Class used to handle the Graphs
class Graph {
public:
    /// @brief A Default Empty Constructor of the Graph
    Graph() = default;

    /// @brief Function to add a Node to the Graph
    /// @brief Returns 0 if Node has not been added, 1 otherwise
    bool addNode(const string &id);

    /// @brief Function used to find a Node
    Node findNode(const string &id, int *success);

    /// @brief Function used to get the Ammount of Nodes in Graph
    int getNodeTotal();

    /// @brief Function used to get the Vertices Vector
    /// @brief Return a vector with all the Vertices in the Graph
    vector<Node> getNodeSet();

private:
    int size_;
    vector<Node> vertexes_;
};



#endif //GRAPH_H
