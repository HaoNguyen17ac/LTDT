#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cctype>

#define IN  "IB1.txt"
#define OU  "OB1.txt"

using namespace std;

const int MAXN = 100005;
vector<int> adj[MAXN];
bool visited[MAXN];
vector<int> result;
int n, x;

void readInput(ifstream &fin) {
    fin >> n >> x;
    fin.ignore();
    for (int i = 1; i <= n; ++i) {
        string line;
        getline(fin, line);
        int num = 0;
        for (size_t j = 0; j < line.size(); ++j) {
            char ch = line[j];
            if (isdigit(ch)) {
                num = num * 10 + (ch - '0');
            } else if (ch == ' ') {
                if (num > 0) {
                    adj[i].push_back(num);
                    num = 0;
                }
            }
        }
        if (num > 0) {
            adj[i].push_back(num);
        }
    }
}

void dfs(int u) {
    visited[u] = true;
    for (size_t i = 0; i < adj[u].size(); ++i) {
        int v = adj[u][i];
        if (!visited[v]) {
            visited[v] = true;
            result.push_back(v);
            dfs(v);
        }
    }
}

void writeOutput(ofstream &fout) {
    fout << result.size() << endl;
    for (size_t i = 0; i < result.size(); ++i) {
        fout << result[i] << " ";
    }
    fout << endl;
}

int main() {
    ifstream fin(IN);
    ofstream fout(OU);
    if (!fin || !fout) {
        return 1;
    }
    readInput(fin);
    visited[x] = true;
    dfs(x);
    writeOutput(fout);
    fin.close();
    fout.close();
    return 0;
}
