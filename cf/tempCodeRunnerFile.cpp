#include<bits/stdc++.h>
const int maxn=4e5+5;
int nxt[maxn];
void getnxt(std::string s){
    int i=0,j=-1;
    nxt[0]=-1;
    while(i<s.length()){
        if(j==-1||s[i]==s[j]){
            nxt[++i]=++j;
           // std::cout<<i<<' '<<nxt[i]<<std::endl;
        }
        else j=nxt[j];
    }
}

int main(){
    std::string s;
    std::cin>>s;
    getnxt(s);    
    if(s.length()!=1&&nxt[s.length()-1]>=s.size()/2){
        std::cout<<"yes"<<std::endl;
        std::cout<<s.substr(0,nxt[s.length()-1]+1)<<std::endl;
    }
    else std::cout<<"no"<<std::endl;
    return 0;

}