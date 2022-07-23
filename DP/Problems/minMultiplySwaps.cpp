#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
#define int long long 
#define LINE cout<<'\n'
#define PYES cout<<"YES"<<'\n'
#define PNO cout<<"NO"<<'\n'

/*
https://codeforces.com/contest/1637/problem/D

1. starting from index=n-1
2. dp[index][sumOfA[i]'s from n-1 to index] is a[index]*(a[index+1]+....+a[n-1])

*/

const int nmax = 100+1;
int a[nmax],b[nmax],m;
int s1=0,s2=0,s=0;  //s is constant

int dp[nmax][10000+2];


void func(int index, int temps, int temps1)
{
  if(index<0) return ;

  for (int i = 0; i < 10002; i++)
  {
    if(dp[index+1][i]!=-1)
    {
      int x = dp[index+1][i];       //i is sum{a[index+1] to a[n-1]]}, temps-i is sum{a[index+1] to a[n-1]]}
      int newsa=i+a[index];
      int newsb=i+b[index];

      if(dp[index][newsa]==-1)    dp[index][newsa] = x + (i)*a[index] + ((temps-i))*b[index] ;
      else  dp[index][newsa] = min(dp[index][newsa] , x + (i)*a[index] + ((temps-i))*b[index]  );
      
      if(dp[index][newsb]==-1)   dp[index][newsb] = x+ (i)*b[index] + ((temps-i))*a[index];
      else dp[index][newsb] = min(dp[index][newsb] , x+ (i)*b[index] + ((temps-i))*a[index]);
    }
  }
  

  func(index-1,temps+a[index]+b[index],temps1+a[index]);
}


signed main() 
{  
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  int _q; cin>>_q;

  for (int _t = 0; _t < _q; _t++)
  {
    memset(dp,-1,sizeof(dp)); memset(a,0,sizeof(a)); memset(b,0,sizeof(b)); s1=0,s=0,s2=0;

    int n,k,ans=0; cin>>n; m=n;
    for (int i = 0; i < n; i++) cin>>a[i];
    for (int i = 0; i < n; i++) cin>>b[i];

    for (int i = 0; i < n; i++)
    {
      ans+=((a[i]*a[i])+(b[i]*b[i]))*(n-1); 
      s+=a[i]+b[i];
      s1+=a[i];
      // s2+=max(a[i],b[i]); //s2=s-s1;
    }
    
    dp[n-1][a[n-1]] = 0;
    dp[n-1][b[n-1]] = 0;

    func(n-2,a[n-1]+b[n-1],a[n-1]); 

    int mini=INT_MAX;
    for (int i = 0; i < 10002; i++)
    {
      if(dp[0][i]!=-1) mini=min(mini,dp[0][i]);
    }
    
    cout<<ans+2*mini<<'\n';

    // for (int j = 0; j < s2+1; j++)
    // {
    //   for (int i = n-1; i >=0 ; i--)
    //   {
    //     cout<<dp[i][j]<<',';
    //   }
    //   LINE;
    // }
    // LINE;
    
    
  }
  
}