#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<vector<int>> graph;
vector<bool> visited;
int v;

// Add Edge
void add_edge(int src, int dest, bool bi_dir = true) {
    graph[src].push_back(dest);
    if (bi_dir) {
        graph[dest].push_back(src);
    }
}

// Display Graph
void display() {
    cout << "\nAdjacency List:\n";
    for (int i = 0; i < v; i++) {
        cout << i << " -> ";
        for (auto neighbour : graph[i]) {
            cout << neighbour << " ";
        }
        cout << endl;
    }
}

// DFS
void dfs(int node) {
    visited[node] = true;
    cout << node << " ";

    for (auto neighbour : graph[node]) {
        if (!visited[neighbour]) {
            dfs(neighbour);
        }
    }
}

// BFS
void bfs(int start) {
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        cout << node << " ";

        for (auto neighbour : graph[node]) {
            if (!visited[neighbour]) {
                visited[neighbour] = true;
                q.push(neighbour);
            }
        }
    }
}

int main() {

    cin >> v;

    graph.resize(v);

    int e;
    cin >> e;

    while (e--) {
        int s, d;
        cin >> s >> d;
        add_edge(s, d);
    }

    display();

    // DFS
    visited.assign(v, false);
    cout << "\nDFS Traversal: ";
    dfs(0);

    // BFS
    visited.assign(v, false);
    cout << "\nBFS Traversal: ";
    bfs(0);

    return 0;
}