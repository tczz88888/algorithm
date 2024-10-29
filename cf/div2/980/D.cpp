/*
最短路，设d[i]是从起点开始到达i题的最小花费，跳过i题就会有val[i]的花费，那么可以建一个有向图，对点i
可以建一条到i-1的边，这时提交了i题，所以没有花费，边权为0，再建一条i到e[i],边权为val[i]的边，表示跳过i
题，跑以1为起点的最短路就行了
*/
#include<bits/stdc++.h>
#pragma gcc optimize(2)
using namespace std;
#define ll long long
const int maxn=4e5+5;
const ll inf=2e18+5;
ll d[maxn],sum[maxn];
int val[maxn],e[maxn];
int n;
vector<pair<int,int>>g[maxn];
struct node{
    int u;
    ll d;
    bool  operator < (const node &p)const{
        return d>p.d;
    }
};

void dj(int s){
    for(int i=1;i<=n;i++) d[i]=inf;
    priority_queue<node>q;
    q.push({s,0});
    d[s]=0;
    while(!q.empty()){
        node p=q.top();
        q.pop();
        int u=p.u;
        if(d[u]!=p.d) continue;
        for(auto [v,w]:g[u]){
            if(d[u]+w<d[v]){
                d[v]=d[u]+w;
                q.push({v,d[v]});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++) {
            cin>>val[i];
            g[i].clear();
        }
        for(int i=1;i<=n;i++) {
            cin>>e[i];
            if(i!=0)
            g[i].push_back({i-1,0});
            g[i].push_back({e[i],val[i]});
        }
        dj(1);
        ll ans=0;
        ll sum=0;
        for(int i=1;i<=n;i++){
            sum+=val[i];
            ans=max(ans,sum-d[i]);
        }
        cout<<ans<<'\n';
    }
    return 0;
}