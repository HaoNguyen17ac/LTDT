#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <queue>

#define IN "I1.txt"
#define OUT "O1.txt"

using namespace std;

const double EPS = 1e-6;

struct Circle {
    double x, y, r;
};

int N, S, T;
vector<Circle> circles;
vector<vector<int> > adj;
vector<int> parent;

bool canStep(int i, int j) {
    double dx = circles[i].x - circles[j].x;
    double dy = circles[i].y - circles[j].y;
    double dist = sqrt(dx * dx + dy * dy);
    double minDist = dist - circles[i].r - circles[j].r;
    return minDist <= 50.0 + EPS;
}

bool bfs(int s, int t) {
    vector<bool> visited(N, false);
    parent.assign(N, -1);
    queue<int> q;

    visited[s] = true;
    q.push(s);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (u == t) return true;
        for (size_t i = 0; i < adj[u].size(); ++i) {
            int v = adj[u][i];
            if (!visited[v]) {
                visited[v] = true;
                parent[v] = u;
                q.push(v);
            }
        }
    }
    return false;
}

int main() {
    ifstream fin(IN);
    ofstream fout(OUT);

    fin >> N >> S >> T;
    --S; --T;

    circles.resize(N);
    for (int i = 0; i < N; ++i) {
        fin >> circles[i].x >> circles[i].y >> circles[i].r;
    }

    adj.resize(N);
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            if (canStep(i, j)) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    if (!bfs(S, T)) {
        fout << 0 << endl;
    } else {
        fout << 1 << endl;

        vector<int> path;
        int cur = T;
        while (cur != -1) {
            path.push_back(cur);
            cur = parent[cur];
        }

        int steps = path.size() - 1;
        int circlesPassed = path.size();

        fout << steps << " " << circlesPassed << endl;
        for (int i = path.size() - 1; i >= 0; --i) {
            int c = (i == 0 || i == path.size() - 1) ? 0 : 1;
            fout << (path[i] + 1) << " " << c << endl;
        }
    }

    fin.close();
    fout.close();
    return 0;
}
