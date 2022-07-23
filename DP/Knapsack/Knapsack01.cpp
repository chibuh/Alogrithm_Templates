#include <bits/stdc++.h>
using namespace std;
#define long long int

const int nmax = 1e5+1;
int dp[nmax][nmax];
int val[nmax]={}, weight[nmax]={};

int func(int ind, int wleft)
{
    if(ind<0) return 0;

    int x1 = func(ind-1,wleft);
    int x2 = 0;
    if(wleft-weight[ind]>=0)   x2 = val[ind] + func(ind-1,wleft-weight[ind]);

    return dp[ind][wleft] = max(x1,x2);
} 

signed main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  int n; cin>>n;
  for (int i = 0; i < n; i++)   cin>>val[i];
  for (int i = 0; i < n; i++)   cin>>weight[i];
  int W; cin>>W;

    cout<<func(n-1,W);
}