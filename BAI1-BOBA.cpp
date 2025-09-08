#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Hàm đếm số lần xuất hiện của bộ ba xuất hiện nhiều nhất
int countMaxTriplet(const string& s) 
{
    vector<string> triplets; // Lưu các bộ ba đã gặp
    vector<int> counts; // Lưu số lần xuất hiện tương ứng
    int maxCount = 0; // Biến đếm số lần xuất hiện lớn nhất

    for (size_t i = 0; i + 2 < s.length(); ++i) 
    {
        string triplet = s.substr(i, 3); // Lấy bộ ba hiện tại
        bool found = false; // Biến kiểm tra bộ ba đã gặp

        for (size_t j = 0; j < triplets.size(); ++j) 
        {
            if (triplets[j] == triplet) // 
            {
                counts[j]++; // Tăng số lần xuất hiện của bộ bà trừng lặp 
                maxCount = max(maxCount, counts[j]); // Cập nhật số lần xuất hiện lớn nhất
                found = true;
                break;
            }
        }

        if (!found) // Nếu chưa gặp bộ ba, thêm bộ ba mới vào danh sách
        {
            triplets.push_back(triplet); //
            counts.push_back(1);
            maxCount = max(maxCount, 1); // Cập nhật số lần xuất hiện lớn nhất
        }
    }

    return maxCount; // Trả về số lần xuất hiện lớn nhất của bộ ba
}

int main() 
{
    int T; // Biến số lượng bộ test T
    cin >> T; // Nhập số lượng bộ test T
    cin.ignore(); // Loại bỏ ký tự xuống dòng 
 
    vector<string> inputs(T); // Mãng động lưu các chuỗi đầu vào
    for (int i = 0; i < T; ++i) 
    {
        getline(cin, inputs[i]); // Nhập từng chuỗi đầu vào
    }

    for (int i = 0; i < T; ++i) 
    {
        cout << countMaxTriplet(inputs[i]) << endl; // In kết quả cho từng chuỗi đầu vào
    }

    return 0;
}
