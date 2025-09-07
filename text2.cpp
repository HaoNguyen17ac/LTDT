#include <iostream>
using namespace std;

// Hàm đếm số chữ số 0 tận cùng của N!
int countTrailingZeros(long long n) {
    long long count = 0;
    for (long long i = 5; n / i >= 1; i *= 5) {
        count += n / i;
    }
    return count;
}

int main() {
    long long n;
    // Nhập nhiều dòng n 
    while (cin >> n) {
        cout << countTrailingZeros(n) << endl;
    }
    return 0;
}
