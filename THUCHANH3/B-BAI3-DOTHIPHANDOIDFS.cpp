#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <sstream>

#define IN "IB3.txt"
#define OU "OB3.txt"

using namespace std;

const int MAXN = 100005;
vector<int> adj[MAXN];
int color[MAXN];

void readGraph(ifstream &fin, int &n) {
    string line;
    fin >> n;
    fin.ignore();
    for (int u = 1; u <= n; ++u) {
        getline(fin, line);
        stringstream ss(line);
        int v;
        while (ss >> v) {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }
}

bool isBipartite(int n) {
    for (int i = 1; i <= n; ++i) {
        color[i] = -1;
    }
    for (int start = 1; start <= n; ++start) {
        if (color[start] == -1) {
            queue<int> q;
            q.push(start);
            color[start] = 0;
            while (!q.empty()) {
                int u = q.front(); q.pop();
                for (size_t i = 0; i < adj[u].size(); ++i) {
                    int v = adj[u][i];
                    if (color[v] == -1) {
                        color[v] = 1 - color[u];
                        q.push(v);
                    } else if (color[v] == color[u]) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

void writeResult(ofstream &fout, bool result) {
    if (result) {
        fout << "Do thi phan doi" << endl;
    } else {
        fout << "Do thi khong phan doi" << endl;
    }
}

int main() {
    ifstream fin(IN);
    ofstream fout(OU);

    int n;
    readGraph(fin, n);

    bool result = isBipartite(n);
    writeResult(fout, result);
    fin.close();
    fout.close();
    
    return 0;
}
