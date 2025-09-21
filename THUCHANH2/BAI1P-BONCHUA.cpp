#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    ifstream fin("BonChua.inp");
    ofstream fout("BonChua.out");

    int n;
    fin >> n;

    vector< vector<int> > adj(n, vector<int>(n));
    vector<int> bonChua;

    // Đọc ma trận kề
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fin >> adj[i][j];
        }
    }

    // Kiểm tra từng đỉnh xem có phải là bồn chứa không
    for (int i = 0; i < n; i++) {
        bool hasOutEdge = false;
        for (int j = 0; j < n; j++) {
            if (adj[i][j] == 1) {
                hasOutEdge = true;
                break;
            }
        }
        if (!hasOutEdge) {
            bonChua.push_back(i + 1); // Đánh số từ 1
        }
    }

    // Ghi kết quả ra file
    fout << bonChua.size() << endl;
    if (bonChua.size() > 0) {
        for (int i = 0; i < bonChua.size(); i++) {
            fout << bonChua[i] << " ";
        }
        fout << endl;
    }

    fin.close();
    fout.close();
    return 0;
}
