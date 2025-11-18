#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

#define IN "I3.txt"
#define OUT "O3.txt"

using namespace std;

const int MAXN = 100005;

int n, m;
vector<int> adj[MAXN];
int team[MAXN];

void readInput() {
    ifstream fin(IN);
    fin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        fin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    fin.close();
}

bool bfs(int start) {
    queue<int> q;
    q.push(start);
    team[start] = 1;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (size_t i = 0; i < adj[u].size(); ++i) {
            int v = adj[u][i];
            if (team[v] == 0) {
                team[v] = 3 - team[u];
                q.push(v);
            } else if (team[v] == team[u]) {
                return false;
            }
        }
    }
    return true;
}

bool assignTeams() {
    for (int i = 1; i <= n; ++i) {
        if (team[i] == 0) {
            if (!bfs(i)) {
                return false;
            }
        }
    }
    return true;
}

void writeOutput(bool possible) {
    ofstream fout(OUT);
    if (!possible) {
        fout << "IMPOSSIBLE\n";
    } else {
        for (int i = 1; i <= n; ++i) {
            fout << team[i] << " ";
        }
        fout << "\n";
    }
    fout.close();
}

int main() {
    readInput();
    bool possible = assignTeams();
    writeOutput(possible);
    return 0;
}
