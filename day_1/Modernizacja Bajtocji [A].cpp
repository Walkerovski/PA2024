#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    scanf("%d%d", &n, &q);
    char action;
    vector < pair < set < int >, bool > > V;
    for (int stage = 0; stage < q; ++stage) {
        scanf(" %c", &action);
        if (action == '+') {
            int a, b;
            scanf("%d%d", &a, &b);
            int indexa = -1, indexb = -1;
            for (int i = 0; i < V.size(); ++i) {
                if (V[i].first.find(a) != V[i].first.end())
                    indexa = i;
                if (V[i].first.find(b) != V[i].first.end())
                    indexb = i;
            }
            if (indexa == -1 && indexb == -1) {
                set <int> new_graph;
                new_graph.insert(a);
                new_graph.insert(b);
                if (a != b)
                    V.push_back({new_graph, false});
                else
                    V.push_back({new_graph, true});
            }
            else if (indexa == -1 || indexb == -1) {
                if (indexa == -1)
                    V[indexb].first.insert(a);
                else
                    V[indexa].first.insert(b);
            }
            else {
                if (indexa == indexb) {
                    V[indexa].second = true;
                    V[indexa].first.insert(a);
                    V[indexa].first.insert(b);
                }
                else {
                    if (V[indexa].first.size() > V[indexb].first.size())
                        swap(indexa, indexb);
                    for(auto it:V[indexa].first) {
                        V[indexb].first.insert(it);
                    }
                    if (V[indexa].second)
                        V[indexb].second = true;
                    V.erase(V.begin() + indexa);
                }
            }
        }
        else if (action == '-') {
            int a;
            scanf("%d", &a);
            for (int i = 0; i < V.size(); ++i) {
                if (V[i].first.find(a) != V[i].first.end()) {
                    V[i].first.erase(a);
                    if(V[i].first.size() <= 1 && !V[i].second) {
                        V.erase(V.begin() + i);
                    }
                }
            }
        }
        else {
            int a;
            scanf("%d", &a);
            bool flag = false;
            for (auto it:V) {
                if (it.first.find(a) != it.first.end()) {
                    if (it.second) {
                        printf("%d", 1);
                        flag = true;
                        break;
                    }
                    else {
                        printf("?");
                        flag = true;
                        break;
                    }
                }
            }
            if (!flag)
                printf("%d", 0);
        }
    }
    cout << "\n";
}