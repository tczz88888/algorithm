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
const int maxn=2e5+5;
int val[maxn];

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>val[i];
        sort(val+1,val+1+n);
        int ans=0x3f3f3f3f;
        val[n+1]=0x7f7f7f7f;
        for(int i=1;i<=n-1;i++){
            int pos=n-(lower_bound(val+1,val+1+n+1,val[i]+val[i+1])-val-1);
            ans=min(ans,pos+i-1);
        }
        cout<<ans<<endl;
    }
    return 0;
}