#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() 
{
    int nx, ny, nz; // Biễn kích thước 3 dãy x,y,z
    cin >> nx; // Nhập kích thước dãy x
    vector<int> x(nx); // Mãng động dãy x
    for (int i = 0; i < nx; ++i) cin >> x[i];

    cin >> ny; // Nhập kích thước dãy y
    vector<int> y(ny); // Mãng động dãy y
    for (int i = 0; i < ny; ++i) cin >> y[i]; 

    cin >> nz; // Nhập kích thước dãy z
    vector<int> z(nz); // Mãng động dãy z
    for (int i = 0; i < nz; ++i) cin >> z[i];

    // Sắp xếp ba mảng
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    sort(z.begin(), z.end());

    vector<int> common; // Mãng động lưu các phần tử chung
    int i = 0, j = 0, k = 0; // Ba con trỏ duyệt ba dãy x,y,z

    // Duyệt ba mảng bằng ba con trỏ
    while (i < nx && j < ny && k < nz) 
	{
        if (x[i] == y[j] && y[j] == z[k]) // Tìm phần tử chung
		{
            // Tránh thêm trùng lặp
            if (common.empty() || common.back() != x[i]) 
			{
                common.push_back(x[i]);
            }
            ++i; ++j; ++k; // Tăng giá trị ba con trỏ
        } else 
		{
            int min_val = min({x[i], y[j], z[k]});	// Tìm giá trị nhỏ nhất trong ba con trỏ
            if (x[i] == min_val) ++i;
            if (y[j] == min_val) ++j;
            if (z[k] == min_val) ++k;
        }
    }

    // In kết quả ra màn hình 
    cout << common.size() << endl;
    for (int num : common) 
	{
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
