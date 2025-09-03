#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

int countMaxTriplet(const string& s) {
    unordered_map<string, int> freq;
    int maxCount = 0;

    for (size_t i = 0; i + 2 < s.length(); ++i) {
        string triplet = s.substr(i, 3);
        freq[triplet]++;
        maxCount = max(maxCount, freq[triplet]);
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

    vector<int> results(T);
    for (int i = 0; i < T; ++i) {
        results[i] = countMaxTriplet(inputs[i]);
    }

    for (int result : results) {
        cout << result << endl;
    }

    return 0;
}
