#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N; // Nhập số lượng phần tử cần có

    vector<int> A; // Khai báo mảng chứa dãy số
    int temp;
    int count = 0;

    // Đọc từng số và kiểm tra số lượng
    while (cin >> temp) {
        A.push_back(temp);
        count++;
        if (count > N) {
            cout << "NO - số lượng phần tử vượt mức cho phép" << endl;
            return 0;
        }
        else if (count < N) {
        cout << "NO - số lượng phần tử bị thiếu" << endl;
        return 0;
        }
    }


    vector<bool> appeared(N + 1, false); // Mảng đánh dấu từ 1 đến N

    for (int i = 0; i < N; ++i) {
        if (A[i] < 1 || A[i] > N || appeared[A[i]]) {
            cout << "NO" << endl;
            return 0;
        }
        appeared[A[i]] = true;
    }

    cout << "YES" << endl;
    return 0;
}
