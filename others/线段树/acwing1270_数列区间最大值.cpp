#include<bits/stdc++.h>
#pragma gcc optimize(2)
using namespace std;
const int maxn=2e5+5;
struct node{
    int val;
    int l;
    int r;
};
node sgt[maxn<<2];
int val[maxn],n,q;

void push_up(int p){
    sgt[p].val=max(sgt[p<<1].val,sgt[p<<1|1].val);
}

void build(int l,int r,int p){
    sgt[p].l=l;
    sgt[p].r=r;
    if(l==r){
        sgt[p].val=val[l];
        return ;
    }
    int mid=l+r>>1;
    build(l,mid,p<<1);
    build(mid+1,r,p<<1|1);
    push_up(p);
}


int query(int l,int r,int p){
    if(sgt[p].l>=l&&sgt[p].r<=r){
        //cout<<sgt[p].l<<" "<<sgt[p].r<<'\n';
        return sgt[p].val;
    }
    int mid=sgt[p].l+sgt[p].r>>1;
    if(r<=mid) return query(l,r,p<<1);
    if(l>=mid+1) return query(l,r,p<<1|1);
    return max(query(l,r,p<<1),query(l,r,p<<1|1));
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>val[i];
    build(1,n,1);
    while(q--){
        int l,r;
        cin>>l>>r;
        cout<<query(l,r,1)<<'\n';
    }
    return 0;
}