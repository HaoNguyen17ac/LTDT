#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Hàm đếm số lần xuất hiện của bộ ba xuất hiện nhiều nhất
int countMaxTriplet(const string& s) {
    vector<string> triplets; // Lưu các bộ ba đã gặp
    vector<int> counts;           // Lưu số lần xuất hiện tương ứng
    int maxCount = 0;           // Biến đếm số lần xuất hiện lớn nhất

    for (size_t i = 0; i + 2 < s.length(); ++i) {
        string triplet = s.substr(i, 3);
        bool found = false;

        for (size_t j = 0; j < triplets.size(); ++j) {
            if (triplets[j] == triplet) {
                counts[j]++;
                maxCount = max(maxCount, counts[j]);
                found = true;
                break;
            }
        }

        if (!found) {
            triplets.push_back(triplet);
            counts.push_back(1);
            maxCount = max(maxCount, 1);
        }
    }

    return maxCount;
}

int main() {
    int T;
    cin >> T;
    cin.ignore();

    vector<string> inputs(T);
    for (int i = 0; i < T; ++i) {
        getline(cin, inputs[i]);
    }

    for (int i = 0; i < T; ++i) {
        cout << countMaxTriplet(inputs[i]) << endl;
    }

    return 0;
}
