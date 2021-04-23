/*Q3. Graph Data Structure*/

#include <iostream>
#include <vector>
using namespace std;

void printList(vector<vector<int>>);
void isConnected(vector<vector<int>>, int, int);
void nodesConnected(vector<vector<int>>, int);

int main()
{
    // An adjacency list containing our edges
    vector<vector<int>> adjacencyList{
        {1, 2, 0},
        {0, 3},
        {0, 3},
        {1, 2, 0}};
    isConnected(adjacencyList, 0, 1);
    isConnected(adjacencyList, 1, 2);
    nodesConnected(adjacencyList, 2);
    nodesConnected(adjacencyList, 0);
    return 0;
}

/* Check if two nodes are connected */
void isConnected(vector<vector<int>> list, int node1, int node2)
{
    for (int i = 0; i < list[node1].size(); i++)
    {
        if (list[node1][i] == node2)
        {
            cout << "[Node " << node1 << "] and [Node " << node2 << "] are connected." << endl;
            return;
        }
    }
    cout << "[Node " << node1 << "] and [Node " << node2 << "] are NOT connected." << endl;
    return;
}

/* Check which nodes are connected to a given node */
void nodesConnected(vector<vector<int>> list, int node)
{
    if (list[node].size() == 0)
    {
        cout << "No nodes are connected to [Node " << node << "]." << endl;
        return;
    }
    cout << "Nodes connected to [Node " << node << "] include: { ";
    for (int i = 0; i < list[node].size(); i++)
    {
        // If last node, don't display the comma
        if (i == list[node].size() - 1)
        {
            cout << list[node][i] << " }" << endl;
        }
        else
        {
            cout << list[node][i] << ", ";
        }
    }
}

/* Print the adjacency list */
void printList(vector<vector<int>> list)
{
    cout << "Adjacency List: " << endl;
    for (int i = 0; i < list.size(); i++)
    {
        for (int j = 0; j < list[i].size(); j++)
        {
            cout << list[i][j] << " ";
        }
        cout << endl;
    }
}