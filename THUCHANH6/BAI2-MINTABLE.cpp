#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <utility>
#include <climits>
#include <algorithm>

#define IN "I2.txt"
#define OUT "O2.txt"

using namespace std;

const int MAX = 105;
const int INF = INT_MAX;

int N, M, startX, startY, endX, endY;
int A[MAX][MAX];
int dist[MAX][MAX];
pair<int, int> parent[MAX][MAX];
bool visited[MAX][MAX];

int dx[] = {-1, 1, 0, 0}; // lên, xuống
int dy[] = {0, 0, -1, 1}; // trái, phải

bool isValid(int x, int y) {
    return x >= 1 && x <= N && y >= 1 && y <= M && A[x][y] != 0;
}

void dijkstra() {
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j)
            dist[i][j] = INF;

    priority_queue< pair<int, pair<int, int> >,
                    vector< pair<int, pair<int, int> > >,
                    greater< pair<int, pair<int, int> > > > pq;

    dist[startX][startY] = 0;
    pq.push(make_pair(0, make_pair(startX, startY)));

    while (!pq.empty()) {
        pair<int, pair<int, int> > cur = pq.top(); pq.pop();
        int d = cur.first;
        int x = cur.second.first;
        int y = cur.second.second;

        if (visited[x][y]) continue;
        visited[x][y] = true;

        for (int dir = 0; dir < 4; ++dir) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (isValid(nx, ny)) {
                int cost = (nx == startX && ny == startY) || (nx == endX && ny == endY) ? 0 : A[nx][ny];
                if (dist[nx][ny] > dist[x][y] + cost) {
                    dist[nx][ny] = dist[x][y] + cost;
                    parent[nx][ny] = make_pair(x, y);
                    pq.push(make_pair(dist[nx][ny], make_pair(nx, ny)));
                }
            }
        }
    }
}

vector< pair<int, int> > reconstructPath() {
    vector< pair<int, int> > path;
    int x = endX, y = endY;
    while (!(x == startX && y == startY)) {
        path.push_back(make_pair(x, y));
        pair<int, int> p = parent[x][y];
        x = p.first;
        y = p.second;
    }
    path.push_back(make_pair(startX, startY));
    reverse(path.begin(), path.end());
    return path;
}

int main() {
    ifstream fin(IN);
    ofstream fout(OUT);

    fin >> N >> M >> startX >> startY >> endX >> endY;
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j)
            fin >> A[i][j];

    if (!isValid(startX, startY) || !isValid(endX, endY)) {
        fout << 0 << endl;
        return 0;
    }

    dijkstra();

    if (dist[endX][endY] == INF) {
        fout << 0 << endl;
    } else {
        fout << 1 << endl;
        fout << dist[endX][endY] << endl;
        vector< pair<int, int> > path = reconstructPath();
        for (size_t i = 0; i < path.size(); ++i)
            fout << path[i].first << " " << path[i].second << endl;
    }

    fin.close();
    fout.close();
    return 0;
}
