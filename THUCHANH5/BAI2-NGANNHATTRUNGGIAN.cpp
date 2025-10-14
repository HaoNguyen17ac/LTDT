#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <cstdio>
#include <algorithm>

#define IN "I2.txt"
#define OUT "O2.txt"

using namespace std;

const int INF = 1000000000;

struct Edge {
    int to, weight;
};

int dijkstra(int start, const vector<vector<Edge> >& graph, vector<int>& trace, vector<int>& dist) {
    int n = graph.size();
    dist.assign(n, INF);
    trace.assign(n, -1);
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

    dist[start] = 0;
    pq.push(make_pair(0, start));

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (size_t i = 0; i < graph[u].size(); ++i) {
            int v = graph[u][i].to;
            int w = graph[u][i].weight;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                trace[v] = u;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    return 0;
}

vector<int> getPath(int start, int end, const vector<int>& trace) {
    vector<int> path;
    int current = end;
    while (current != -1) {
        path.push_back(current);
        if (current == start) break;
        current = trace[current];
    }
    if (path.back() != start) return vector<int>(); 
    reverse(path.begin(), path.end());
    return path;
}

bool contains(const vector<int>& path, int target) {
    for (size_t i = 0; i < path.size(); ++i)
        if (path[i] == target) return true;
    return false;
}

int main() {
    freopen(IN, "r", stdin);
    freopen(OUT, "w", stdout);

    int n, m, s, v, t;
    cin >> n >> m >> s >> v >> t;

    vector<vector<Edge> > graph(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, vv, w;
        cin >> u >> vv >> w;
        graph[u].push_back((Edge){vv, w});
    }

    vector<int> trace, dist;
    dijkstra(s, graph, trace, dist);
    vector<int> path = getPath(s, v, trace);

    if (path.empty() || !contains(path, t)) {
        cout << -1 << endl;
    } else {
        cout << path.size() << " " << dist[v] << endl;
        for (size_t i = 0; i < path.size(); ++i)
            cout << path[i] << " ";
        cout << endl;
    }

    return 0;
}
