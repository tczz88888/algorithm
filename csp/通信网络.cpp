#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+5;
vector<int>g[maxn];
int n,m;
int ct[maxn][maxn];
bool vis[maxn];
void dfs(int id,int u){
    for(auto v:g[u]){
        if(vis[v]) continue;
        vis[v]=1;
        ct[id][v]=1;
        ct[v][id]=1;
        dfs(id,v);
    }
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        memset(vis,0,sizeof(vis));
        vis[i]=1;
        dfs(i,i);
    }
    for(int i=1;i<=n;i++){
        int tot=0;
        for(int j=1;j<=n;j++){
            if(ct[i][j]==1) ++tot;
        }
       // cout<<tot<<' ';
        if(tot==n-1) ++ans;
    }
    //cout<<endl;
    cout<<ans<<endl;
    return 0;
}