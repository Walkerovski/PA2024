#include <bits/stdc++.h>
using namespace std;
int x, counter;
bool visited[3007];

vector<pair<int, int>> v;
vector<int> reversed[3007];
vector<int> normal[3007];

void find_path(int x, int y)
{
    if (x == y)
        return;
    if (visited[v[x].second] == 0 && visited[v[y].second] == 0)
    {
        int temp, temp2;
        for (int i = 0; i < v.size(); ++i)
            if (v[i].second == x)
                temp = i;
        for (int i = 0; i < v.size(); ++i)
            if (v[y].second == i)
                temp2 = i;
        normal[counter].push_back(v[x].second);
        reversed[counter].push_back(v[y].second);
        swap(v[x].second, v[y].second);
        visited[v[x].second] = 1;
        visited[v[y].second] = 1;
        find_path(temp, temp2);
    }
}

int main()
{
    int n;
    cin >> n;
    int a;
    for (int i = 0; i < n; ++i)
    {
        cin >> a;
        v.push_back({a, i});
    }
    sort(v.begin(), v.end());
    while (true)
    {
        ++counter;
        bool flag = 0;
        for (int i = 0; i < v.size(); ++i)
        {
            if (v[i].second != i)
                flag = 1;
            if (v[i].second != i)
                if (visited[v[i].second] == 0)
                    find_path(i, v[i].second);
        }
        if(!flag)
            break;
        for (int i = 0; i <= 3001; ++i)
            visited[i] = 0;
    }
    cout << counter - 1 << endl;
    for (int i = 1; i <= counter - 1; ++i)
    {
        cout << reversed[i].size() * 2 << endl;
        for (int j = 0; j < normal[i].size(); ++j)
            cout << normal[i][j] + 1 << " ";
        for (int j = reversed[i].size() - 1; j >= 0; --j)
            cout << reversed[i][j] + 1 << " ";
        cout << endl;
    }
}