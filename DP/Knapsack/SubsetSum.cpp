#include <bits/stdc++.h>
using namespace std;
#define int long long

static const int nmax = 1e2+1, msum = 1e4+1;
    
//RECURSIVE
int dp[nmax][msum];
int v[nmax];
    
bool func(int ind, int sum)
{
    if(ind<0)   return (sum==0);
    if(dp[ind][sum]!=-1)    return dp[ind][sum];
        
    bool fl = func(ind-1,sum);
    if(sum>=v[ind])    fl|=func(ind-1,sum-v[ind]);
        
    return dp[ind][sum] = fl|=(sum==0);
}  
bool isSubsetSum(vector<int>arr, int sum){
    memset(dp,-1,sizeof(dp));
    for(int i = 0; i<arr.size(); i++)   v[i]=arr[i];
    return func(arr.size()-1,sum);
}





//Non-Recursive (Using Table Concept)
bool isSubsetSum(vector<int>arr, int sum){
    int n = arr.size();
    bool dp[n+1][sum+1];
    memset(dp,false,sizeof(dp));
        
    dp[0][0] = true;
        
    for(int i = 1; i<=n ; i++)
    {
        for(int j = 0; j<=sum ; j++)
        {
            if(dp[i-1][j]) 
            {
                dp[i][j]=true;
                if(arr[i-1]+j<=sum) dp[i][j+arr[i-1]]=true;
            }
        }
    }
    return dp[n][sum];
}




signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n,k; cin>>n>>k;
    for (int i = 0; i < n ; i++)
    {
        cin>>a[i];
    }


}