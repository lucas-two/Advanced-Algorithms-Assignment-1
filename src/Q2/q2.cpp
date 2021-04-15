/* Q2. Bellman-Ford Algorithm */

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

struct edge
{
    // (NOTE: we're storing node index for start and end)
    int from;
    int to;
    int weight;
};
struct node
{
    int id;
};
struct dist
{
    float cost;   // Total cost to arrive at this node
    int nodeFrom; // What node did it come from?
};
string getPath(dist[], int);

main()
{
    const int numOfEdges = 10;
    const int numOfNodes = 5;
    const int startingNodeIndex = 0;
    dist bestDistance[numOfNodes];

    // Initialise nodes
    node nodes[numOfNodes];
    nodes[0].id = 0;
    nodes[1].id = 1;
    nodes[2].id = 2;
    nodes[3].id = 3;
    nodes[4].id = 4;
    // Initialise edges
    edge edges[numOfEdges];
    edges[0].from = 0;
    edges[0].to = 1;
    edges[0].weight = 6;
    edges[1].from = 0;
    edges[1].to = 3;
    edges[1].weight = 7;
    edges[2].from = 1;
    edges[2].to = 3;
    edges[2].weight = 8;
    edges[3].from = 1;
    edges[3].to = 2;
    edges[3].weight = 5;
    edges[4].from = 1;
    edges[4].to = 4;
    edges[4].weight = -4;
    edges[5].from = 2;
    edges[5].to = 1;
    edges[5].weight = -2;
    edges[6].from = 3;
    edges[6].to = 2;
    edges[6].weight = -3;
    edges[7].from = 3;
    edges[7].to = 4;
    edges[7].weight = 9;
    edges[8].from = 4;
    edges[8].to = 0;
    edges[8].weight = 2;
    edges[9].from = 4;
    edges[9].to = 2;
    edges[9].weight = 7;

    // Initialise best-distance array values to infinity
    for (int i = 0; i < numOfNodes; i++)
    {
        bestDistance[i].cost = INFINITY;
        bestDistance[i].nodeFrom = -1; // Null
    }

    // Set starting node to distance 0 and the node it came from as itself
    bestDistance[startingNodeIndex].cost = 0;
    bestDistance[startingNodeIndex].nodeFrom = 0;

    // Run (numberOfNodes - 1) iterations
    for (int i = 0; i < numOfNodes - 1; i++)
    {
        // For each node...
        for (int currentNode = 0; currentNode < numOfNodes; currentNode++)
        {
            // For each edge where the node equals the current node...
            for (int currentEdge = 0; currentEdge < numOfEdges; currentEdge++)
            {
                if (edges[currentEdge].from == currentNode)
                {
                    // Check if new distance (Edge weight + Best distance) is less than current distance.
                    float newDistance = edges[currentEdge].weight + bestDistance[edges[currentEdge].from].cost;
                    if (newDistance < bestDistance[edges[currentEdge].to].cost)
                    {
                        // Rleax node
                        bestDistance[edges[currentEdge].to].cost = newDistance;                 // Update with new distance
                        bestDistance[edges[currentEdge].to].nodeFrom = edges[currentEdge].from; // Update which node it came from
                    }
                }
            }
        }
    }

    // Run iterations again but for finding the negative cycles
    for (int i = 0; i < numOfNodes - 1; i++)
    {
        for (int currentNode = 0; currentNode < numOfNodes; currentNode++)
        {
            for (int currentEdge = 0; currentEdge < numOfEdges; currentEdge++)
            {
                if (edges[currentEdge].from == currentNode)
                {
                    float newDistance = edges[currentEdge].weight + bestDistance[edges[currentEdge].from].cost;
                    if (newDistance < bestDistance[edges[currentEdge].to].cost)
                    {
                        // Set to negative infinity
                        bestDistance[edges[currentEdge].to].cost = -INFINITY;
                        bestDistance[edges[currentEdge].to].nodeFrom = edges[currentEdge].from;
                    }
                }
            }
        }
    }
    cout << "BELLMAN-FORD ALGORITHM" << endl;
    cout << "Shortest path from Node 0 to..." << endl
         << endl;
    // Displaying the shortest path output
    for (int i = 1; i < numOfNodes; i++)
    {
        cout << "(Node " << i << ")" << endl;
        cout << "Cost: " << bestDistance[i].cost << endl;
        cout << "Path: " << getPath(bestDistance, i) << endl
             << endl;
    }
    getPath(bestDistance, 4);
    return 0;
}

string getPath(dist distArray[], int node)
/* Trace a shortest path route to a node. */
{
    string spacing = " -> ";
    string path = "";
    int currentNode = node;
    while (currentNode != 0)
    {
        // Don't add arrow spacing if it's the first node
        if (currentNode == node)
        {
            path = to_string(currentNode) + path;
            currentNode = distArray[currentNode].nodeFrom;
            continue;
        }
        // Add the node to the path
        path = to_string(currentNode) + spacing + path;
        currentNode = distArray[currentNode].nodeFrom;
    }
    // Add starting node to path
    path = to_string(currentNode) + spacing + path;
    return path;
};
