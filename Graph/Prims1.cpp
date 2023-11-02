#include <iostream>
#include <climits>
using namespace std;

int minKey(int key[], bool mstSet[], int V) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }

    return min_index;
}

void printMST(int parent[], int V, int graph[100][100]) {
    cout << "Edges   Weight" << endl;
    int totalWeight = 0;
    for (int i = 1; i < V; i++) {
        cout << parent[i] << "-" << i << "   " << graph[i][parent[i]] << endl;
        totalWeight += graph[i][parent[i]];
    }
    cout << totalWeight << endl;
}
void primMST(int graph[100][100], int V) {
    int parent[V];
    int key[V];
    bool mstSet[V];

    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet, V);
        mstSet[u] = true;
        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printMST(parent, V, graph);
}

int main() {
    int V;
    cout<<"Enter No. of Vertex: "<<endl;
    cin >> V;
    int graph[100][100];

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cout<<"Enter vetices: "<<endl;
            cin >> graph[i][j];
        }
    }

    primMST(graph, V);

    return 0;
}