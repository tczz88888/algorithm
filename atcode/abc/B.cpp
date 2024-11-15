#include <bits/stdc++.h>
#pragma gcc optimize(2)
using namespace std;
#define ll long long

int main()
{
    int n, m, ans = 0;
    cin >> n >> m;
    string s;
    cin >> s;
    for (int i = m - 1; i < n; i++)
    {
        bool ok = 1;
        for (int j = i - m + 1; j <= i; j++)
        {
            if (s[j] == 'X')
            {
                ok = 0;
                break;
            }
        }
        if (ok)
        {
            ++ans;
            for (int j = i - m + 1; j <= i; j++)
            {
                s[j]='X';
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}