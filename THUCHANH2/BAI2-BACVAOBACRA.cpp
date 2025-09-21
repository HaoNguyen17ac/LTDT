#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream fin("BacVaoBacRa.inp"); // Đọc từ file input
    ofstream fout("BacVaoBacRa.out"); // Ghi ra file output
 
    int n;
    fin >> n; // Số đỉnh của đồ thị

    int a[1001][1001]; // Giới hạn n ≤ 1000
    int inDegree[1001] = {0}; // Bậc vào
    int outDegree[1001] = {0}; // Bậc ra

    // Đọc ma trận và tính bậc vào / bậc ra
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            fin >> a[i][j];
            if (a[i][j] == 1) {
                outDegree[i]++;   // Đỉnh i có cạnh đi ra
                inDegree[j]++;    // Đỉnh j có cạnh đi vào
            }
        }
    }

    // Ghi kết quả ra file
    fout << n << endl;
    for (int i = 1; i <= n; ++i) {
        fout << inDegree[i] << " " << outDegree[i] << endl;
    }

    fin.close(); // Đóng file input
    fout.close(); // Đóng file output

    return 0;
}
