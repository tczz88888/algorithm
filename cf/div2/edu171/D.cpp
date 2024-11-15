#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+5;
#define ll long long
ll val[maxn];
ll cnt[maxn];
ll sum1[maxn];
ll sum2[maxn];
int n;

void query(int l,int r){
    int posl=lower_bound(cnt+1,cnt+1+n,l)-cnt;
    int posr=lower_bound(cnt+1,cnt+1+n,r)-cnt;
    ll ans=sum2[posr-1]-sum2[posl];
    ans+=sum1[l-cnt[posl-1]]-sum1[n+1]+val[posl-1]*n-(l-cnt[posl-1]+1);
    ans+=sum1[l-cnt[posl-1]]-sum1[n+1]+val[posl-1]*n-(l-cnt[posl-1]+1);
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>val[i];
        cnt[i]=n-i+1;
        cnt[i]+=cnt[i-1];
    }
    for(int i=n;i>=1;i--){
        sum1[i]=sum1[i]*(n-i+1);
    }
    for(int i=1;i<=n;i++){
        sum2[i]=sum2[i-1]+sum1[i];
    }
    return 0;
}