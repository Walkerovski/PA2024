#include <bits/stdc++.h>
using namespace std;
set < int > Neighbourhood[30000+21];
set < int > Answer[30000+21];
vector <string> V;

bool Visited[30000+21];
vector <int> Sequence;

void dfs(int vertex) {
    Sequence.push_back(vertex);
    Visited[vertex] = true;
    for (auto it:Neighbourhood[vertex]) {
        if (!Visited[it]) {
            dfs(it);
        }
    }
}

void dfsA(int vertex) {
    Visited[vertex] = true;
    for (auto it:Answer[vertex]) {
        if (!Visited[it]) {
            dfsA(it);
        }
    }
    Sequence.push_back(vertex);
}

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
    dfs(1);
    for (int it = 1; it < Sequence.size(); ++it) {
        if (Neighbourhood[1].find(Sequence[it]) == Neighbourhood[1].end()){
            Neighbourhood[1].insert(Sequence[it]);
            Neighbourhood[Sequence[it]].insert(1);
            string s = "+ " + to_string(1) + " " + to_string(Sequence[it]) + "\n";
            V.push_back(s);
        }
    }
    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        Answer[a].insert(b);
        Answer[b].insert(a);
        if (Neighbourhood[a].find(b) == Neighbourhood[a].end()) {
            Neighbourhood[a].insert(b);
            Neighbourhood[b].insert(a);
            string s = "+ " + to_string(a) + " " + to_string(b) + "\n";
            V.push_back(s);
        }
    }
    for (int i = Sequence.size() - 1; i >= 1; --i) {
        vector < pair < int, int > > vec;
        for (auto it:Neighbourhood[Sequence[i]]) {
            if (Answer[Sequence[i]].find(it) == Answer[Sequence[i]].end() && it != 1) {
                vec.push_back({it, Sequence[i]});
                string s = "- " + to_string(it) + " " + to_string(Sequence[i]) + "\n";
                V.push_back(s);
            }
        }
        for (auto it:vec) {
            Neighbourhood[it.first].erase(it.second);
        }
    }
    for (int i = 1; i <= n; ++i) {
        Visited[i] = false;
    }
    Sequence.clear();
    dfsA(1);
    for (auto it:Sequence) {
        if (Answer[1].find(it) == Answer[1].end()) {
            if (it == 1) {
                continue;
            }
            string s = "- " + to_string(it) + " " + to_string(1) + "\n";
            V.push_back(s);
        }
    }
    cout << V.size() << "\n";
    for (auto it:V) {
        cout << it;
    }
}