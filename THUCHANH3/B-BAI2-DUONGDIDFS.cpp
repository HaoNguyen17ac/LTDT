#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

const int MAX = 100005;

vector<int> adj[MAX];
bool visited[MAX];
int parent[MAX];
int n, x, y;
bool found = false;

void readGraph() {
    cin >> n >> x >> y;
    cin.ignore(1000, '\n');
    for (int i = 1; i <= n; ++i) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        int v;
        while (ss >> v) {
            if (v != i) {
                adj[i].push_back(v);
                adj[v].push_back(i);
            }
        }
    }
}

void DFS(int u) {
    if (found) return;
    visited[u] = true;
    if (u == y) {
        found = true;
        return;
    }
    for (size_t i = 0; i < adj[u].size(); ++i) {
        int v = adj[u][i];
        if (!visited[v]) {
            parent[v] = u;
            DFS(v);
        }
    }
}

void tracePath() {
    if (!visited[y]) {
        cout << -1 << endl;
        return;
    }
    vector<int> path;
    int cur = y;
    while (cur != -1) {
        path.push_back(cur);
        cur = parent[cur];
    }
    reverse(path.begin(), path.end());
    cout << path.size() << endl;
    for (size_t i = 0; i < path.size(); ++i) {
        cout << path[i] << " ";
    }
    cout << endl;
}

void solve() {
    for (int i = 0; i <= n; ++i) {
        visited[i] = false;
        parent[i] = -1;
    }
    DFS(x);
    tracePath();
}

int main() {
    readGraph();
    solve();
    return 0;
}