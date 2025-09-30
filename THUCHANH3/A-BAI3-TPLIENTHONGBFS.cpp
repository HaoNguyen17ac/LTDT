#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <sstream>
#include <algorithm>

#define IN  "I3.txt"
#define OU  "O3.txt"

using namespace std;

const int MAXN = 100005;
vector<int> adj[MAXN];
bool visited[MAXN];

void readAdjList(int &n, istream &in) {
    in >> n;
    in.ignore(); 

    for (int i = 1; i <= n; ++i) {
        string line;
        getline(in, line);
        stringstream ss(line);
        int neighbor;
        while (ss >> neighbor) {
            if (neighbor == -1) break;
            adj[i].push_back(neighbor);
        }
    }
}

void findComponents(int n, vector< vector<int> > &components) {
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            vector<int> component;
            queue<int> q;
            visited[i] = true;
            q.push(i);

            while (!q.empty()) {
                int u = q.front(); q.pop();
                component.push_back(u);

                for (size_t j = 0; j < adj[u].size(); ++j) {
                    int v = adj[u][j];
                    if (!visited[v]) {
                        visited[v] = true;
                        q.push(v);
                    }
                }
            }

            sort(component.begin(), component.end());
            components.push_back(component);
        }
    }
}

void printComponents(const vector< vector<int> > &components, ostream &out) {
    out << components.size() << "\n";
    for (size_t i = 0; i < components.size(); ++i) {
        for (size_t j = 0; j < components[i].size(); ++j) {
            out << components[i][j] << " ";
        }
        out << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);

    ifstream fin(IN);
    ofstream fout(OU);

    int n;
    vector< vector<int> > components;

    readAdjList(n, fin);
    findComponents(n, components);
    printComponents(components, fout);

    fin.close();
    fout.close();

    return 0;
}
