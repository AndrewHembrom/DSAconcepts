#include <iostream>
#include <climits>

using namespace std;

const int INF = INT_MAX;

// Define a function to find the vertex with the minimum key value
int findMinKeyVertex(int* key, bool* mstSet, int V) {
    int minKey = INF;
    int minIndex = -1;

    for (int v = 0; v < V; v++) {
        if (!mstSet[v] && key[v] < minKey) {
            minKey = key[v];
            minIndex = v;
        }
    }

    return minIndex;
}

// Function to print the Minimum Spanning Tree
void printMST(int* parent, int* graph, int V) {
    cout << "Minimum Spanning Tree (MST) edges:" << endl;
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << " : " << graph[i * V + parent[i]] << endl;
    }
}

// Prim's algorithm to find the Minimum Spanning Tree
void primMST(int* graph, int V) {
    int* parent = new int[V]; // Array to store MST
    int* key = new int[V];    // Key values used to pick the minimum weight edge
    bool* mstSet = new bool[V]; // To represent set of vertices included in MST

    for (int i = 0; i < V; i++) {
        key[i] = INF;
        mstSet[i] = false;
    }

    key[0] = 0;     // Start with the first vertex
    parent[0] = -1; // First node is the root of MST

    for (int count = 0; count < V - 1; count++) {
        int u = findMinKeyVertex(key, mstSet, V);
        mstSet[u] = true;

        for (int v = 0; v < V; v++) {
            int weight = graph[u * V + v];
            if (!mstSet[v] && weight && weight < key[v]) {
                parent[v] = u;
                key[v] = weight;
            }
        }
    }

    printMST(parent, graph, V);

    delete[] parent;
    delete[] key;
    delete[] mstSet;
}

int main() {
    int V;
    cout << "Enter the number of vertices (V): ";
    cin >> V;

    int* graph = new int[V * V];
    cout << "Enter the adjacency matrix (" << V << "x" << V << "):" << endl;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> graph[i * V + j];
        }
    }

    primMST(graph, V);

    delete[] graph;

    return 0;
}
