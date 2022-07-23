// Kth Ancestor of a Tree Node
/*  (BINARY LIFTING)  */

#include <bits/stdc++.h>
using namespace std;

const int nmax = 1e5+1;
vector<int> adj[nmax];

vector<int> parent;
vector<int> depth;
int LOG;
vector<vector<int>> up;

void dfs(int v, int par)        //O(n)
{
    for(int child : adj[v])
    {
        if(child!=par)
        {
            depth[child] = depth[v]+1;

            up[child][0] = v;
            for (int i = 1; i < LOG; i++)       //O(logn)
            {
                up[child][i] = up[ up[child][i-1] ][i-1];  //i.e. 2^(i) ancestor of child is => 2^(i-1) ancestor of 2^(i-1) ancestor of child
            }
            
            dfs(child,v);
        }
    }
}

// void dfs_depth(int v, int par)        //O(n)  (for  Method 2)
// {
//     for(int child : adj[v])
//     {
//         if(child!=par)
//         {
//             depth[child] = depth[v]+1;
//             parent[child] = v;            
//             dfs(child,v);
//         }
//     }
// }

//Nodes from 1 to n

int main()
{
    int n; cin>>n;

//O(n*log(n))
/*1 - Recursive dfs approach*/    

    for (int i = 1; i <= n-1; i++)      //'n-1' edges of a tree
    {
        int k1,k2; cin>>k1>>k2;
        adj[k1].push_back(k2);
        adj[k2].push_back(k1);
    }
    LOG = ceil(log(n));
    up = vector<vector<int>> (n+1,vector<int>(LOG));
    depth = vector<int> (n+1);

    up[1][0]=1; // so that for kth parent>depth could 1 itself intead of RTE/-1,etc. Just for convinience. 
    dfs(1,1);


//O(n*log(n))
/*2 - Iterative approach using parent array */
    // Let node 1 be root

    // parent = vector<int>(n+1);    // par[i] = parent of ith
    // parent[1]=1;
    // dfs_depth(1,1);

    // for (int i = 1; i <= n; i++)
    // {
    //     up[i][0] = parent[i];
    // }
    // for (int i = 1; i < LOG; i++)   //NOTE: 1 to LOG (not 0 as covered earlier)
    // {
    //     for (int v = 1; v <= n; v++)
    //     {
    //         up[v][i] = up[ up[v][i-1] ][i-1];  // 2^(i-1)th parent's 2^(i-1)th parent
    //     }
    // }


/*******************************************************/

//O(logn)
//FIND kth ancestor of NODE 'm';  

    int k,m; cin>>k>>m;
    if(depth[m]<k)  cout<<-1<<'\n'; //No Ancestor
    else
    {
        for (int i = LOG-1; i >=0 ; i--)
        {
            if(k>=(1<<i))   
            {
                m = up[m][i];
                k-=(1<<i);
            }
        } 
        cout<<m<<'\n';       
    }
    

}

