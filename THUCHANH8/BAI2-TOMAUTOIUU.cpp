#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 100;
vector<int> adj[MAXN];
int color[MAXN], bestColor[MAXN], n, m;
int minColor = MAXN;

bool isSafe(int u, int c) {
    for (int v : adj[u]) {
        if (color[v] == c) return false;
    }
    return true;
}

void backtrack(int u, int k) {
    if (u == n) {
        if (k < minColor) {
            minColor = k;
            for (int i = 0; i < n; ++i) bestColor[i] = color[i];
        }
        return;
    }

    for (int c = 1; c <= k; ++c) {
        if (isSafe(u, c)) {
            color[u] = c;
            backtrack(u + 1, k);
            color[u] = 0;
        }
    }

    color[u] = k + 1;
    backtrack(u + 1, k + 1);
    color[u] = 0;
}

void optimalColoring() {
    backtrack(0, 0);
    cout << "Tô màu tối ưu:\n";
    cout << "Số màu tối thiểu: " << minColor << endl;
    for (int c = 1; c <= minColor; ++c) {
        cout << "Màu " << c << ": ";
        for (int i = 0; i < n; ++i) {
            if (bestColor[i] == c) cout << i + 1 << " ";
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

    optimalColoring();
    return 0;
}
