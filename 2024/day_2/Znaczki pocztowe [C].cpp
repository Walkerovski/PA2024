#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a;
    map < int, int > mapa;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        ++mapa[a];
    }
    vector < pair < int, int > > V;
    for (auto it:mapa)
        V.push_back({it.second, it.first});
    sort(V.begin(), V.end(), greater<pair<int,int>>());
    for (int i = 1; i <= n; ++i) {
        int sum = 0;
        for (auto it:V) {
            sum += it.first / i * i;
            if (it.first / i == 0)
                break;
        }
        cout << sum << " ";
    }
}