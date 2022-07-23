#include <bits/stdc++.h>
using namespace std;
#define int long long

//Q) N items with ith item having weight Wi and value Vi.   What is Maximum Value (V) with atmost W weight??   https://www.youtube.com/watch?v=tkoM1Pgt0Q4
    //** O(N*W) **

const int nmax = 100;
int a[nmax][2]={}; //{wt,cost}

int dp[nmax][100001];  //{index,wt}

int maxcost=0;

int func(int index, int wtleft)
{
    if(dp[index][wtleft]!=-1) return dp[index][wtleft];

    if(index==0)
    {
        if(wtleft-a[0][0]>=0)   return a[0][1];
        else return 0;
    }
    
    int cost0=0, cost1=0;

    cost0 = func(index-1,wtleft);    
    if(wtleft-a[index][0]>=0)    cost1= a[index][1] + func(index-1,wtleft-a[index][0]);
    
    return dp[index][wtleft] = max(cost0,cost1);
    
}

signed main() 
{    
    int n,w; cin>>n>>w;    

    memset(dp,-1,sizeof(dp));
    
    for (int i = 0; i < n; i++) cin>>a[i][0]>>a[i][1];

    maxcost = func(n-1,w);
 
    cout<<maxcost;

}