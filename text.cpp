#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N; // Nhập số lượng phần tử

    vector<int> A(N); // Khai báo mảng chứa dãy số
    vector<bool> appeared(N + 1, false); // Mảng đánh dấu từ 1 đến N

    for (int i = 0; i < N; ++i) {
        cin >> A[i]; // Nhập từng phần tử

        // Kiểm tra điều kiện hoán vị
        if (A[i] < 1 || A[i] > N || appeared[A[i]]) {
            cout << "NO" << endl;
            return 0;
        }
        appeared[A[i]] = true; // Đánh dấu số đã xuất hiện
    }

    cout << "YES" << endl; // Nếu không có lỗi, là hoán vị
    return 0;
}
