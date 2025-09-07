#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

int main() {
    int nx, ny, nz;
    cin >> nx;
    vector<int> x(nx);
    for (int i = 0; i < nx; ++i) cin >> x[i];

    cin >> ny;
    vector<int> y(ny);
    for (int i = 0; i < ny; ++i) cin >> y[i];

    cin >> nz;
    vector<int> z(nz);
    for (int i = 0; i < nz; ++i) cin >> z[i];

    // Dùng unordered_set để lưu phần tử của từng dãy
    unordered_set<int> set_x(x.begin(), x.end());
    unordered_set<int> set_y(y.begin(), y.end());
    unordered_set<int> set_z(z.begin(), z.end());

    vector<int> common;

    // Duyệt qua set_x, nếu phần tử tồn tại trong cả set_y và set_z thì thêm vào kết quả
    for (int num : set_x) {
        if (set_y.count(num) && set_z.count(num)) {
            common.push_back(num);
        }
    }

    // Sắp xếp kết quả tăng dần
    sort(common.begin(), common.end());

    // In kết quả
    cout << common.size() << endl;
    for (int num : common) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
