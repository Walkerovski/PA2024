#include<bits/stdc++.h>
using namespace std;
vector< pair<int,int> >V;
bool Nodes[35+21];
int Answer[35+21];

int main() {
    int n, m;
    cin >> n >> m;
    int a, b;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        V.push_back({a - 1, b - 1});
    }
    for (long long i = 1; i < (1UL<<n); ++i) {
        long long mask = i;
        int exp = 0;
        for (int j = n; j >= 0; --j) {
            if (mask / (1UL << j) > 0) {
                mask -= (1UL << j);
                Nodes[j] = true;
                ++exp;
            }
            else
                Nodes[j] = false;
        }
        for(auto it:V) {
            if(Nodes[it.first] && !Nodes[it.second]) {
                swap(Nodes[it.first], Nodes[it.second]);
            }
        }
        int counter = 0;
        if(Nodes[0])
            ++counter;
        for(int j = 1; j < n; ++j) {
            if(Nodes[j] != Nodes[j-1] && counter > 0)
                break;
            if(Nodes[j])
                ++counter;
        }
        if (counter == exp)
            ++Answer[exp];
    }
    for (int i = 1; i <= n; ++i)
        cout << Answer[i] % 2 << " ";
    cout << "\n";
}