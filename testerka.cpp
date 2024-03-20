#include <bits/stdc++.h>
using namespace std;
set < int > Neighbourhood[30000+21];
vector <string> V;

int main() {
    int n;
    cin >> n;
    int m;
    cin >> m;
    int a, b;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        Neighbourhood[a].insert(b);
        Neighbourhood[b].insert(a);
    }
    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
    }
    cin >> m;
    char znak;
    for (int i = 0; i < m; ++i) {
        cin >> znak >> a >> b;
        bool flag = 0;
        if (znak == '-') {
            for (auto cel:Neighbourhood[a]) {
                if (cel == b) {
                    flag = 1;
                    break;
                }
            }
            if (!flag) {
                cout << "Nieistniejace polaczenie!\n" << znak << " " << a << " " << b << "\n";
                return -1;
            }
            flag = 0;
            for (auto pośrednik:Neighbourhood[a]) {
                if (Neighbourhood[pośrednik].find(b) != Neighbourhood[pośrednik].end()) {
                    flag = 1;
                    break;
                }
            }
            if (!flag) {
                cout << "Brak pośrednika!\n" << znak << " " << a << " " << b << "\n";
                return -1;
            }
            Neighbourhood[a].erase(b);
            Neighbourhood[b].erase(a);
        }
        else {
            for (auto pośrednik:Neighbourhood[a]) {
                if (Neighbourhood[pośrednik].find(b) != Neighbourhood[pośrednik].end()) {
                    flag = 1;
                    break;
                }
            }
            if (!flag) {
                cout << "Brak pośrednika!\n" << znak << " " << a << " " << b << "\n";
                return -1;
            }
            Neighbourhood[a].insert(b);
            Neighbourhood[b].insert(a);
        }
    }
    return 0;
}