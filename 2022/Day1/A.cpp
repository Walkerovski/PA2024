#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, q;
    cin >> n >> q;

    string S;
    cin >> S;
    
    int a;
    char c;
    for(int i = 0; i < q; ++i)
    {
        cin >> a >> c;
    }

    int score, counter = 0;
    for(auto& it: S)
    {
        if(it == 'N')
            ++counter;
    }
    int bitmask[20];
    for(int i = 0; i < (1 << counter); ++i)
    {
        for(int j = 0; j < counter; ++j)
        {
            if(!bitmask[j])
            {
                bitmask[j] = 1;
                break;
            }
            else
                bitmask[j] = 0;
        }
        int k = 0;
        string Scopy, Scopy2;
        for(auto& it: S)
        {
            if(it == 'N')
            {
                Scopy += '0' + bitmask[k];
                ++k;
            }
            else if (it == 'Z')
                Scopy += '1';
            else
                Scopy += '0';
        }
        cout << "\n" << Scopy << "\n";
        while(Scopy.size() > 1)
        {
            Scopy2 += Scopy[0];
            bool changed = 0;
            for(int j = 1; j < Scopy.size(); ++j)
            {
                if(!changed && Scopy[j] == Scopy2[j-1])
                {
                    if(Scopy[j] == '0')
                        Scopy2[j - 1] = '1';
                    else
                        Scopy2[j - 1] = '0';
                    changed = 1;
                    continue;
                }
                Scopy2 += Scopy[j];
            }
            if(!changed)
                break;
            Scopy = Scopy2;
            Scopy2 = "";
        }
        cout << Scopy << "\n";
    }
}