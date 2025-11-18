#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

const int MAXN = 100;
vector<int> adj[MAXN];
int color[MAXN], n, m;

bool compareDegree(int a, int b) {
    return adj[a].size() > adj[b].size();
}

void greedyColoring() {
    vector<int> order(n);
    for (int i = 0; i < n; ++i) order[i] = i;
    sort(order.begin(), order.end(), compareDegree);

    for (int u : order) {
        set<int> used;
        for (int v : adj[u]) {
            if (color[v] != 0) used.insert(color[v]);
        }
        int c = 1;
        while (used.count(c)) ++c;
        color[u] = c;
    }

    cout << "Tô màu tham lam:\n";
    set<int> usedColors;
    for (int i = 0; i < n; ++i) usedColors.insert(color[i]);
    cout << "Số màu dùng: " << usedColors.size() << endl;
    for (int c : usedColors) {
        cout << "Màu " << c << ": ";
        for (int i = 0; i < n; ++i) {
            if (color[i] == c) cout << i + 1 << " ";
        }
        cout << endl;
    }
}

int main() {
    cout << "Nhập số đỉnh và số cạnh: ";
    cin >> n >> m;
    cout << "Nhập các cạnh (u v):\n";
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }

    greedyColoring();
    return 0;
}
