#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <sstream>
#include <string>

#define IN  "I1.txt"
#define OU  "O1.txt"

using namespace std;

void readGraph(int &n, int &x, vector< vector<int> > &adj) {
    cin >> n >> x;
    cin.ignore();
    adj.assign(n + 1, vector<int>());
    for (int i = 1; i <= n; ++i) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        int u;
        while (ss >> u) {
            if (u != i) {
                adj[i].push_back(u);
                adj[u].push_back(i);
            }
        }
    }
}

vector<int> bfs(int x, const vector< vector<int> > &adj, vector<char> &visited) {
    queue<int> q;
    vector<int> result;
    q.push(x);
    visited[x] = true;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (size_t i = 0; i < adj[u].size(); ++i) {
            int v = adj[u][i];
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
                result.push_back(v);
            }
        }
    }
    return result;
}

void writeResult(const vector<int> &result) {
    cout << result.size() << endl;
    for (size_t i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }
    cout << endl;
}

int main() {
    freopen(IN, "r", stdin);
    freopen(OU, "w", stdout);

    int n, x;
    vector< vector<int> > adj;
    readGraph(n, x, adj);

    vector<char> visited(n + 1, false); 
    vector<int> result = bfs(x, adj, visited);

    sort(result.begin(), result.end());
    writeResult(result);

    return 0;
}
