#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int cariVertexMinimum(vector<int> &cost, vector<bool> &visited, int jumlahVertex) {
    int min = INT_MAX;
    int min_index = -1;
    for (int i = 0; i < jumlahVertex; i++) {
        if (!visited[i] && cost[i] < min) {
            min = cost[i];
            min_index = i;
        }
    }
    return min_index;
}

vector<int> algoritmaPrims(vector<vector<int>> &graph, int jumlahVertex) {
    vector<int> parent(jumlahVertex);
    vector<int> cost(jumlahVertex, INT_MAX);
    vector<bool> visited(jumlahVertex, false);
    cost[0] = 0;
    parent[0] = -1;
    for (int edge = 0; edge < jumlahVertex - 1; edge++) {
        int u = cariVertexMinimum(cost, visited, jumlahVertex);
        visited[u] = true;
        for (int v = 0; v < jumlahVertex; v++) {
            if (graph[u][v] && !visited[v] && graph[u][v] < cost[v]) {
                parent[v] = u;
                cost[v] = graph[u][v];
            }
        }
    }
    return parent;
}

void cetakHasil(vector<int> &parent, vector<vector<int>> &graph) {
    int totalBobot = 0;
    cout << "Edge\tBobot\n";
    for (int i = 1; i < parent.size(); i++) {
        cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << endl;
        totalBobot += graph[i][parent[i]];
    }
    cout << "Total Bobot : " << totalBobot << endl;
}

int main() {
    vector<vector<int>> graph = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };
    vector<int> parent = algoritmaPrims(graph, graph.size());
    cetakHasil(parent, graph);
    return 0;
}