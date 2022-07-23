#include <bits/stdc++.h>
using namespace std;

#define long long int

// const int nmax = 1e5+1;
// int m;
// pair<int,int> arr[nmax];

// bool func(int ind, int sum)
// {


// }

signed main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n,m; cin>>n>>m;

    int a[n], b[n];

    int v1[n][2];
    for (int i = 0; i < n; i++)
    {
        cout<<v1[i][0]<<v1[i][1];
    }

    vector<vector<bool>> dp(5005, vector<int>(5005,false));
    dp[n][0] = true;


    for(int i = n - 1; i >= 0; i--){
        for(int sum = 0; sum <= 5000; sum++){
            if(sum - v1[i][0] >= 0) dp[i][sum] = dp[i + 1][sum - v1[i][0]];
            if(sum - v1[i][1] >= 0) dp[i][sum] = dp[i + 1][sum - v1[i][1]];
        }
    }

    // bool fl = func(n-1,sum);

    string ans = "";
    int prefix_sum = 0;
    for(int i = 0; i < n; i++){
        if(dp[i + 1][M - v1[i][0] - prefix_sum] == true){
            ans += "0";
            prefix_sum += v1[i][0];
        }
        else{
            ans += "1";
            prefix_sum += v1[i][1];
        }
    }

    cout<<s<<'\n';
    
    
}