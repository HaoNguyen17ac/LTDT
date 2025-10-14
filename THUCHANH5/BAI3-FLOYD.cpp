#include <iostream>
using namespace std;

#define IN "I3.txt"
#define OUT "O3.txt"

const int INF = 1000000000;
const int MAXN = 1000;

int dist[MAXN + 1][MAXN + 1];
int n, m;

void initMatrix() {
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            dist[i][j] = (i == j) ? 0 : INF;
}

void inputData() {
    freopen(IN, "r", stdin);
    cin >> n >> m;
    initMatrix();
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        if (w < dist[u][v]) {
            dist[u][v] = w;
            dist[v][u] = w; 
        }
    }
}

void floydWarshall() {
    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                if (dist[i][k] < INF && dist[k][j] < INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}

void outputResult() {
    freopen(OUT, "w", stdout);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    inputData();
    floydWarshall();
    outputResult();
    return 0;
}
