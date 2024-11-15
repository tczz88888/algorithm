#include <bits/stdc++.h>
#pragma gcc optimize(2)
using namespace std;
const int maxn = 2e5 + 5;
#define ll long long
int n, m;
int pos[maxn];
int val[maxn];
ll sum;
map<int, int> mp;
int main()
{
    cin >> n >> m;
    sum = 0;
    for (int i = 1; i <= m; i++)
        cin >> pos[i];
    for (int i = 1; i <= m; i++)
    {
        cin >> val[i];
        sum += val[i];
        mp[pos[i]] = val[i];
    }
    mp[n] += 0;
    if (sum != n || (*mp.begin()).first != 1)
    {
        cout << -1 << endl;
    }
    else
    {
        bool ok = 1;
        int res = 0;
        int last = -1;
        ll ans = 0;
        for (auto it = mp.begin(); it != mp.end(); it++)
        {
           // cout << last << ' ' << res << endl;
            if (last == -1)
            {
                res = (*it).second;
            }
            else
            {
                if (res >= (*it).first - last)
                {
                    ans += 1ll * ((*it).first - last) * ((*it).first - last - 1) / 2;
                    ans += 1ll * ((*it).first - last) * (res - ((*it).first - last));
                    res -= ((*it).first - last);
                    res += (*it).second;
                }
                else
                {
                    ok = 0;
                    break;
                }
            }
            last = (*it).first;
        }
        if (ok)
            cout << ans << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}