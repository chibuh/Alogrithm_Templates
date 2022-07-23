#include <bits/stdc++.h>
using namespace std;
#define int long long
#define autorep(it,s) for(auto it = s.begin(); it!= s.end(); it++)

const int nmax = 3000+1;
vector<int> adj[nmax];
// vector<pair<int,int>> adjwt[nmax];
int vis[nmax]={};

set<pair<int,pair<int,int>>> s;

////////---------------------DFS-----------------------------//////////
void dfs(int vertex)
{
    vis[vertex]=1;
    // cout<<vertex<<"-";
    for(int child: adj[vertex])
    {
        if(!vis[child]) dfs(child);
    }
}

signed main() 
{

    int n,m,k,l1,l2,l3, ans=0; cin>>n>>m>>k;
    
    for (int i = 0; i < m; i++)
    {
        cin>>l1>>l2;
        adj[l2].push_back(l1);
        adj[l1].push_back(l2);
    }

        
    
}