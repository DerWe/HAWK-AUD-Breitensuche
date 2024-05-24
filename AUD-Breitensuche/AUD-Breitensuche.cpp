#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Beispiel: Adjazenzliste für einen ungerichteten Graphen
vector<vector<int>> graph = {
    {1, 2},     // Knoten 0 ist mit Knoten 1 und 2 verbunden
    {0, 2, 3},  // Knoten 1 ist mit Knoten 0, 2 und 3 verbunden
    {0, 1, 3},  // ...
    {1, 2}
};

void bfs(int start) {
    vector<bool> visited(graph.size(), false);
    queue<int> q;

    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        cout << "Besuche Knoten " << current << endl;

        for (int neighbor : graph[current]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }

    }
}

int main() {
    int startNode = 0; // Startknoten auswählen
    bfs(startNode);
    return 0;
}
