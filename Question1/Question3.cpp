#include <iostream>
#include <climits> // For INT_MAX used for comparing purpose
using namespace std;


class SpanningTree {
private:
    int** matrix;
    int size;

    // Helper function to find the parent of a node (with path compression)
    int find(int parent[], int i) {
        // While the current node is not its own parent, move to the parent
        while (parent[i] != i)
            i = parent[i];
        // Return the root parent of the set
        return i;
    }


    // Function to perform union of two sets
    void unionSets(int parent[], int rank[], int x, int y) {
        // Find the root parent of both sets
        int xRoot = find(parent, x);
        int yRoot = find(parent, y);

        // Union by rank: attach the smaller tree under the larger tree
        if (rank[xRoot] < rank[yRoot]) {
            parent[xRoot] = yRoot;  // y becomes the parent of x
        }
        else if (rank[xRoot] > rank[yRoot]) {
            parent[yRoot] = xRoot;  // x becomes the parent of y
        }
        else {
            parent[yRoot] = xRoot;  // Arbitrary choice: make x the parent of y
            rank[xRoot]++;           // Increase the rank of x's tree
        }
    }



    // Main Kruskal's algorithm to find the Minimum Spanning Tree (MST)
    void kruskal() {
        int minCost = 0;  // Variable to store the total weight of the MST
        int* parent = new int[size];  // Array to store the parent of each vertex
        int* rank = new int[size];    // Array to store the rank (or height) of each tree

        // Initialize parent array: each node is its own parent (disjoint sets)
        for (int i = 0; i < size; i++) {
            parent[i] = i;
            rank[i] = 0;  // Initial rank is 0 for all nodes 
        }

        cout << "Kruskal's MST:" << endl;
        int edgeCount = 0;  // To count the number of edges included in the MST

        // Loop to add edges to the MST until we have V-1 edges
        while (edgeCount < size - 1) {
            int minWeight = INT_MAX, u = -1, v = -1;

            // Find the edge with the minimum weight that doesn't form a cycle
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    // If there's an edge (non-zero weight) and it has the smallest weight
                    if (matrix[i][j] != 0 && matrix[i][j] < minWeight) {
                        // Check if u and v are in different sets (to avoid cycles)
                        if (find(parent, i) != find(parent, j)) {
                            minWeight = matrix[i][j];  // Update minimum weight
                            u = i;  // Store the vertex u
                            v = j;  // Store the vertex v
                        }
                    }
                }
            }

            // If a valid edge is found (u and v are different vertices)
            if (u != -1 && v != -1) {
                unionSets(parent, rank, u, v);  // Merge the sets of u and v
                cout << u << " - " << v << " Weight: " << minWeight << endl;  // Output the selected edge
                minCost += minWeight;  // Add the weight of the edge to the total cost
                edgeCount++;  // Increment the edge count
            }
        }

        // Output the minimum cost of the MST after including all edges
        cout << "Minimum cost using Kruskal's: " << minCost << endl;
    }






    void prim() {
        int minCost = 0;
        int* key = new int[size];
        bool* mstSet = new bool[size];
        int* parent = new int[size];

        for (int i = 0; i < size; i++) {
            key[i] = INT_MAX;
            mstSet[i] = false;
        }

        key[0] = 0;
        parent[0] = -1;

        for (int count = 0; count < size - 1; count++) {
            int minKey = INT_MAX, u;

            for (int v = 0; v < size; v++) {
                if (!mstSet[v] && key[v] < minKey) {
                    minKey = key[v];
                    u = v;
                }
            }

            mstSet[u] = true;

            for (int v = 0; v < size; v++) {
                if (matrix[u][v] && !mstSet[v] && matrix[u][v] < key[v]) {
                    parent[v] = u;
                    key[v] = matrix[u][v];
                }
            }
        }

        cout << "Prim's MST:" << endl;
        for (int i = 1; i < size; i++) {
            cout << parent[i] << " - " << i << " Weight: " << matrix[i][parent[i]] << endl;
            minCost += matrix[i][parent[i]];
        }
        cout << "Minimum cost using Prim's: " << minCost << endl;

        delete[] key;
        delete[] mstSet;
        delete[] parent;
    }

public:
    SpanningTree() {
        size = 0;
        matrix = nullptr;
    }

    ~SpanningTree() {
        if (matrix) {
            for (int i = 0; i < size; i++) {
                delete[] matrix[i];
            }
            delete[] matrix;
        }
    }

    void input() {
        cout << "Enter the number of vertices: ";
        cin >> size;

        matrix = new int* [size];
        for (int i = 0; i < size; i++) {
            matrix[i] = new int[size];
        }

        cout << "Enter the adjacency matrix (use 0 for no edge): " << endl;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                cin >> matrix[i][j];
            }
        }
    }

    void findMST() {
        kruskal();
        prim();
    }
};

int main() {
    SpanningTree st;
    st.input();
    st.findMST();
    return 0;
}
