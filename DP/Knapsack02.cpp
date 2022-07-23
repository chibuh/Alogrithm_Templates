#include <bits/stdc++.h>
using namespace std;
#define int long long

//Q) N items with ith item having weight Wi and value Vi.   What is Maximum Value (V) with atmost W weight??   https://www.youtube.com/watch?v=gHVtY5raAQg
    //same question but ** O(N*V*V) ,  as W=1e9 -> Space Complexity can't be O(N*W)  **

const int nmax = 100;
int a[nmax][2]={}; //{wt,cost}

int dp[nmax][100001];  //{index,cost} = minwt for that cost at index


int func(int index, int costleft)    //use costleft completly and get minWeight it can be achieved... else return INFINITE wt
{
    if(costleft==0) return 0;
    if(dp[index][costleft]!=-1) return dp[index][costleft];

    if(index==0)
    {
        if((costleft-a[0][1])==0)   return a[0][0];
        else return 1e15;
    }
    
    int wt0=0, wt1=1e15;

    wt0 = func(index-1,costleft);       // bina iss index ko liye minwt to make costLeft=0;    else return INFINITE wt
    if(costleft-a[index][1]>=0)    wt1= a[index][0] + func(index-1,costleft-a[index][1]);  // iss index ko like minwt to make costLeft=0; 
    
    return dp[index][costleft] = min(wt1,wt0);   
}

signed main() 
{    
    int n,w,sum=0; cin>>n>>w;    
    int maxcost=0;

    memset(dp,-1,sizeof(dp));


    for (int i = 0; i < n; i++) {cin>>a[i][0]>>a[i][1]; sum+=a[i][1];}

    for (int i = sum; i >= 0; i--)
    {
        int wt = func(n-1,i);   
        if(wt<=w)   {maxcost=i;break;}
    }
    cout<<maxcost;

}