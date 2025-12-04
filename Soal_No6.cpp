#include <iostream>
#include <climits>
#include <vector>
using namespace std;

struct Edge {
    int asal, tujuan, bobot;
};

Edge createEdge(int a, int t, int b) {
    Edge s;
    s.asal = a;
    s.tujuan = t;
    s.bobot = b;
    return s;
}

void bellmanFord(int jumlahVertex, vector<Edge> &daftarEdge, int source) {
    vector<int> jarak(jumlahVertex, INT_MAX);
    jarak[source] = 0;

    for (int i = 0; i < jumlahVertex - 1; i++) {
        for (int j = 0; j < daftarEdge.size(); j++) {
            int u = daftarEdge[j].asal;
            int v = daftarEdge[j].tujuan;
            int w = daftarEdge[j].bobot;

            if (jarak[u] != INT_MAX && jarak[u] + w < jarak[v]) {
                jarak[v] = jarak[u] + w;
            }
        }
    }

    cout << "Hasil Shortest Path dari " << source << ":\n";
    for(int i = 0; i < jumlahVertex; i++){
        if(jarak[i] == INT_MAX)
            cout << "Node " << i << "Tidak dapat dijangkau\n";
        else
            cout << "Node  " << i << ": " << jarak[i] << endl;
    }
}

int main() {
    int jumlahVertex = 6;
    vector<Edge> daftarEdge;

    daftarEdge.push_back(createEdge(0, 1, 2));
    daftarEdge.push_back(createEdge(0, 3, 8));
    daftarEdge.push_back(createEdge(1, 4, 6));
    daftarEdge.push_back(createEdge(1, 3, 5));
    daftarEdge.push_back(createEdge(4, 3, 3));
    daftarEdge.push_back(createEdge(4, 5, 1));
    daftarEdge.push_back(createEdge(4, 2, 9));
    daftarEdge.push_back(createEdge(3, 5, 2));
    daftarEdge.push_back(createEdge(5, 2, 3));

    bellmanFord(jumlahVertex, daftarEdge, 0);

    return 0;
}