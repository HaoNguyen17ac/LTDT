#include <iostream>
#include <vector>
#include <stack>
#include <cstdio>
using namespace std;

#define IN "I6.txt"
#define OU "O6.txt"

const int MAXN = 105;
vector<int> adj[MAXN];      
bool visited[MAXN];       
vector<int> euler_path;
int n;

void dfs_iterative(int start) {
    stack<int> st;
    st.push(start);
    while (!st.empty()) {
        int u = st.top();
        st.pop();
        if (!visited[u]) {
            visited[u] = true;
            for (size_t i = 0; i < adj[u].size(); ++i) {
                int v = adj[u][i];
                if (!visited[v])
                    st.push(v);
            }
        }
    }
}

void findEuler_iterative(int start) {
    vector<vector<int> > temp_adj(MAXN);
    for (int i = 1; i <= n; ++i)
        temp_adj[i] = adj[i];

    stack<int> st;
    st.push(start);

    while (!st.empty()) {
        int u = st.top();
        if (!temp_adj[u].empty()) {
            int v = temp_adj[u].back();
            temp_adj[u].pop_back();
            for (vector<int>::iterator it = temp_adj[v].begin(); it != temp_adj[v].end(); ++it) {
                if (*it == u) {
                    temp_adj[v].erase(it);
                    break;
                }
            }
            st.push(v);
        } else {
            euler_path.push_back(u);
            st.pop();
        }
    }
}

int main() {
    freopen(IN, "r", stdin);
    freopen(OU, "w", stdout);

    cin >> n;
    cin.ignore(); 

    for (int i = 1; i <= n; ++i) {
        string line;
        getline(cin, line);
        int v = 0;
        for (size_t j = 0; j <= line.size(); ++j) {
            if (j == line.size() || line[j] == ' ') {
                if (v > 0) {
                    adj[i].push_back(v);
                    adj[v].push_back(i); 
                    v = 0;
                }
            } else {
                v = v * 10 + (line[j] - '0');
            }
        }
    }

    for (int i = 1; i <= n; ++i)
        visited[i] = false;
    dfs_iterative(1);

    for (int i = 1; i <= n; ++i) {
        if (!adj[i].empty() && !visited[i]) {
            cout << 0 << endl;
            return 0;
        }
    }

    // Kiểm tra bậc chẵn
    for (int i = 1; i <= n; ++i) {
        if (adj[i].size() % 2 != 0) {
            cout << 0 << endl;
            return 0;
        }
    }

    findEuler_iterative(1);
    cout << 1 << endl;
    for (int i = euler_path.size() - 1; i >= 0; --i)
        cout << euler_path[i] << " ";
    cout << endl;

    return 0;
}
