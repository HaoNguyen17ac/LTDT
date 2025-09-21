#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    ifstream fin("DanhSachCanh.inp");
    ofstream fout("DanhSachCanh.out");

    int n, m;
    fin >> n >> m;

    vector< vector<int> > adj(n + 1); // danh sách kề

    for (int i = 0; i < m; ++i) {
        int u, v;
        fin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u); // vì đồ thị vô hướng
    }

    fout << n << endl;
    for (int i = 1; i <= n; ++i) {
        fout << adj[i].size() << endl; // bậc của đỉnh i
    }

    fin.close();
    fout.close();

    return 0;
}
