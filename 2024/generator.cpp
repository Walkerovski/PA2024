#include <bits/stdc++.h>
using namespace std;
vector <int> V;

int main() {
    int n;
    n = rand() % 30000 + 2;
    cout << n << "\n";
    int m;
    m = n - 1;
    cout << m << "\n";
    int a, b;
    for (int i = 1; i <= n; ++i) {
        V.push_back(i);
    }

    random_device rd;
    mt19937 g(rd());

    shuffle(V.begin(), V.end(), g);

    for (int i = 0; i < V.size() - 1; ++i) {
        cout << V[i] << " " << V[i+1] << "\n";
    }

    cout << m << "\n";
    shuffle(V.begin(), V.end(), g);

    for (int i = 0; i < V.size() - 1; ++i) {
        cout << V[i] << " " << V[i+1] << "\n";
    }
}