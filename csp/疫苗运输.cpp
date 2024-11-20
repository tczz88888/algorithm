#include<bits/stdc++.h>
using namespace std;
const int maxn=505;
int d[maxn],st[maxn];//第i辆车最早拿到疫苗的时间和拿到疫苗的站点
bool vis[maxn];
int sz[maxn],id[maxn][maxn],dis[maxn][maxn],len[maxn];//第i辆车的车站数量。第j个站的编号以及和第一个站的距离,第i辆车一圈的距离
int dt[maxn][maxn];
int n,m;
struct node{
    int line;
    int pos;
};
vector<node>ver[maxn];
int exgcd(int a,int b,int &x ,int &y){
    if(b==0){
        x=1;
        y=0;
        return a;
    }
    int d=exgcd(b,a%b,y,x);
    y-=(a/b)*x;
    return d;
}

void dj(){
    memset(dis,0x3f,sizeof(dis));
    for(int i=1;i<=m;i++){
        for(int j=1;j<=sz[i];j++){
            if(id[i][j]==1){
                d[i]=dis[i][j];
                st[i]=j;
                break;
            }
        }
    }
    for(int i=1;i<=m;i++){
        int pos=1;
        for(int j=2;j<=m;j++){
            if(!vis[pos]&&d[j]<d[pos]){
                pos=j;
            }
        }
        vis[pos]=1;
        int dd=dis[pos][st[pos]];
        for(int s=1,j=st[pos];s<=sz[pos];s++,j++){
            int jj=(j-1)%sz[pos]+1;
            for(auto [line,p]:ver[id[i][j]]){
                if(vis[line]) continue;
                int d1=dd;
                int d2=dis[line][p];
                int a1=len[pos];
                int a2=len[line];
                int x,y;
                int D=exgcd(a1,a2,x,y);
                if((d1-d2)%D) continue;
                x=(d2-d1)/D*x;
                a2/=D;
                x=(x%a2+a2)%a2;
                if(d[line]>d1+x*a1){
                    d[line]=d1+x*a1;
                    st[line]=p;
                }
            }
            dd+=dis[pos][jj];
        }
    }
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>sz[i];
        for(int j=1;j<=sz[i];j++){
            cin>>id[i][j];
            int p;
            cin>>p;
            dt[i][j]=p;
            len[i]+=p;
            dis[i][j+1]=len[i];
            ver[id[i][j]].push_back({i,j});
        }
    }


    return 0;
}