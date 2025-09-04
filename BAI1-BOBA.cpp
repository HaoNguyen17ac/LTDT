#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

// hàm đếm số lần xuất hiện 
int countMaxTriplet(const string& s) 
{
    unordered_map<string, int> freq; // lưu số lần xuất hiện của từng bộ 3 
    int maxCount = 0; // biến đếm 

    for (size_t i = 0; i + 2 < s.length(); ++i) // vòng lặp duyệt qua chuỗi lấy từng bộ 3 liên tiếp
    {
        string triplet = s.substr(i, 3); // lấy chuỗi bộ 3 
        freq[triplet]++; // đếm số lần xuất hiện 
        maxCount = max(maxCount, freq[triplet]); // cập nhật biến đếm
    }

    return maxCount; // trả kết quả biến đếm lớn nhất 
}

int main() 
{
    int T;
    cin >> T; // nhập vào số lượng dãy text T
    cin.ignore(); // xoá ký tự xuống dòng 

    vector<string> inputs(T); // mảng động lưu các chuỗi 
    for (int i = 0; i < T; ++i) 
    {
        getline(cin, inputs[i]); // nhập các các chuỗi 
    }

    vector<int> results(T); // mãng động lưu kết quả đếm của các chuổi 
    for (int i = 0; i < T; ++i) 
    {
        results[i] = countMaxTriplet(inputs[i]); // gọi hàm tính kết quả 
    }

    for (int result : results) 
    {
        cout << result << endl; // in ra màn hình 
    }

    return 0;
}
