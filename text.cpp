#include <iostream>
#include <vector>
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

    // Sắp xếp ba mảng
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    sort(z.begin(), z.end());

    vector<int> common;
    int i = 0, j = 0, k = 0;

    // Duyệt ba mảng bằng ba con trỏ
    while (i < nx && j < ny && k < nz) {
        if (x[i] == y[j] && y[j] == z[k]) {
            // Tránh thêm trùng lặp
            if (common.empty() || common.back() != x[i]) {
                common.push_back(x[i]);
            }
            ++i; ++j; ++k;
        } else {
            int min_val = min({x[i], y[j], z[k]});
            if (x[i] == min_val) ++i;
            if (y[j] == min_val) ++j;
            if (z[k] == min_val) ++k;
        }
    }

    // In kết quả
    cout << common.size() << endl;
    for (int num : common) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
