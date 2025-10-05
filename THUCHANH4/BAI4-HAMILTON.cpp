#include <iostream>
#include <vector>
#include <cstdio>

#define IN "I4.txt"
#define OU "O4.txt"

using namespace std;

int n;
vector<vector<int> > adj;
vector<bool> visited;
vector<int> path;
bool found = false;

void readInput() {
    freopen(IN, "r", stdin);
    cin >> n;
    adj.resize(n, vector<int>(n));
    visited.resize(n, false);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> adj[i][j];
}

void writeOutput() {
    freopen(OU, "w", stdout);
    if (found) {
        cout << "1\n";
        for (int i = 0; i < path.size(); ++i)
            cout << path[i] + 1 << " ";
        cout << path[0] + 1 << "\n";
    } else {
        cout << "0\n";
    }
}

void backtrack(int u, int depth) {
    if (found) return;
    path.push_back(u);
    visited[u] = true;
    if (depth == n) {
        if (adj[u][path[0]] == 1) {
            found = true;
        }
    } else {
        for (int v = 0; v < n; ++v) {
            if (!visited[v] && adj[u][v] == 1) {
                backtrack(v, depth + 1);
            }
        }
    }
    if (!found) {
        visited[u] = false;
        path.pop_back();
    }
}

void solveHamiltonCycle() {
    path.clear();
    fill(visited.begin(), visited.end(), false);
    backtrack(0, 1);
}

int main() {
    readInput();
    solveHamiltonCycle();
    writeOutput();
    return 0;
}
