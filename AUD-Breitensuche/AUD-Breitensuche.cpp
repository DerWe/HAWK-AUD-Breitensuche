#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Graph als Adjazenzliste
vector<vector<int>> graph;

// Breitensuche
void bfs(int start) {
    vector<bool> visited(graph.size(), false);
    vector<int> distance(graph.size(), -1);
    queue<int> q;

    q.push(start);
    visited[start] = true;
    distance[start] = 0;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int neighbor : graph[current]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
                distance[neighbor] = distance[current] + 1;
            }
        }
    }

    // Ausgabe der Distanzen
    cout << "Kürzeste Wege vom Startknoten " << start << ":\n";
    for (int i = 0; i < graph.size(); ++i) {
        cout << "Knoten " << i << ": " << distance[i] << "\n";
    }
}

int main() {
    // Beispielgraph (Adjazenzliste)
    graph = {
        {1, 2},     // Knoten 0
        {0, 2, 3},  // Knoten 1
        {0, 1, 4},  // Knoten 2
        {1},        // Knoten 3
        {2, 5},     // Knoten 4
        {4}         // Knoten 5
    };

    int startknoten = 0; // Startknoten auswählen
    bfs(startknoten);

    return 0;
}