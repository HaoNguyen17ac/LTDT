#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream fin("MaTranKe.inp"); // file input
    ofstream fout("MaTranKe.out"); // file output

    int n;
    fin >> n; // Nhập số đỉnh

    int a[1001][1001]; // Giới hạn n ≤ 1000
    int degree[1001] = {0};

    // Đọc ma trận và tính bậc
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            fin >> a[i][j];
            if (a[i][j] == 1) {
                degree[i]++;
            }
        }
    }

    // Ghi kết quả ra file
    fout << n << endl;
    for (int i = 1; i <= n; ++i) {
        fout << degree[i] << endl;
    }

    fin.close(); // đóng file input
    fout.close(); // đóng file output

    return 0;
}
