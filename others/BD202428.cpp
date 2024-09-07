//倍增记录每个位置i往后跳2^j步到哪，然后查询的时候每次步数翻倍，如果没有超过r则将l左移到对应的位置，如果超过r则将步数减半，如果下一步无法跳远了，那么将当前位置的val累加到ans，因为字符集只有26个，所以最多只会有26次循环操作
#include <bits/stdc++.h>
#define ll long long
#pragma GCC optimize(2)
using namespace std;
const int maxn = 4e5 + 5;
// s[i][j],从i开始消去2^j次最后一个元素的idx
int st[maxn][20];
int n, q;
int val[maxn];
string s;
int pw[20];
vector<int> pos[26];


int getIdx(vector<int>&vec,int x){
    int l=0,r=vec.size();
    while(l<r){
        int mid=l+r>>1;
        if(vec[mid]<=x) l=mid+1;
        else r=mid;
    }
    return l;
}

void build_st()
{
    //cout << s << endl;
    for(int i=0;i<26;i++) pos[i].clear();
    for (int i = 0; i < n; i++)
        pos[s[i] - 'A'].push_back(i);
    // for (int i = 0; i < 26; i++)
    // {
    //     if (pos[i].size())
    //     {
    //         cout << char('A' + i) << ' ';
    //         for (auto it : pos[i])
    //             cout << it + 1 << ' ';
    //         cout << endl;
    //     }
    // }
   // cout << "***************************" << endl;
    memset(st, 0x3f3f3f, sizeof(st));
    for (int i = 0; i < n; i++)
    {
        int idx = getIdx(pos[s[i] - 'A'],i);
        if (idx < pos[s[i] - 'A'].size())
        {
            st[i][0] = pos[s[i] - 'A'][idx] + 1;
          //  cout << i + 1 << ' ' << 0 << ' ' << st[i][0] + 1 << endl;
        }
    }
    //cout << endl;
   // cout << "***************************" << endl;
    for (int i = 1; i < 16; i++)
    {
        for (int j = 0; j + pw[i] < n; j++)
        {
            if (st[j][i - 1] < n && st[st[j][i - 1]][i - 1] < n)
            {
                st[j][i] = st[st[j][i - 1]][i - 1];
               // cout << j + 1 << ' ' << i << ' ' << st[j][i] + 1 << endl;
            }
        }
    }
}

ll query(int &l, int &r)
{
    --l;
    --r;
    if (l > r)
        r += n / 2;
    int k = 0;
    ll ans = 0;
    while (l <= r)
    {
        if (k == 0 && st[l][k] > r+1)
        {
            ans += val[l];
           // cout<<"s1"<<' '<<l+1<<endl;
            l++;
            continue;
        }

        if (st[l][k] <= r+1)
        {
            l = st[l][k];
          //  cout<<"s2"<<' '<<l+1<<endl;
          if(k<16)
            ++k;
        }
        else
        {
          //  cout<<"s3"<<endl;
            --k;
        }
       // cout<<k<<endl;
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    pw[0] = 1;
    for (int i = 0; i < 16; i++)
        pw[i] = pw[i - 1] * 2;
    while (t--)
    {
        cin >> n >> q;
        cin >> s;
        for (int i = 0; i < n; i++)
        {
            cin >> val[i];
            val[i + n] = val[i];
        }
        n *= 2;
        s = s.append(s);
        build_st();
        while (q--)
        {
            int a, b, c;
            cin >> a >> b >> c;
            if (a == 1){
                val[b-1] = c;
                val[b-1+n/2]=c;
            }
            else
            {
                cout << query(b , c ) << '\n';
            }
        }
    }
    return 0;
}


