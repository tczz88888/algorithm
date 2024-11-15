#include<bits/stdc++.h>
using namespace std;  
#define ll long long
const int maxn = 200005;  
  

int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    __int128 ans=0;
    ll deta=0;
    for(int i=0;i<s.length();i++){
        deta+=1ll*(i+1)*(s[i]-'0');
        ans=ans*10+deta;
        if(ans>=1000000000000000000){
            cout<<(ll)(ans/1000000000000000000);
            ans%=1000000000000000000;
            string s=to_string((ll)ans);
            for(int j=1;j<=18-s.length();j++) cout<<0;
        }
    }
    cout<<(ll)ans<<endl;
    return 0;
}

