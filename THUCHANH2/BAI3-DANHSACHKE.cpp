#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

int main() {
    ifstream fin("DanhSachKe.inp"); // Đọc từ file input
    ofstream fout("DanhSachKe.out"); // Ghi ra file output

    int n;
    fin >> n;
    fin.ignore(); // Bỏ qua ký tự xuống dòng sau số n

    vector< vector<int> > adjList(n + 1); // Đánh số từ 1 đến n

    // Đọc danh sách kề từ file
    for (int i = 1; i <= n; ++i) {
        string line; 
        getline(fin, line); // 
        stringstream ss(line);
        int v;
        while (ss >> v) {
            adjList[i].push_back(v);
        }
    }

    // Ghi kết quả ra file
    fout << n << endl;
    for (int i = 1; i <= n; ++i) {
        fout << adjList[i].size() << endl;
    }

    fin.close(); // Đóng file input
    fout.close(); // Đóng file output

    return 0;
}