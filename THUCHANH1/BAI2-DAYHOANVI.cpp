#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int main() 
{
    int N; // biến số lượng số tự nhiên N
    string line; // biến dòng nhập 

    // nhập số lượng phần tử
    getline(cin, line);
    stringstream ssN(line);
    ssN >> N;

    // nhập dãy số trên một dòng
    getline(cin, line); 
    stringstream ss(line);

    vector<int> A; // mãng động lưu các số nguyên
    int temp;
    while (ss >> temp) 
    {
        A.push_back(temp);
    }

    // kiểm tra số lượng phần tử 
    if (A.size() < N) 
    {
        cout << "NO - số lượng phần tử bị thiếu" << endl; // in ra màn hình NO nếu số lượng phần tử nhập nhỏ hơn N
        return 0;
    }
    if (A.size() > N) 
    {
        cout << "NO - số lượng phần tử vượt mức cho phép" << endl; // in ra màn hình NO nếu số lượng phần tử nhập lớn hơn N
        return 0;
    }

    // kiểm tra hoán vị
    vector<bool> appeared(N + 1, false);
    for (int i = 0; i < N; ++i) 
    {
        if (A[i] < 1 || A[i] > N || appeared[A[i]]) 
        {
            cout << "NO" << endl;
            return 0;
        }
        appeared[A[i]] = true;
    }

    cout << "YES" << endl;
    return 0;
}
