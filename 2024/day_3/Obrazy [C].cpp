#include <bits/stdc++.h>
using namespace std;
long long T[30+21];
long long n;
long long counter = 0;

void fill(long long h, long long w) {
    for (int i = n; i > 0; --i) {
        if (h / T[i] > 0 && w / T[i] > 0) {
            counter += (h / T[i]) * (w / T[i]);
            fill(h - (h / T[i]) * T[i], w - (w / T[i]) * T[i]);
            fill(h - (h / T[i]) * T[i], (w / T[i]) * T[i]);
            fill((h / T[i]) * T[i], w - (w / T[i]) * T[i]);
            return;
        }
    }
}

int main() {
    long long h, w;
    cin >> h >> w;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> T[i];
    }
    if (h % T[1]) {
        cout << -1;
        return 0;
    }
    if (w % T[1]) {
        cout << -1;
        return 0;
    }
    fill(h, w);
    cout << counter;
}