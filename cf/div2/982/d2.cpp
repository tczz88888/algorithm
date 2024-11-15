/**                           _ooOoo_
 *                           o8888888o
 *                           88" . "88
 *                           (| -_- |)
 *                            O\ = /O
 *                        ____/`---'\____
 *                      .   ' \\| |// `.
 *                       / \\||| : |||// \
 *                     / _||||| -:- |||||- \
 *                       | | \\\ - /// | |
 *                     | \_| ''\---/'' | |
 *                      \ .-\__ `-` ___/-. /
 *                   ___`. .' /--.--\ `. . __
 *                ."" '< `.___\_<|>_/___.' >'"".
 *               | | : `- \`.;`\ _ /`;.`/ - ` : | |
 *                 \ \ `-. \_ __\ /__ _/ .-` / /
 *         ======`-.____`-.___\_____/___.-`____.-'======
 *                            `=---='
 *
 *         .............................................
 *                  佛祖保佑             永无BUG
 */

                        

#include <bits/stdc++.h>
#pragma gcc optimize(2)
using namespace std;
#define ll long long
const int mod = 1e9 + 7;
const int maxn = 2e5 + 5;
int f[maxn], cnt[maxn], a[maxn], b[maxn], pre[maxn],n, m;
void solve()
{
    memset(f, 0x3f, sizeof(f));
    memset(cnt, 0, sizeof(cnt));
    f[0] = 0;
    cnt[0]=1;
    int l, r,L;
    for (int i = 1; i <= m; i++)
    {
        int sum=0;
        L=l =0;
        r = 1;
        while (r<=n)
        {
            //cout<<l<<' '<<r<<endl;
            while (l<r&&pre[r] - pre[l]>b[i]){
                sum=(sum-cnt[l]+mod)%mod;
                ++l;
            }
            if(L<l){
                L=l;
                sum=0;
            }
            while(L<r&&f[L]==f[l]){
                sum=(sum+cnt[L])%mod;
                ++L;
            }
            int v=f[l]+m-i;
            if(f[r]>v){
                f[r]=f[l]+m-i;
                cnt[r]=sum;
            }
            else if(f[r]==v){
                cnt[r]=(cnt[r]+sum)%mod;
            }
            ++r;
        }
    }
}

int main()
{
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            pre[i]=pre[i-1]+a[i];
        }
        for(int i=1;i<=m;i++){
            cin>>b[i];
        }
        solve();
        (f[n]==0x3f3f3f3f)?cout<<-1<<'\n':cout<<f[n]<<' '<<cnt[n]<<'\n';
    }
    return 0;
}