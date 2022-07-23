#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
#define int long long 
#define LINE cout<<'\n'
#define PYES cout<<"YES"<<'\n'
#define PNO cout<<"NO"<<'\n'

const int nmax = 1e5;

int t[4*nmax]={};

void build(int a[], int v, int tl, int tr)  //initially ->  v=1 (index of current vertex) | tl=0 & tr=n-1  (tl....tr)
{
    if (tl == tr) {             // bottom_most/leaf case
        t[v] = a[tl];
    }
    else {
        int tm = (tl + tr) / 2;     //dividing curr segment into two halves (tl...tr)==> (tl...tm) & (tm+1....tr)
        build(a, v*2, tl, tm);      //building left (tl...tm) segment
        build(a, v*2+1, tm+1, tr);  //building right (tm+1...tr) segment

        t[v] = min(t[v*2],t[v*2+1]);   /*OPERATION*/
    }
}

void update(int v, int tl, int tr, int pos, int new_val) 
{
    if (tl == tr) {
        t[v] = new_val;
    } 
    else {
        int tm = (tl + tr) / 2;

        if (pos <= tm)  update(v*2, tl, tm, pos, new_val);
        else    update(v*2+1, tm+1, tr, pos, new_val);

        t[v] = min(t[v*2],t[v*2+1]);   /*OPERATION*/
    }
}

int sum(int v, int tl, int tr, int l, int r)
{
    if (l > r)   return INT_MAX;   /*OPERATION*/
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return min(sum(v*2, tl, tm, l, min(r, tm)) , sum(v*2+1, tm+1, tr, max(l, tm+1), r));   /*OPERATION*/
}


signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,m,q,k,ans=0; cin>>n>>q;
    int a[n];
    for (int i = 0; i < n; i++) cin>>a[i];

    build(a,1,0,n-1);

    for (int i = 0; i < q; i++)
    {
        int tq,l,r; cin>>tq>>l>>r;
        if(tq==1) update(1,0,n-1,l,r);
        else cout<<sum(1,0,n-1,l,r-1)<<'\n';
    }
}