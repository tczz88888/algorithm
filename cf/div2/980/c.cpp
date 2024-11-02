#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
pair<int,int>p[maxn];
bool cmp(pair<int,int>a,pair<int,int>b){
    if(min(a.first,a.second)==min(b.first,b.second))
        return max(a.first,a.second)<max(b.first,b.second);
    return min(a.first,a.second)<min(b.first,b.second);
}
int main(){
    int n,t;
    cin>>t;;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>p[i].first>>p[i].second;
        }
        sort(p+1,p+1+n,cmp);
        for(int i=1;i<=n;i++){
            cout<<p[i].first<<' '<<p[i].second<<' ';
        }
        cout<<endl;
    }
    return 0;
}