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
const int maxn = 1e4 + 5;
int p[maxn];

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        --n;
        for(int i=1;i<=n;i++) p[i]=-1;
        bool z = 0;
        int tot = 2;
        set<int> st;
        int pos;
        for(int i=2;i<=n;i++){
            cout << '?' << ' ' << 1 << ' ' << i << endl;
            int op;
            cin>>op;
            if(op==0){
                pos=i;
                break;
            }
        }
        for(int i=1;i<=pos-1;i++) p[i]=0;
        p[pos]=1;
        tot=pos+1;
        for(int i=2;i<=pos;i++) st.insert(i);
        while (tot <= n)
        {
            vector<int>v;
            v.clear();
            for (auto it : st)
            {
                cout << '?' << ' ' << it << ' ' << tot << endl;
                int q;
                cin >> q;
                v.push_back(it);
                if (q == 0)
                {
                    p[tot] = it;
                    st.insert(tot);
                    ++tot;
                    for(auto s:v) st.erase(s);
                    break;
                }
            }
        }
        cout << '!';
        for (int i = 1; i <= n; i++)
        {
            cout << ' ' << p[i];
        }
        cout << endl;
    }
    return 0;
}