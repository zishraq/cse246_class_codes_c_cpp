#include <bits/stdc++.h>
using namespace std;


vector <vector <int>> floydWarshall(vector <vector <int>> &graph) {
//    vector <vector <int>> distances(graph);
    vector <vector <int>> distances = graph;

    for (int k = 1; k <= graph.size() - 1; k++) {
        for (int i = 1; i <= graph.size() - 1; i++) {
            for (int j = 1; j <= graph.size() - 1; j++) {
                distances[i][j] = min(distances[i][j], distances[i][k] + distances[k][j]);
            }
        }
    }

    return distances;
}

int main() {
    int vertices, edges;

    cin >> vertices >> edges;

    vector <vector <int>> graph(vertices + 1);

    for (auto &i : graph) {
        i.resize(vertices + 1, 999999);
//        i.resize(vertices + 1, 99);
    }

    for (int i = 0; i < graph.size(); i++) {
        graph[i][i] = 0;
    }

    int vertex, neighbour, weight;
    for (int i = 0; i < edges; i++) {
        cin >> vertex >> neighbour >> weight;

        graph[vertex][neighbour] = weight;
    }

    vector <vector <int>> distances = floydWarshall(graph);

    for (int i = 1; i <= vertices; i++) {
        for (int j = 1; j <= vertices; j++) {
            cout << distances[i][j] << ", ";
        }
        cout << endl;
    }

    return 0;
}