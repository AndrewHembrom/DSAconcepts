#include <iostream>

using namespace std;

// Define a structure to represent an edge
struct Edge {
    int src, dest, weight;
};

// Define a structure to represent a disjoint set
struct DisjointSet {
    int* parent;
    int* rank;
    int n;

    DisjointSet(int n) {
        this->n = n;
        parent = new int[n];
        rank = new int[n];

        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int find(int v) {
        if (v != parent[v]) {
            parent[v] = find(parent[v]);
        }
        return parent[v];
    }

    void unionSets(int a, int b) {
        a = find(a);
        b = find(b);

        if (a != b) {
            if (rank[a] < rank[b]) {
                parent[a] = b;
            } else if (rank[a] > rank[b]) {
                parent[b] = a;
            } else {
                parent[b] = a;
                rank[a]++;
            }
        }
    }

    ~DisjointSet() {
        delete[] parent;
        delete[] rank;
    }
};

// Kruskal's algorithm to find the Minimum Spanning Tree
void kruskalMST(Edge* edges, int E, int V) {
    // Sort the edges using bubble sort (you can use another sorting algorithm)
    for (int i = 0; i < E - 1; i++) {
        for (int j = 0; j < E - i - 1; j++) {
            if (edges[j].weight > edges[j + 1].weight) {
                swap(edges[j], edges[j + 1]);
            }
        }
    }

    DisjointSet ds(V);
    Edge* result = new Edge[V - 1];
    int e = 0;
    int i = 0;

    while (e < V - 1 && i < E) {
        Edge nextEdge = edges[i++];
        int x = ds.find(nextEdge.src);
        int y = ds.find(nextEdge.dest);

        if (x != y) {
            result[e++] = nextEdge;
            ds.unionSets(x, y);
        }
    }

    cout << "Minimum Spanning Tree (MST) edges:" << endl;
    for (int i = 0; i < V - 1; i++) {
        cout << result[i].src << " - " << result[i].dest << " : " << result[i].weight << endl;
    }

    delete[] result;
}

int main() {
    int V, E;
    cout << "Enter the number of vertices (V) and edges (E): ";
    cin >> V >> E;

    Edge* edges = new Edge[E];
    cout << "Enter the edges (src, dest, weight):" << endl;
    for (int i = 0; i < E; i++) {
        cin >> edges[i].src >> edges[i].dest >> edges[i].weight;
    }

    kruskalMST(edges, E, V);

    delete[] edges;

    return 0;
}
