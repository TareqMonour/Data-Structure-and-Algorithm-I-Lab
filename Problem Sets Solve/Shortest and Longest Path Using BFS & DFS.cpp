#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e9;

void bfs(const vector<vector<int>>& graph, int start, int end, vector<int>& shortestPath) {
    int n = graph.size();
    vector<bool> visited(n, false);
    queue<int> q;

    q.push(start);
    visited[start] = true;
    shortestPath[start] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v = 0; v < n; ++v) {
            if (graph[u][v] && !visited[v]) {
                q.push(v);
                visited[v] = true;
                shortestPath[v] = shortestPath[u] + 1;
            }
        }
    }
}

void dfs(const vector<vector<int>>& graph, int start, int end, vector<bool>& visited, int length, int& maxLength) {
    if (start == end) {
        maxLength = max(maxLength, length);
        return;
    }

    visited[start] = true;

    for (int v = 0; v < graph.size(); ++v) {
        if (graph[start][v] && !visited[v]) {
            dfs(graph, v, end, visited, length + 1, maxLength);
        }
    }

    visited[start] = false;
}

int main() {
    int n, m;
    cin >> n >> m;

    // Initialize the adjacency matrix with zeros
    vector<vector<int>> graph(n, vector<int>(n, 0));

    // Read edges and build the adjacency matrix
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u][v] = graph[v][u] = 1; // assuming an undirected graph
    }

    int p, q;
    cin >> p >> q;

    // Use BFS to find the shortest path
    vector<int> shortestPath(n, INF);
    bfs(graph, p, q, shortestPath);

    // Use DFS to find the longest path
    vector<bool> visited(n, false);
    int maxLength = 0;
    dfs(graph, p, q, visited, 0, maxLength);

    cout << "Shortest Path Length (BFS): " << shortestPath[q] << endl;
    cout << "Longest Path Length (DFS): " << maxLength << endl;

    return 0;
}
