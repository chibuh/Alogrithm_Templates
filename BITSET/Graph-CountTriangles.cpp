// Given array and sum, find if sum can be found using an element 0 or 1 time.
// 13:00 https://www.youtube.com/watch?v=jqJ5s077OKo 
#include <bits/stdc++.h>
using namespace std;


// O(1e5*n)
const int nmax = 1e5+1;
bitset<nmax> adj[nmax];
int main()  {

    int n,m; cin>>n>>m;
    for (int i = 0; i < m; i++)
    {
        int k1,k2; cin>>k1>>k2;
        adj[k1][k2]=1;
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(i!=j)
            {
                ans+=(adj[i]&adj[j]).count();   
            }
        }
    }
    cout<<ans/3;
    
    
    
}