#include<bits/stdc++.h>
using namespace std;
int sum[2000*2+21][26+21];
int n, m;
vector< pair<int,int> >Answer;

void divide(int side, int color) {
    sum[side][27] = 0;
    if (side < 2000) {
        for(int i = 0; i < m; ++i)
            if(sum[i+2000][27] != 0) {
                --sum[i+2000][color];
                --sum[i+2000][27];
            }
    }
    else
        for(int i = 0; i < n; ++i)
            if(sum[i][27] != 0) {
                --sum[i][color];
                --sum[i][27];
            }

    // cout << side + 1<< " "<<color<<"\n";
    // cout << sum[0][27] << " " << sum[0][0]<<"ASDA\n";

    for(int i = 0; i < m; ++i)
        for(int color = 0; color < 27; ++color)
            if (sum[i+2000][27]!=0 && sum[i+2000][color] == sum[i+2000][27])
                divide(i+2000, color);

    for(int i = 0; i < n; ++i)
        for(int color = 0; color < 27; ++color)
            if (sum[i][27]!=0 && sum[i][color] == sum[i][27])
                divide(i, color);

    Answer.push_back({side, color});
}

int main() {
    cin >> n >> m;
    char x;
    pair <int, int> start;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            cin >> x;
            x = (int)x - (int)'A';
            ++sum[i][x];
            ++sum[j+2000][x];
            if(sum[i][x] == m)
                start={i, x};
            if(sum[j+2000][x] == n)
                start={j+2000, x};
            sum[i][27] = m;
            sum[j+2000][27] = n;
        }
    divide(start.first, start.second);
    cout << Answer.size() << "\n";
    for(auto it: Answer) {
        if(it.first < 2000)
            cout << "R " << it.first + 1 << " " << (char)(it.second + 'A') << "\n";
        else
            cout << "K " << it.first + 1 - 2000 << " " << (char)(it.second + 'A') << "\n";
    }
}