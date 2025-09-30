#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <set>
#include <string>
#include <cctype>
using namespace std;

#define IN  "I4.txt"
#define OU  "O4.txt"

int n, x, y, z;
vector<vector<int> > adj;

void readInput() {
    ifstream fin(IN);
    fin >> n >> x >> y >> z;
    fin.ignore();

    adj.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        string line;
        getline(fin, line);
        int num = 0;
        for (size_t j = 0; j < line.size(); ++j) {
            char c = line[j];
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            } else if (num > 0) {
                adj[i].push_back(num);
                num = 0;
            }
        }
        if (num > 0) adj[i].push_back(num);
    }
    fin.close();
}

void bfs(int start, vector<bool>& visited, set<pair<int, int> >& removedEdges, int removedNode) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (size_t i = 0; i < adj[u].size(); ++i) {
            int v = adj[u][i];
            if (u == removedNode || v == removedNode) continue;
            if (removedEdges.count(make_pair(u, v))) continue;
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

bool isBridge(int a, int b) {
    vector<bool> visited(n + 1, false);
    set<pair<int, int> > removedEdges;
    removedEdges.insert(make_pair(a, b));
    bfs(1, visited, removedEdges, -1);
    for (int i = 1; i <= n; ++i)
        if (!visited[i]) return true;
    return false;
}

bool isArticulation(int node) {
    vector<bool> visited(n + 1, false);
    int start = (node == 1) ? 2 : 1;
    set<pair<int, int> > emptySet;
    bfs(start, visited, emptySet, node);
    for (int i = 1; i <= n; ++i)
        if (i != node && !visited[i]) return true;
    return false;
}

void writeOutput(bool bridge, bool articulation) {
    ofstream fout(OU);
    fout << (bridge ? "canh cau" : "khong la canh cau") << endl;
    fout << (articulation ? "dinh khop" : "khong la dinh khop") << endl;
    fout.close();
}

int main() {
    readInput();
    bool bridge = isBridge(x, y);
    bool articulation = isArticulation(z);
    writeOutput(bridge, articulation);
    return 0;
}
