#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;

    int a[n+21], b[n+21];
    for(int i = 0; i < n; ++i)
    {
        cin >> a[i];
        b[i] = a[i];
    }
    
    int score1 = 0;
    for(int i = 0; i < n - 1; ++i)
    {
        if(i % 2)
        {
            if(a[i + 1] >= a[i])
            {
                a[i + 1] = -2e9;
                ++score1;
            }
        }
        else
            if(a[i + 1] <= a[i])
            {
                a[i + 1] = 2e9;
                ++score1;
            }
    }
    int score2 = 0;
    for(int i = 0; i < n - 1; ++i)
    {
        if(!(i % 2))
        {
            if(b[i + 1] >= b[i])
            {
                b[i + 1] = -2e9;
                ++score2;
            }
        }
        else
            if(b[i + 1] <= b[i])
            {
                b[i + 1] = 2e9;
                ++score2;
            }
    }
    cout << min(score1, score2);
}