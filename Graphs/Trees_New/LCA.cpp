// Least Common Ancestor
#include <bits/stdc++.h>
using namespace std;

const int nmax = 1e5+1;
vector<int> adj[nmax];
int vis[nmax] = {};

vector<int> depth;
int LOG;
vector<vector<int>> up;

void dfs(int v)
{
    vis[v]=1;

    for(int child : adj[v])
    {
        if(vis[child])	continue;
        
        depth[child] = depth[v]+1;
        up[child][0] = v;
        for (int i = 1; i < LOG; i++)
        {
            up[child][i] = up[ up[child][i-1] ][i-1];
        }
        dfs(child);        
    }
}

int get_lca(int a, int b)   //NOTE: LCA always exist in a tree
{
    if(depth[a]<depth[b])   swap(a,b);  // to make a's depth greater always

    int k = depth[a]-depth[b];  // 'k' shift up 'a' => so that 'a' and 'b' are at same level/depth

    for (int i = LOG-1; i >= 0; i--)
    {
        if(k>=(1<<i))
        {
            k-=(1<<i);
            a = up[a][i];
        }
    }

    if(a==b)    return a;

    for (int i = LOG-1; i >= 0; i--)
    {
        if(up[a][i]!=up[b][i])
        {
            a = up[a][i];
            b = up[b][i];
        }
    }

    return up[a][0];    // as we will reach just child of LCA as condition was 'up[a][i]!=up[b][i]'
}

int main()
{
    int n; cin>>n;
    for (int i = 0; i < n-1; i++)
    {
        int k1,k2; cin>>k1>>k2;
        adj[k1].push_back(k2);
        adj[k2].push_back(k1);
    }

    LOG = ceil(log2(n));
    up = vector<vector<int>> (n+1,vector<int>(LOG));
    depth = vector<int> (n+1);
    
    //Let node 1 be root (doesnt matter which to take as root)

    for (int i = 0; i < LOG; i++)   up[1][i] = 1;       //making 1 itself all kth ancestor





    
    
}

