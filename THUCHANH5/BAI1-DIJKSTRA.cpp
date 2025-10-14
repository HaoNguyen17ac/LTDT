#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>

#define IN "I1.txt"
#define OUT "O1.txt"

using namespace std;

const int INF = 1000000000;

struct Edge {
    int to, weight;
};

void readInput(int &n, int &m, int &s, int &t, vector<vector<Edge> > &adj) {
    cin >> n >> m >> s >> t;
    adj.resize(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back((Edge){v, w});
    }
}

void dijkstra(int n, int s, const vector<vector<Edge> > &adj, vector<int> &dist, vector<int> &prev) {
    dist.assign(n + 1, INF);
    prev.assign(n + 1, -1);
    dist[s] = 0;

    priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > pq;
    pq.push(make_pair(0, s));

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (size_t i = 0; i < adj[u].size(); ++i) {
            int v = adj[u][i].to;
            int w = adj[u][i].weight;

            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                prev[v] = u;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
}

void writeOutput(int t, const vector<int> &dist, const vector<int> &prev) {
    if (dist[t] == INF) {
        cout << -1 << endl;
    } else {
        vector<int> path;
        for (int v = t; v != -1; v = prev[v])
            path.push_back(v);

        reverse(path.begin(), path.end());

        cout << path.size() << " " << dist[t] << endl;

        for (size_t i = 0; i < path.size(); ++i) {
            cout << path[i];
            if (i + 1 < path.size()) cout << " ";
        }
        cout << endl;
    }
}

int main() {
    freopen(IN, "r", stdin);
    freopen(OUT, "w", stdout);

    int n, m, s, t;
    vector<vector<Edge> > adj;
    readInput(n, m, s, t, adj);

    vector<int> dist, prev;
    dijkstra(n, s, adj, dist, prev);

    writeOutput(t, dist, prev);

    return 0;
}
