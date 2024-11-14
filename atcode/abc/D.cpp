#include <bits/stdc++.h>
#pragma gcc optimize(2)
using namespace std;
#define ll long long
const int maxn = 2e5 + 5;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin>>q;
    priority_queue<ll>qu;
    ll deta=0;
    while(q--){
        int op;
        cin>>op;
        if(op==1){
            qu.push(-deta);
        }
        else if(op==2){
            ll x;
            cin>>x;
            deta+=x;
        }
        else{
            ll h;
            cin>>h;
            int ans=0;
            while(!qu.empty()&&qu.top()+deta>=h){
                ++ans;
                qu.pop();
            }
            cout<<ans<<'\n';
        }
    }
    return 0;
}