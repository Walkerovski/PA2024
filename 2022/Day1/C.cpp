#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    string input;
    cin >> input;

    int score = 0;
    bool wrong = 0;
    for(int i = 1; i <= n; ++i)
    {
        if(input[i - 1] == 'N')
            wrong = 1;
        if(i % (n / 10) == 0 && !wrong)
            ++score;
        if(i % (n / 10) == 0)
            wrong = 0;
    }
    cout << score;
}