#include <bits/stdc++.h>
using namespace std;
int A[21], B[21];

int main() {
    const int N = 18, Range = 10;
    int x = 0;

    for (int i = 0; i < N; ++i) {
        cin >> x;
        ++A[x];
        A[Range+1] += x;
    }
    for (int i = 0; i < N; ++i) {
        cin >> x;
        ++B[x];
        B[Range+1] += x;
    }
    for (int i = Range+1; i > 0; --i) {
        if(A[i] > B[i]) {
            cout << "Algosia";
            return(0);
        }
        if(A[i] < B[i]) {
            cout << "Bajtek";
            return(0);
        }
    }
    cout << "remis";
}