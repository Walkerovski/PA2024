#include <bits/stdc++.h>
using namespace std;
int Counter[500000+21];

int main() {
    int n = 0, x;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        ++Counter[x];
    }
    sort(Counter + 1, Counter + n + 1, greater<int>());
    int counter = 0, i = 1;
    while (n > 0) {
        n -= Counter[i] * 2 - 1;
        ++counter;
        ++i;
    }
    cout << counter << "\n";
}