#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int NOT_EXIST=2000000000;

const int maxn=2e5+5;
struct node_info{
    int val;
    int id;
    int last_id;

    int tag_val=NOT_EXIST;
    int tag_id;
    int tag_last_id;
};

struct node{
    int ls;
    int rs;
    node_info info;
};
vector<node>sgt;

void alloc_ls(int p){
    sgt[p].ls=sgt.size()+1;
    sgt.push_back(node());
}


void alloc_rs(int p){
    sgt[p].rs=sgt.size()+1;
    sgt.push_back(node());
}

void alloc_son(int p){
    alloc_ls(p);
    alloc_rs(p);
}

void push_up(int p){
    int ls=sgt[p].ls;
    int rs=sgt[p].rs;
    if(sgt[ls].info.id==sgt[rs].info.id&&sgt[ls].info.id!=-1){//左右儿子都被同一程序占用
        sgt[p].info.id=sgt[ls].info.id;
        if(sgt[ls].info.id==0&&sgt[ls].info.last_id==sgt[rs].info.last_id){//左右儿子都没被占用，而且左右儿子上次被同一程序占用
            sgt[p].info.last_id=sgt[ls].info.last_id;
        }
        else sgt[p].info.last_id=-1;
        if(sgt[ls].info.val==sgt[rs].info.val){//左右儿子被赋同一值
            sgt[p].info.val=sgt[ls].info.val;
        }
        else sgt[p].info.val=NOT_EXIST;
    }
}

void push_down(int p){
    if(!sgt[p].ls) alloc_son(p);
    int ls=sgt[p].ls;
    int rs=sgt[p].rs;
    if(sgt[p].info.tag_id){
        sgt[ls].info.id=sgt[p].info.tag_id;
        sgt[rs].info.id=sgt[p].info.tag_id;
        sgt[p].info.tag_id=0;
    }

    if(sgt[p].info.tag_val!=NOT_EXIST) {
        sgt[ls].info.val=sgt[p].info.tag_val;
        sgt[rs].info.val=sgt[p].info.tag_val;
        sgt[p].info.tag_val=NOT_EXIST;
    }

    if(sgt[p].info.tag_last_id){
        sgt[ls].info.last_id=sgt[p].info.tag_last_id;
        sgt[rs].info.last_id=sgt[p].info.tag_last_id;
        sgt[p].info.tag_last_id=0;
    }
}

int search(int u,int l,int r,int lc,int rc,int id){//找到被id程序占用的长度l，r是询问的区间，lc，rc是u对应的区间
    if(sgt[u].info.id!=-1){
        return (sgt[u].info.id==id||sgt[u].info.id==0)?min(rc,r):-1;
    }
    push_down(u);
    int mid=lc+rc>>1;
    int res=search(sgt[u].ls,l,mid,lc,rc,id);
    if(res==mid);
    res=max(res,search(sgt[u].rs,mid+1,r,lc,rc,id));
    return res;
}


void set_val(int u,int l,int r,int lc,int rc,int d){
    int ls=sgt[u].ls;
    int rs=sgt[u].rs;
    if(lc>=l&&rc<=r){
        sgt[u].info.val=d;
        sgt[u].info.tag_val=d;
        return ;
    }
    push_down(u);
    int mid=lc+rc>>1;
    if(r<=mid) set_val(ls,l,r,lc,mid,d);
    else if(l>=mid+1) set_val(rs,l,r,mid+1,rc,d);
    else{
        set_val(ls,l,r,lc,mid,d);
        set_val(rs,l,r,mid+1,rc,d);
    }
    push_up(u);
}

void set_id(int u,int l,int r,int lc,int rc,int d){
    int ls=sgt[u].ls;
    int rs=sgt[u].rs;
    if(lc>=l&&rc<=r){
        sgt[u].info.id=d;
        sgt[u].info.tag_id=d;
        return ;
    }
    push_down(u);
    int mid=lc+rc>>1;
    if(r<=mid) set_id(ls,l,r,lc,mid,d);
    else if(l>=mid+1) set_id(rs,l,r,mid+1,rc,d);
    else{
        set_id(ls,l,r,lc,mid,d);
        set_id(rs,l,r,mid+1,rc,d);
    }
    push_up(u);
}

void set_last_id(int u,int l,int r,int lc,int rc,int d){
    int ls=sgt[u].ls;
    int rs=sgt[u].rs;
    if(lc>=l&&rc<=r){
        sgt[u].info.last_id=d;
        sgt[u].info.tag_last_id=d;
        return ;
    }
    push_down(u);
    int mid=lc+rc>>1;
    if(r<=mid) set_last_id(ls,l,r,lc,mid,d);
    else if(l>=mid+1) set_last_id(rs,l,r,mid+1,rc,d);
    else{
        set_last_id(ls,l,r,lc,mid,d);
        set_last_id(rs,l,r,mid+1,rc,d);
    }
    push_up(u);
}

int query_id(int u,int x,int lc,int rc){
    int ls=sgt[u].ls;
    int rs=sgt[u].rs;
    if(lc==rc){
        return sgt[u].info.id;
    }
    push_down(u);
    int mid=lc+rc>>1;
    if(x<=mid) return query(ls,x,lc,mid);
    if(x>=mid+1) return query(ls,x,mid+1,rc);
}


pair<int,int> query(int u,int x,int lc,int rc){
    int ls=sgt[u].ls;
    int rs=sgt[u].rs;
    if(lc==rc){
        return sgt[u].info.id==0?make_pair(0,0):make_pair(sgt[u].info.id,sgt[u].info.val);
    }
    push_down(u);
    int mid=lc+rc>>1;
    if(x<=mid) return query(ls,x,lc,mid);
    if(x>=mid+1) return query(ls,x,mid+1,rc);
}


void op_write(int id,int l,int r,int x){

}

void op_earse(){

}

void op_recover(){
    
}

void op_read(){

}

int main(){

}