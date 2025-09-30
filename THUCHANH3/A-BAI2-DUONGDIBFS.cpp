#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
#include <algorithm>
#include <string>

#define IN  "I2.txt"
#define OU  "O2.txt"

using namespace std;

const int MAXN = 100005;
vector<int> adj[MAXN];
int parent[MAXN];
bool visited[MAXN];
int n, x, y;

void readInput() {
    cin >> n >> x >> y;
    cin.ignore(); 

    for (int i = 1; i <= n; ++i) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        int neighbor;
        while (ss >> neighbor) {
            if (neighbor == i) continue;
            adj[i].push_back(neighbor);
        }
    }
}

void bfs(int start) {
    queue<int> q;
    visited[start] = true;
    parent[start] = -1;
    q.push(start);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (vector<int>::iterator it = adj[u].begin(); it != adj[u].end(); ++it) {
            int v = *it;
            if (!visited[v]) {
                visited[v] = true;
                parent[v] = u;
                q.push(v);
            }
        }
    }
}

void tracePath(int target) {
    if (!visited[target]) {
        cout << "0\n";
        return;
    }

    vector<int> path;
    for (int cur = target; cur != -1; cur = parent[cur]) {
        path.push_back(cur);
    }
    reverse(path.begin(), path.end());

    cout << path.size() << "\n";
    for (vector<int>::iterator it = path.begin(); it != path.end(); ++it) {
        cout << *it << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    freopen(IN, "r", stdin);
    freopen(OU, "w", stdout);

    readInput();
    bfs(x);
    tracePath(y);

    return 0;
}
