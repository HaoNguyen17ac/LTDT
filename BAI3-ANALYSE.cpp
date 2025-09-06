#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Hàm tạo danh sách các số nguyên tố ≤ 1000 
vector<int> generatePrimes(int maxN) {
    vector<bool> isPrime(maxN + 1, true); // Mảng động lưu số nguyên tố 
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= maxN; ++i) // Hàm loại bỏ bội số số nguyên tố 
    {
        if (isPrime[i]) {
            for (int j = i * i; j <= maxN; j += i)
                isPrime[j] = false;
        }
    }
    vector<int> primes; // Lưu các 
    for (int i = 2; i <= maxN; ++i) {
        if (isPrime[i])
            primes.push_back(i);
    }
    return primes;
}

// Hàm tính số lần xuất hiện của mỗi số nguyên tố trong N!
vector<int> factorialPrimeExponents(int N, const vector<int>& primes) {
    vector<int> exponents;
    for (int p : primes) {
        int count = 0;
        int power = p;
        while (power <= N) {
            count += N / power;
            power *= p;
        }
        exponents.push_back(count);
    }
    // Loại bỏ các số 0 ở cuối dãy
    while (!exponents.empty() && exponents.back() == 0)
        exponents.pop_back();
    return exponents;
}

int main() {
    vector<int> primes = generatePrimes(1000);
    int N;
    while (cin >> N) {
        vector<int> result = factorialPrimeExponents(N, primes);
        for (int i = 0; i < result.size(); ++i) {
            cout << result[i];
            if (i < result.size() - 1)
                cout << " ";
        }
        cout << endl;
    }
    return 0;
}
