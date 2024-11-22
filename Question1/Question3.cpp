//#include <iostream>
//#include <climits> // For INT_MAX
//using namespace std;
//
//class SpanningTree {
//private:
//    int** matrix;
//    int size;
//
//    // Helper function for Kruskal's algorithm
//    int find(int parent[], int i) {
//        while (parent[i] != i)
//            i = parent[i];
//        return i;
//    }
//
//    void unionSets(int parent[], int rank[], int x, int y) {
//        int xRoot = find(parent, x);
//        int yRoot = find(parent, y);
//
//        if (rank[xRoot] < rank[yRoot]) {
//            parent[xRoot] = yRoot;
//        }
//        else if (rank[xRoot] > rank[yRoot]) {
//            parent[yRoot] = xRoot;
//        }
//        else {
//            parent[yRoot] = xRoot;
//            rank[xRoot]++;
//        }
//    }
//
//    void kruskal() {
//        int minCost = 0;
//		int* parent = new int[size];
//		int* rank = new int[size];
//        for (int i = 0; i < size; i++) {
//            parent[i] = i;
//            rank[i] = 0;
//        }
//
//        cout << "Kruskal's MST:" << endl;
//        int edgeCount = 0;
//
//        while (edgeCount < size - 1) {
//            int minWeight = INT_MAX, u = -1, v = -1;
//            for (int i = 0; i < size; i++) {
//                for (int j = 0; j < size; j++) {
//                    if (matrix[i][j] != 0 && matrix[i][j] < minWeight) {
//                        if (find(parent, i) != find(parent, j)) {
//                            minWeight = matrix[i][j];
//                            u = i;
//                            v = j;
//                        }
//                    }
//                }
//            }
//
//            if (u != -1 && v != -1) {
//                unionSets(parent, rank, u, v);
//                cout << u << " - " << v << " Weight: " << minWeight << endl;
//                minCost += minWeight;
//                edgeCount++;
//            }
//        }
//        cout << "Minimum cost using Kruskal's: " << minCost << endl;
//    }
//
//    void prim() {
//        int minCost = 0;
//        int* key = new int[size];
//        bool* mstSet = new bool[size];
//        int* parent = new int[size];
//
//        for (int i = 0; i < size; i++) {
//            key[i] = INT_MAX;
//            mstSet[i] = false;
//        }
//
//        key[0] = 0;
//        parent[0] = -1;
//
//        for (int count = 0; count < size - 1; count++) {
//            int minKey = INT_MAX, u;
//
//            for (int v = 0; v < size; v++) {
//                if (!mstSet[v] && key[v] < minKey) {
//                    minKey = key[v];
//                    u = v;
//                }
//            }
//
//            mstSet[u] = true;
//
//            for (int v = 0; v < size; v++) {
//                if (matrix[u][v] && !mstSet[v] && matrix[u][v] < key[v]) {
//                    parent[v] = u;
//                    key[v] = matrix[u][v];
//                }
//            }
//        }
//
//        cout << "Prim's MST:" << endl;
//        for (int i = 1; i < size; i++) {
//            cout << parent[i] << " - " << i << " Weight: " << matrix[i][parent[i]] << endl;
//            minCost += matrix[i][parent[i]];
//        }
//        cout << "Minimum cost using Prim's: " << minCost << endl;
//
//        delete[] key;
//        delete[] mstSet;
//        delete[] parent;
//    }
//
//public:
//    SpanningTree() {
//        size = 0;
//        matrix = nullptr;
//    }
//
//    ~SpanningTree() {
//        if (matrix) {
//            for (int i = 0; i < size; i++) {
//                delete[] matrix[i];
//            }
//            delete[] matrix;
//        }
//    }
//
//    void input() {
//        cout << "Enter the number of vertices: ";
//        cin >> size;
//
//        matrix = new int* [size];
//        for (int i = 0; i < size; i++) {
//            matrix[i] = new int[size];
//        }
//
//        cout << "Enter the adjacency matrix (use 0 for no edge): " << endl;
//        for (int i = 0; i < size; i++) {
//            for (int j = 0; j < size; j++) {
//                cin >> matrix[i][j];
//            }
//        }
//    }
//
//    void findMST() {
//        kruskal();
//        prim();
//    }
//};
//
//int main() {
//    SpanningTree st;
//    st.input();
//    st.findMST();
//    return 0;
//}
