/**                           _ooOoo_
 *                           o8888888o
 *                           88" . "88
 *                           (| -_- |)
 *                            O\ = /O
 *                        ____/`---'\____
 *                      .   ' \\| |// `.
 *                       / \\||| : |||// \
 *                     / _||||| -:- |||||- \
 *                       | | \\\ - /// | |
 *                     | \_| ''\---/'' | |
 *                      \ .-\__ `-` ___/-. /
 *                   ___`. .' /--.--\ `. . __
 *                ."" '< `.___\_<|>_/___.' >'"".
 *               | | : `- \`.;`\ _ /`;.`/ - ` : | |
 *                 \ \ `-. \_ __\ /__ _/ .-` / /
 *         ======`-.____`-.___\_____/___.-`____.-'======
 *                            `=---='
 *
 *         .............................................
 *                  佛祖保佑             永无BUG
 */

#include <bits/stdc++.h>
#pragma gcc optimize(2)
using namespace std;
#define ll long long
const int NOT_EXIST = 0x3f3f3f3f;
const int maxn = 2e5 + 5;
int n, MAX, k;
struct node_info
{
    int val;
    int id;
    int last_id;

    int tag_val;
    int tag_id;
    int tag_last_id;
};

struct node
{
    int ls = 0;
    int rs = 0;
    node_info info;
};
int len=1;
node sgt[10000000];

void alloc_ls(int p)
{
    sgt[p].ls = len;
    sgt[len]=node();
    ++len;
}

void alloc_rs(int p)
{
    sgt[p].rs = len;
    sgt[len]=node();
    ++len;
}

void alloc_son(int p)
{
    alloc_ls(p);
    alloc_rs(p);
}

void push_up(int p)
{
    int ls = sgt[p].ls;
    int rs = sgt[p].rs;
    if (sgt[ls].info.id == sgt[rs].info.id && sgt[ls].info.id != -1)
    { // 左右儿子都被同一程序占用
        sgt[p].info.id = sgt[ls].info.id;
        if (sgt[ls].info.id == 0 && sgt[ls].info.last_id == sgt[rs].info.last_id)
        { // 左右儿子都没被占用，而且左右儿子上次被同一程序占用
            sgt[p].info.last_id = sgt[ls].info.last_id;
        }
        else
            sgt[p].info.last_id = -1;
        if (sgt[ls].info.val == sgt[rs].info.val)
        { // 左右儿子被赋同一值
            sgt[p].info.val = sgt[ls].info.val;
        }
        else
            sgt[p].info.val = NOT_EXIST;
    }
    else
    {
        sgt[p].info.id = -1;
        sgt[p].info.last_id = -1;
    }
}

void push_down(int p)
{
    if (!sgt[p].ls)
        alloc_son(p);
    int ls = sgt[p].ls;
    int rs = sgt[p].rs;
    if (sgt[p].info.tag_id)
    {
        sgt[ls].info.id = sgt[p].info.id;
        sgt[rs].info.id = sgt[p].info.id;
        sgt[p].info.tag_id = 0;
        sgt[ls].info.tag_id = 1;
        sgt[rs].info.tag_id = 1;
    }

    if (sgt[p].info.tag_val)
    {
        sgt[ls].info.val = sgt[p].info.val;
        sgt[rs].info.val = sgt[p].info.val;
        sgt[p].info.tag_val = 0;
        sgt[ls].info.tag_val = 1;
        sgt[rs].info.tag_val = 1;
    }

    if (sgt[p].info.tag_last_id)
    {
        sgt[ls].info.last_id = sgt[p].info.last_id;
        sgt[rs].info.last_id = sgt[p].info.last_id;
        sgt[p].info.tag_last_id = 0;
        sgt[ls].info.tag_last_id = 1;
        sgt[rs].info.tag_last_id = 1;
    }
}

int search1(int u, int l, int r, int lc, int rc, int id)
{ // 找到被id程序占用的长度l，r是询问的区间，lc，rc是u对应的区间
  // cout<<lc<<' '<<rc<<' '<<sgt[u].info.id<<endl;
    if (sgt[u].info.id != -1)
    {
        return (sgt[u].info.id == id || sgt[u].info.id == 0) ? min(rc, r) : -1;
    }
    push_down(u);
    int mid = lc + rc >> 1;
    if (r <= mid)
        return search1(sgt[u].ls, l, r, lc, mid, id);
    if (l >= mid + 1)
        return search1(sgt[u].rs, l, r, mid + 1, rc, id);
    int res = search1(sgt[u].ls, l, r, lc, mid, id);
    if (res == mid)
        res = max(res, search1(sgt[u].rs, l, r, mid + 1, rc, id));
    return res;
}

int search2(int u, int l, int r, int lc, int rc, int id)
{ // 找到上次被id程序占用的长度l，r是询问的区间，lc，rc是u对应的区间
  // cout<<"lid1"<<lc<<' '<<rc<<' '<<sgt[u].info.last_id<<endl;
    if (sgt[u].info.last_id != -1)
    {
        return (sgt[u].info.last_id == id) ? min(rc, r) : -1;
    }
    push_down(u);
    int mid = lc + rc >> 1;
    if (r <= mid)
        return search2(sgt[u].ls, l, r, lc, mid, id);
    if (l >= mid + 1)
        return search2(sgt[u].rs, l, r, mid + 1, rc, id);
    int res = search2(sgt[u].ls, l, r, lc, mid, id);
    if (res == mid)
        res = max(res, search2(sgt[u].rs, l, r, mid + 1, rc, id));
    return res;
}

int search3(int u, int l, int r, int lc, int rc, int id)
{ // 找到被id程序占用的长度l，r是询问的区间，lc，rc是u对应的区间
    // cout<<"id1 "<<lc<<' '<<rc<<' '<<sgt[u].info.id<<endl;
    if (sgt[u].info.id != -1)
    {
        return (sgt[u].info.id == id) ? min(rc, r) : -1;
    }
    push_down(u);
    int mid = lc + rc >> 1;
    if (r <= mid)
        return search3(sgt[u].ls, l, r, lc, mid, id);
    if (l >= mid + 1)
        return search3(sgt[u].rs, l, r, mid + 1, rc, id);
    int res = search3(sgt[u].ls, l, r, lc, mid, id);
    if (res == mid)
        res = max(res, search3(sgt[u].rs, l, r, mid + 1, rc, id));
    return res;
}

void set_id(int u, int l, int r, int lc, int rc, int d, int x)
{
    if (lc >= l && rc <= r)
    {
        sgt[u].info.id = d;
        sgt[u].info.tag_id = 1;
        if (x != NOT_EXIST)
        {
            sgt[u].info.val = x;
            sgt[u].info.tag_val = 1;
        }
        return;
    }
    push_down(u);
    int ls = sgt[u].ls;
    int rs = sgt[u].rs;
    int mid = lc + rc >> 1;
    if (r <= mid)
        set_id(ls, l, r, lc, mid, d, x);
    else if (l >= mid + 1)
        set_id(rs, l, r, mid + 1, rc, d, x);
    else
    {
        set_id(ls, l, r, lc, mid, d, x);
        set_id(rs, l, r, mid + 1, rc, d, x);
    }
    push_up(u);
    // cout<<"set "<<u<<' '<<lc<<' '<<rc<<' '<<sgt[u].info.id<<endl;
}

void set_last_id(int u, int l, int r, int lc, int rc, int d)
{
    if (lc >= l && rc <= r)
    {
        sgt[u].info.last_id = d;
        sgt[u].info.tag_last_id = 1;
        return;
    }
    push_down(u);
    int ls = sgt[u].ls;
    int rs = sgt[u].rs;
    int mid = lc + rc >> 1;
    if (r <= mid)
        set_last_id(ls, l, r, lc, mid, d);
    else if (l >= mid + 1)
        set_last_id(rs, l, r, mid + 1, rc, d);
    else
    {
        set_last_id(ls, l, r, lc, mid, d);
        set_last_id(rs, l, r, mid + 1, rc, d);
    }
    push_up(u);
    // cout<<"set_last "<<u<<' '<<sgt[u].info.last_id<<endl;
}

pair<int, int> query(int u, int x, int lc, int rc)
{
    if (lc == rc||((lc<=x&&rc>=x)&&sgt[u].info.id!=-1&&sgt[u].info.val!=NOT_EXIST))
    {
        return sgt[u].info.id == 0 ? make_pair(0, 0) : make_pair(sgt[u].info.id, sgt[u].info.val);
    }
    push_down(u);
    int ls = sgt[u].ls;
    int rs = sgt[u].rs;
    int mid = lc + rc >> 1;
    if (x <= mid)
        return query(ls, x, lc, mid);
    else
        return query(rs, x, mid + 1, rc);
}

void op_write(int id, int l, int r, int x)
{
    int lim = search1(0, l, r, 1, MAX, id);
    if (lim >= l)
    {
        set_id(0, l, lim, 1, MAX, id, x);
        cout << lim << "\n";
    }
    else
    {
        cout << -1 << "\n";
    }
}

void op_earse(int id, int l, int r)
{
    int lim = search3(0, l, r, 1, MAX, id);
    if (r == lim)
    {
        // cout<<".............."<<id<<endl;
        set_last_id(0, l, r, 1, MAX, id);
        set_id(0, l, r, 1, MAX, 0, NOT_EXIST);
        cout << "OK" << "\n";
    }
    else
    {
        cout << "FAIL" << "\n";
    }
}

void op_recover(int id, int l, int r)
{
    int lim1 = search3(0, l, r, 1, MAX, 0);
    // cout<<"sb"<<endl;
    int lim2 = search2(0, l, r, 1, MAX, id);
    // cout<<lim1<<' '<<lim2<<endl;
    if (r == lim1 && r == lim2)
    {
        set_id(0, l, r, 1, MAX, id,NOT_EXIST);
        cout << "OK" << "\n";
    }
    else
    {
        cout << "FAIL" << "\n";
    }
}

void op_read(int p)
{
    auto ans = query(0, p, 1, MAX);
    cout << ans.first << ' ' << ans.second << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> MAX >> k;
    sgt[0]=node();
    while (k--)
    {
        int op;
        cin >> op;
        int l, r, id, x;
        if (op == 0)
        {
            cin >> id >> l >> r >> x;
            op_write(id, l, r, x);
        }
        else if (op == 1)
        {
            cin >> id >> l >> r;
            op_earse(id, l, r);
        }
        else if (op == 2)
        {
            cin >> id >> l >> r;
            op_recover(id, l, r);
        }
        else
        {
            cin >> x;
            op_read(x);
        }
    }
    return 0;
}