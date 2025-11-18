#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>
#include <cstdlib>

#define IN "I1.txt"
#define OUT "O1.txt"

using namespace std;

const int MAXN = 1005;
vector<int> adj[MAXN];
int color[MAXN];
int n, m;

bool compareDegree(int a, int b) {
    if (adj[a].size() != adj[b].size())
        return adj[a].size() > adj[b].size();
    return a < b;
}

void readInput() {
    ifstream fin(IN);
    if (!fin.is_open()) exit(1);
    if (!(fin >> n)) {
        fin.close();
        exit(1);
    }
    for (int i = 1; i <= n; ++i) {
        adj[i].clear();
        color[i] = 0;
    }
    int u, v;
    m = 0;
    while (fin >> u >> v) {
        if (u >= 1 && u <= n && v >= 1 && v <= n) {
            adj[u].push_back(v);
            adj[v].push_back(u);
            m++;
        }
    }
    fin.close();
}

void welshPowellColoring() {
    vector<int> order;
    for (int i = 1; i <= n; ++i)
        order.push_back(i);
    sort(order.begin(), order.end(), compareDegree);
    int currentColor = 0;
    for (size_t i = 0; i < order.size(); ++i) {
        int u = order[i];
        if (color[u] != 0) continue;
        currentColor++;
        color[u] = currentColor;
        for (size_t j = 0; j < order.size(); ++j) {
            int v = order[j];
            if (color[v] == 0) {
                bool canColor = true;
                for (size_t k = 0; k < adj[v].size(); ++k) {
                    int w = adj[v][k];
                    if (color[w] == currentColor) {
                        canColor = false;
                        break;
                    }
                }
                if (canColor) color[v] = currentColor;
            }
        }
    }
}

void writeOutput() {
    ofstream fout(OUT);
    if (!fout.is_open()) exit(1);
    int maxColor = 0;
    for (int i = 1; i <= n; ++i)
        if (color[i] > maxColor) maxColor = color[i];
    vector<vector<int> > groups(maxColor + 1);
    for (int i = 1; i <= n; ++i)
        groups[color[i]].push_back(i);
    fout << maxColor << "\n";
    for (int c = 1; c <= maxColor; ++c) {
        sort(groups[c].begin(), groups[c].end());
        for (size_t j = 0; j < groups[c].size(); ++j)
            fout << groups[c][j] << " ";
        fout << "\n";
    }
    fout.close();
}

int main() {
    readInput();
    welshPowellColoring();
    writeOutput();
    return 0;
}
