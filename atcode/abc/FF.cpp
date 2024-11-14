#include<bits/stdc++.h>
#pragma gcc optimize(2)
using namespace std;  
#define ll long long
const int maxn = 200005;  
int ans[maxn];
int h[maxn];
int q[maxn];
int tail=-1,head=0;
struct node{
    int pos;
    int mx;
    int l;
    int r;
};
node sgt[maxn<<2];

void push_up(int p){
    if(sgt[p<<1].mx<sgt[p<<1|1].mx){
        sgt[p].mx=sgt[p<<1|1].mx;
        sgt[p].pos=sgt[p<<1|1].pos;
    }
    else{
        sgt[p].mx=sgt[p<<1].mx;
        sgt[p].pos=sgt[p<<1].pos;
    }
}
void build(int l,int r,int p){
    sgt[p].l=l;
    sgt[p].r=r;
    if(l==r){
        sgt[p].mx=h[l];
        sgt[p].pos=l;
        return ;
    }
    int mid=l+r>>1;
    build(l,mid,p<<1);
    build(mid+1,r,p<<1|1);
    push_up(p);
}

pair<int,int> query(int l,int r,int p){
    if(sgt[p].l>=l&&sgt[p].r<=r){
        return make_pair(sgt[p].mx,sgt[p].pos);
    }
    int mid=sgt[p].l+sgt[p].r>>1;
    if(r<=mid) return query(l,r,p<<1);
    if(l>=mid+1) return query(l,r,p<<1|1);
    pair<int,int>p1=query(l,r,p<<1);
    pair<int,int>p2=query(l,r,p<<1|1);
    if(p1.first<p2.first){
        return p2;
    }
    else return p1;
}
int main(){
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>h[i];
    }
    for(int i=n;i>=1;i--){
        while(tail>=head&&q[tail]<=h[i]) --tail;
        q[++tail]=h[i];
        ans[i]=tail-head+1;
        cout<<ans[i]<<endl;
    }
    build(1,n,1);
    while(m--){
        int l,r;
        cin>>l>>r;
        int pos=query(l,r,1).second;
        cout<<ans[pos]-1<<'\n';
    }
    return 0;
}