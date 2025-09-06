#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Hàm tạo danh sách các số nguyên tố ≤ 1000 
vector<int> generatePrimes(int maxN) 
{
    vector<bool> isPrime(maxN + 1, true); // Mảng động lưu số nguyên tố 
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= maxN; ++i) // Hàm loại bỏ bội số số nguyên tố 
    {
        if (isPrime[i]) 
        {
            for (int j = i * i; j <= maxN; j += i)
                isPrime[j] = false;
        }
    }
    vector<int> primes; // Lưu các số nguyên tố vào mảng động 
    for (int i = 2; i <= maxN; ++i) 
    {
        if (isPrime[i])
            primes.push_back(i);
    }
    return primes; // Trả danh sách các số nguyên tố 
}

// Hàm tính số lần xuất hiện của mỗi số nguyên tố trong N!
vector<int> factorialPrimeExponents(int N, const vector<int>& primes) 
{
    vector<int> exponents; // Mảng động lưu số lần xuất hiện của các số nguyên tố 
    for (int p : primes) // Mỗi số nguyên tố p tính số lần xuất hiện trong N!
    {
        int count = 0; // Biến đếm tổng số lần xuất hiện của số nguyên tố
        int power = p; // Biến tính giá trị của các số nguyên tố 
        while (power <= N) 
        {
            count += N / power; // count += N / p^k với k = 1,2,3,...
            power *= p;
        }
        exponents.push_back(count); // Lưu kết quả vào mảng 
    }
    // Loại bỏ các số 0 ở cuối dãy
    while (!exponents.empty() && exponents.back() == 0)
        exponents.pop_back();
    return exponents; // Trả về dãy số lần xuất hiện
}

int main() 
{
    vector<int> primes = generatePrimes(1000); // Mảng động danh sách số nguyên tố ≤ 1000
    int N; // Biến N!
    while (cin >> N) // Nhập nhiều dòng N!
    {
        vector<int> result = factorialPrimeExponents(N, primes); // Tính số lần xuất hiện các số nguyên tố trong N!
        for (int i = 0; i < result.size(); ++i) {
            cout << result[i]; // In kết quả
            if (i < result.size() - 1)
                cout << " ";
        }
        cout << endl;
    }
    return 0;
}
