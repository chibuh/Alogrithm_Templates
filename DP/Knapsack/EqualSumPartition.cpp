#include <bits/stdc++.h>
using namespace std;
#define int long long

/*NOTE: Either do subsetSum for (sum/2)  when sum is even;   else false when sum is odd as cant be divides itno 2 partition*/
//RECURSIVE
static const int nmax = 1e2+1, msum = 1e4+1;
    


//Non-Recursive (Using Table Concept)
bool canPartition(vector<int>& nums) {
    int n = nums.size(), dif = 0;       // dif will be diference between sum of partitions
    for(int x : nums)   dif+=x;

    if(dif%2)   return false;
        
    bool dp[n+1][dif+1];
    memset(dp,false,sizeof(dp));
        
    dp[0][dif]=true;
        
    bool ans = false;
    for(int i = 1; i <= n ; i++)
    {
        for(int j = dif; j >= 0 ; j--)
        {
            if(dp[i-1][j])  
            {
                dp[i][j]=true;
                if(j-2*nums[i-1]>=0)   dp[i][j-2*nums[i-1]]=true;
            }
        }
    } 
    return ans;    
}



signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n,k; cin>>n>>k;
    vector<int> nums;
    for (int i = 0; i < n ; i++)
    {
        int temp; cin>>temp;
        nums.push_back(temp);
    }
    cout<<canPartition(nums)<<'\n';

}