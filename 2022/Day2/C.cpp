#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int counter = 0;
    int string[1000000];
    for(int i = 0; i < 1000000; ++i)
        string[i] = 0;
    for(int i = 1; i < 1000000; ++i)
    {
        for(int k = i; k != 0; k /= 2)
            if (k % 2 == 1)
                ++string[i];
        counter += string[i];
        if(counter > 1000007)
            break;
    }
    int k = 1;
    int size = 0;
    while(true)
    {
        n -= string[k];
        if(n == 1 && string[k + 1] == string[k] + 1)
        {
            string[k] = -1;
            ++k;
            size = k - 1;
            break;
        }
        else if(n == 2 && string[k + 2] == string[k] + 2)
        {
            string[k] = -1;
            string[k + 1] = -1;
            k += 2;
            size = k - 2;
            break;
        }
        else if(n == 0)
            break;
        else if(n < 0)
        {
            for(int i = k; i > 0; --i)
            {
                if(string[i] == abs(n))
                {
                    string[i] = -1;
                    n += string[i];
                    size = k - 1;
                    break;
                }
            }
            break;
        }
        ++k;
    }
    if(k > size && size > 0)
        cout << size << "\n";
    else
        cout << k << "\n";

    for(k; k > 0; --k)
        if(string[k] > 0)
            cout << k << " ";
}