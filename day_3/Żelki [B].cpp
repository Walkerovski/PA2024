#include<bits/stdc++.h>
using namespace std;

long long BackpackPrevious[7000+21];
long long Backpack[7000+21];

vector <long long> V[7000+21];
set <int> colors;
int main() {
    int n, k, m;
    cin >> n >> k >> m;
    for (int i = 0; i < n; ++i) {
        long long color, mas, price;
        cin >> color >> mas >> price;
        V[i].push_back(color);
        V[i].push_back(mas);
        V[i].push_back(price);
        colors.insert(color);
    }
    if (colors.size() != k) {
        cout << 0 << "\n";
        for (int i = 1; i < m; ++i)
            cout << -1 << "\n";
        return 0;
    }
    sort(V, V + n);
    for (int i = 0; i < m; ++i) {
        BackpackPrevious[i] = 1e18;
        Backpack[i] = 1e18;
    }
    BackpackPrevious[0] = 0;
    Backpack[V[0][1]%m] = V[0][2];
    Backpack[0] = 1e18;
    for (int i = 1; i < n; ++i) {
        if (V[i][0] != V[i-1][0]) {
            for (int j = 0; j < m; ++j) {
                BackpackPrevious[j] = Backpack[j];
                Backpack[j] = 1e18;
            }
        }
        for (int j = 0; j < m; ++j) {
            if (BackpackPrevious[(j - V[i][1] + m) % m] != 1e18) {
                Backpack[j] = min(Backpack[j], BackpackPrevious[(j - V[i][1] + m) % m] + V[i][2]);
            }
        }
    }

    vector<pair<int, long long> > X;
    for (int j = 1; j < m; ++j) {
        if(Backpack[j] != 1e18) {
            X.push_back({j, Backpack[j]});
        }
        Backpack[j] = 1e18;
    }
    Backpack[0] = 0;
    
    for (auto it:X)
        for (int i = 0; i < m; ++i)
            Backpack[(it.first * i) % m] = min(Backpack[(it.first * i) % m], it.second * i);

    vector<pair<int, long long> > Y;
    for (int j = 1; j < m; ++j) {
        if(Backpack[j] != 1e18) {
            Y.push_back({j, Backpack[j]});
        }
        Backpack[j] = 1e18;
    }
    Backpack[0] = 0;

    for (auto it:Y)
        for (int i = 0; i < m; ++i)
            if (Backpack[i] != 1e18)
                Backpack[(i + it.first) % m] = min(Backpack[(i + it.first) % m], Backpack[i] + it.second);

    for (int i = 0; i < m; ++i)
        if (Backpack[i] != 1e18)
            cout << Backpack[i] << "\n";
        else
            cout << -1 << "\n";
}