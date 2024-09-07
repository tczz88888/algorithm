//kmp，最后一个位置的next值如果大于串长度的一半则是yes，输出对应的next数组对应的字符串，不超过长度的一半则是no，等于一半也是no，因为要求俩有重叠部分
#include<bits/stdc++.h>
using namespace std;
const int maxn=4e5+5;
string s;
int nxt[maxn];
void getnxt(string s){
    int i=0,j=-1;
    nxt[0]=-1;
    while(i<s.length()){
        if((!~j)||s[i]==s[j]){
            nxt[++i]=++j;
            //cout<<i<<' '<<nxt[i]<<endl;
        }
        else j=nxt[j];
    }
}

int main(){
    cin>>s;
    getnxt(s);
    if(nxt[s.length()]>s.length()/2){
        cout<<"yes"<<endl<<s.substr(0,nxt[s.length()])<<endl;
    }
    else cout<<"no"<<endl;
    return 0;
}