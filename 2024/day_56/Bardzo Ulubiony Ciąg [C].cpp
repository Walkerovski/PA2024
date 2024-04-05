#include<bits/stdc++.h>
using namespace std;
vector <long long> RawInput, Input, RInput;
const int inf = 35000000;
int Tab1[2*inf], Tab2[2*inf];

int main() {
    int n;
    cin >> n;

    int x;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        RawInput.push_back(x);
        if(!Input.empty())
            Input.push_back(Input.back() + x);
        else
            Input.push_back(x);
    }

    for (int i = RawInput.size() - 1; i >= 0; --i)
        if(!RInput.empty())
            RInput.push_back(RInput.back() + RawInput[i]);
        else
            RInput.push_back(RawInput[i]);

    int answer = 0;
    for (int i2 = 0; i2 < n; ++i2)
        for (int i1 = 0 ; i1 <= i2; ++i1)
            for (int j2 = i2 + 1; j2 < n; ++j2)
                ++Tab2[RInput[i2] - RInput[i1] + RInput[j2] + inf];

    for (int i2 = 0; i2 < n; ++i2) {
        for (int i1 = 0 ; i1 <= i2; ++i1) {
            for (int j2 = i2; j2 < n; ++j2) {
                ++Tab1[Input[i2] - Input[i1] + Input[j2] + inf];
                --Tab2[RInput[i2] - RInput[i1] + RInput[j2] + inf];

                if(j2 != i2) {
                    answer += Tab1[Input[i2] - Input[i1] + Input[j2] + inf] * Tab2[-Input[i2] + Input[i1] - Input[j2] + inf];
                }
                else {
                    if (Tab1[Input[i2] - Input[i1] + Input[j2] + inf] * Tab2[-Input[i2] + Input[i1] - Input[j2] + inf] > 0)
                        answer += Tab1[Input[i2] - Input[i1] + Input[j2] + inf] * Tab2[-Input[i2] + Input[i1] - Input[j2] + inf] - 1;
                }
            }
        }
    }
    cout << answer << "\n";
} 