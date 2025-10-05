#include <iostream>
#include <vector>
#include <utility>
using namespace std;

#define IN "I2.txt"
#define OU "O2.txt"

struct Domino {
    int x, y;
    bool used;
    Domino(int a, int b) : x(a), y(b), used(false) {}
};

int n;
vector<Domino> dominos;
vector<pair<int, int> > result;

void readInput() {
    cin >> n;
    dominos.clear();
    result.clear();
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        dominos.push_back(Domino(x, y));
    }
}

void writeOutput(bool success) {
    cout << (success ? "1" : "0") << endl;
    if (success) {
        for (int i = 0; i < n; ++i) {
            cout << result[i].first << " " << result[i].second << endl;
        }
    }
}

bool dfs(int depth, int last, int start) {
    if (depth == n) {
        return (last == start);
    }
    for (int i = 0; i < n; ++i) {
        if (!dominos[i].used) {
            int a = dominos[i].x;
            int b = dominos[i].y;
            if (a == last) {
                dominos[i].used = true;
                result.push_back(make_pair(a, b));
                if (dfs(depth + 1, b, start)) return true;
                result.pop_back();
                dominos[i].used = false;
            }
            if (b == last) {
                dominos[i].used = true;
                result.push_back(make_pair(b, a));
                if (dfs(depth + 1, a, start)) return true;
                result.pop_back();
                dominos[i].used = false;
            }
        }
    }
    return false;
}

bool solve() {
    for (int i = 0; i < n; ++i) {
        dominos[i].used = true;

        result.push_back(make_pair(dominos[i].x, dominos[i].y));
        if (dfs(1, dominos[i].y, dominos[i].x)) return true;
        result.pop_back();

        result.push_back(make_pair(dominos[i].y, dominos[i].x));
        if (dfs(1, dominos[i].x, dominos[i].y)) return true;
        result.pop_back();

        dominos[i].used = false;
    }
    return false;
}

int main() {
    freopen(IN, "r", stdin);
    freopen(OU, "w", stdout);

    readInput();
    bool success = solve();
    writeOutput(success);
    return 0;
}
