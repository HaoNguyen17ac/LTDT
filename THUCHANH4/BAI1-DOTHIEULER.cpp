#include <iostream>
#include <vector>
#include <stack>
#include <cstdio>
using namespace std;

#define IN "I1.txt"
#define OU "O1.txt"

const int MAXN = 105;
int adj[MAXN][MAXN]; 
bool visited[MAXN];
vector<int> euler_path;
int n;

void dfs(int u) {
    visited[u] = true;
    for (int v = 1; v <= n; ++v) {
        if (adj[u][v] && !visited[v])
            dfs(v);
    }
}

void findEuler(int u) {
    for (int v = 1; v <= n; ++v) {
        while (adj[u][v]) {
            adj[u][v]--;
            adj[v][u]--;
            findEuler(v);
        }
    }
    euler_path.push_back(u);
}

int main() {
    freopen(IN, "r", stdin);
    freopen(OU, "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> adj[i][j];

    for (int i = 1; i <= n; ++i)
        visited[i] = false;
    dfs(1);
    for (int i = 1; i <= n; ++i) {
        bool hasEdge = false;
        for (int j = 1; j <= n; ++j)
            if (adj[i][j]) hasEdge = true;
        if (hasEdge && !visited[i]) {
            cout << 0 << endl;
            return 0;
        }
    }

    for (int i = 1; i <= n; ++i) {
        int deg = 0;
        for (int j = 1; j <= n; ++j)
            deg += adj[i][j];
        if (deg % 2 != 0) {
            cout << 0 << endl;
            return 0;
        }
    }

    findEuler(1);
    cout << 1 << endl;
    for (int i = euler_path.size() - 1; i >= 0; --i)
        cout << euler_path[i] << " ";
    cout << endl;

    return 0;
}
