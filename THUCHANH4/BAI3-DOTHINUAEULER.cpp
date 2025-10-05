#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstring>

#define IN "I3.txt"
#define OU "O3.txt"

using namespace std;

const int MAXN = 100;
vector<int> adj[MAXN];
bool visitedEdge[MAXN][MAXN];
int degree[MAXN];
int n;

void readInput() {
    cin >> n;
    int matrix[MAXN][MAXN];
    for (int i = 0; i < n; ++i) {
        degree[i] = 0;
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
            if (matrix[i][j]) {
                adj[i].push_back(j);
                degree[i]++;
            }
        }
    }
}

void dfsConnectivity(int u, bool visitedNode[]) {
    visitedNode[u] = true;
    for (size_t i = 0; i < adj[u].size(); ++i) {
        int v = adj[u][i];
        if (!visitedNode[v]) {
            dfsConnectivity(v, visitedNode);
        }
    }
}

bool isConnected(int start) {
    bool visitedNode[MAXN];
    memset(visitedNode, false, sizeof(visitedNode));
    dfsConnectivity(start, visitedNode);

    for (int i = 0; i < n; ++i) {
        if (degree[i] > 0 && !visitedNode[i]) {
            return false;
        }
    }
    return true;
}

int getStartVertexIfSemiEuler() {
    int oddCount = 0;
    int start = 0;
    for (int i = 0; i < n; ++i) {
        if (degree[i] % 2 != 0) {
            oddCount++;
            start = i;
        }
    }
    if (oddCount != 2) return -1;
    return start;
}

void dfsEuler(int u, vector<int>& path) {
    for (size_t i = 0; i < adj[u].size(); ++i) {
        int v = adj[u][i];
        if (!visitedEdge[u][v]) {
            visitedEdge[u][v] = visitedEdge[v][u] = true;
            dfsEuler(v, path);
        }
    }
    path.push_back(u + 1);
}

void printEulerPath(const vector<int>& path) {
    cout << "1\n";
    for (size_t i = 0; i < path.size(); ++i) {
        cout << path[i];
        if (i + 1 < path.size()) cout << " ";
    }
    cout << "\n";
}

int main() {
    freopen(IN, "r", stdin);   
    freopen(OU, "w", stdout);  

    readInput();

    int start = getStartVertexIfSemiEuler();
    if (start == -1 || !isConnected(start)) {
        cout << "0\n";
        return 0;
    }

    vector<int> eulerPath;
    dfsEuler(start, eulerPath);
    reverse(eulerPath.begin(), eulerPath.end());

    printEulerPath(eulerPath);
    return 0;
}
