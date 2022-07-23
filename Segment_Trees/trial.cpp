#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
#define int long long 
#define LINE cout<<'\n'
#define LOW -1e18

int n;
const int nmax = 1e5+1;

int t[4*nmax]={};

void build(int a[], int v, int tl, int tr)  //initially ->  v=1 (index of current vertex) | tl=0 & tr=n-1  (tl....tr)
{
    if (tl == tr) {             // bottom_most/leaf case
        t[v] = a[tl];   /*B1)OPERATION*/
    }
    else {
        int tm = (tl + tr) / 2;     //dividing curr segment into two halves (tl...tr)==> (tl...tm) & (tm+1....tr)
        build(a, v*2, tl, tm);      //building left (tl...tm) segment
        build(a, v*2+1, tm+1, tr);  //building right (tm+1...tr) segment

        t[v] = t[v*2] + t[v*2+1];   /*A1)OPERATION*/
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

        t[v] = t[v*2] + t[v*2+1];   /*A2)OPERATION*/
    }
}

int sum(int v, int tl, int tr, int l, int r)
{
    if (l > r)   return 0;      /*A3)OPERATION*/
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return sum(v*2, tl, tm, l, min(r, tm)) + sum(v*2+1, tm+1, tr, max(l, tm+1), r); /*A4)OPERATION*/
}

pair<int,int> maxSeg(int v, int tl, int tr)     // {l,r}
{
    if(tl==tr)  return {tl,tr};

    int tm = (tl+tr)/2;

    pair<int,int> p1 = maxSeg(v*2, tl, tm);
    pair<int,int> p2 = maxSeg(v*2+1, tm+1, tr);
    
    int s1 = sum(1,0,n-1,p1.first,p1.second);
    int s2 = sum(1,0,n-1,p2.first,p2.second);
    int s12 = sum(1,0,n-1,p1.first,p2.second);
    
    int s1122 = LOW, s122 = LOW, s112 = LOW;

    if((p1.second<tm) && (p2.first>tm+1)) s1122 = sum(1,0,n-1,p1.second+1,p2.first-1);

    int maxi = max({s1,s2,s12,s112});

    if(s2==maxi && s1==maxi)
    {
        if(v%2==0) return p2;
        else return p1;
    } 
    else if(s1==maxi)   return p1;
    else if(s2==maxi)   return p2;
    else if(s12==maxi) return {p1.first,p2.second};
    else return {p1.second+1,p2.first-1};
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int m,q,k,ans=0; cin>>n>>q;
    int a[n];
    for (int i = 0; i < n; i++) cin>>a[i];

    build(a,1,0,n-1);

    pair<int,int> temp = maxSeg(1,0,n-1);
    cout<<max(0ll,sum(1,0,n-1,temp.first,temp.second))<<'\n';

    for (int i = 0; i < q; i++)
    {
        int l,r; cin>>l>>r;
        update(1,0,n-1,l,r);

        temp = maxSeg(1,0,n-1);
        cout<<max(0ll,sum(1,0,n-1,temp.first,temp.second))<<'\n';
    }
}