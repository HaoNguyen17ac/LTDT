#include <iostream>
using namespace std;

// Hàm đếm số chữ số 0 tận cùng của N!
int countTrailingZeros(long long n) 
{
    long long count = 0; // Biến đếm số chữ số 0 tận cùng
    for (long long i = 5; n / i >= 1; i *= 5) 
    {
        count += n / i; 
    }
    return count; // Trả về kết quả biến đếm
}

int main() 
{
    long long n; // Biến N!
    // Nhập nhiều dòng n 
    while (cin >> n) 
    {
        cout << countTrailingZeros(n) << endl; // In kết quả ra màn hình
    }
    return 0;
}
