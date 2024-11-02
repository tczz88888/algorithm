#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=4e5+5;
int d[maxn],val[maxn];
int b[maxn];
ll sum[maxn];
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            cin>>val[i];
            sum[i]=sum[i-1]+val[i];
        }
        for(int i=1;i<=m;i++){
            cin>>b[i];
        }
        memset(d,0x3f,sizeof(d));
        d[0]=0;
        for(int i=1;i<=m;i++){
            int l=1,r=1;
            while(l<=r&&r<=n){
                //cout<<l<<endl;
                while(l<=r&&sum[r]-sum[l-1]>b[i]) ++l;
                d[r]=min(d[r],d[l-1]+m-i);
                ++r;
            }
        }
        if(d[n]!=0x3f3f3f3f) 
        cout<<d[n]<<endl;
        else cout<<-1<<endl;
    }
    return 0;
}