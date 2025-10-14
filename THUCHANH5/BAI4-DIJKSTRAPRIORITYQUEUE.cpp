#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cstdio>
#include <algorithm>

using namespace std;

#define IN "I4.txt"
#define OUT "O4.txt"

const int MAXN = 1001;
vector<pair<int, int> > adj[MAXN];
int dist[MAXN], prevNode[MAXN];
bool visited[MAXN];

void dijkstra(int s, int n) {
    for (int i = 1; i <= n; ++i) {
        dist[i] = INT_MAX;
        visited[i] = false;
        prevNode[i] = -1;
    }

    dist[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    pq.push(make_pair(0, s));

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (visited[u]) continue;
        visited[u] = true;

        for (size_t i = 0; i < adj[u].size(); ++i) {
            int v = adj[u][i].first;
            int w = adj[u][i].second;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                prevNode[v] = u;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
}

vector<int> getPath(int t) {
    vector<int> path;
    while (t != -1) {
        path.push_back(t);
        t = prevNode[t];
    }
    reverse(path.begin(), path.end());
    return path;
}

int main() {
    freopen(IN, "r", stdin);
    freopen(OUT, "w", stdout);

    int n, m, s, t;
    cin >> n >> m >> s >> t;

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(v, w));
    }

    dijkstra(s, n);
    vector<int> path = getPath(t);

    if (dist[t] == INT_MAX) {
        cout << "-1\n"; 
    } else {
        cout << path.size() << " " << dist[t] << endl;
        for (size_t i = 0; i < path.size(); ++i) {
            cout << path[i];
            if (i + 1 < path.size()) cout << " ";
        }
        cout << endl;
    }

    return 0;
}
