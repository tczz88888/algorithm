#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int n,square[maxn],num,mx;
unordered_map<int,int>mp;

void init(){
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>num;
        ++mp[num];
        mx=max(mx,num);
    }
    for(int i=1;i<=1e4;i++) square[i]=i*i;
}

void solve(){
    int ans=0;
    for(auto it:mp){
        int p;
        for(int i=1;i<=1e4;i++){
            p=it.first*square[i];
            if(mp.count(p)) ans+=mp[it.first]*mp[p];
            if(p>mx) break;
        }
    }
    cout<<ans-n<<endl;
}

int main(){
    init();
    solve();
    return 0;
}