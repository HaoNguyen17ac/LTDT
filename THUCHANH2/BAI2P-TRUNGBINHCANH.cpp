#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    ifstream fin("TrungBinhCanh.inp");
    ofstream fout("TrungBinhCanh.out");

    int n;
    fin >> n;

    vector< vector<int> > weight(n, vector<int>(n));
    int maxLength = 0;
    int totalLength = 0;
    int edgeCount = 0;
    vector<int> longestEdges;

    // Đọc ma trận trọng số
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fin >> weight[i][j];
        }
    }

    // Duyệt qua các cạnh (chỉ duyệt 1 lần vì đồ thị vô hướng)
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int w = weight[i][j];
            if (w > 0) {
                totalLength += w;
                edgeCount++;
                if (w > maxLength) {
                    maxLength = w;
                    longestEdges.clear();
                    longestEdges.push_back(w);
                } else if (w == maxLength) {
                    longestEdges.push_back(w);
                }
            }
        }
    }

    // Ghi kết quả ra file
    fout << longestEdges.size() << endl;

    for (int i = 0; i < longestEdges.size(); i++) {
        fout << longestEdges[i] << " ";
    }
    fout << endl;

    if (edgeCount > 0) {
        double average = (double)totalLength / edgeCount;
        fout << average << endl;
    } else {
        fout << 0 << endl;
    }

    fin.close();
    fout.close();
    return 0;
}
