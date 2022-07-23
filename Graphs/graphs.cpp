#include <bits/stdc++.h>
using namespace std;
#define int long long
#define autorep(it,s) for(auto it = s.begin(); it!= s.end(); it++)

const int nmax = 10005+1;
vector<int> adj[nmax];
vector<pair<int,int>> adjwt[nmax];
int vis[nmax]={};

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

bool dfsVtoN(int vertex, int n)     //return true if exist path from Vertex to N; else false;
{
    vis[vertex]=1;

    bool pathExist=false;

    for(int child: adj[vertex])
    {
        if(pathExist)   break;
        if(vis[child]) continue;
        if(child==n)    return true;
        
        pathExist |=  dfsVtoN(child,n); 
    }

    return pathExist;
} 

////////---------------------BFS-----------------------------//////////

int level[nmax]={};    //(in BFS) NOTE: level[pos] gives shortest path length from SOURCE to POS 
int p[nmax]={};    //parent of a vertex

//O(V+E)
void bfs(int source)
{
    queue<int> q;    q.push(source);
    vis[source]=1;
    // p[source]=-1;

    while(!q.empty())      //O(V)      every time one vertex is popped
    {
        int curr = q.front(); q.pop();

        for(int child : adj[curr])      //O(2*E) = O(V1e)+O(V2e)...     V1e means Edges of V1 vertex
        {
            if(!vis[child])    
            {
                q.push(child);
                vis[child]=1;
                level[child]=level[curr]+1;
                // p[child]=curr;
            }
        }
    }

}



////////---------------------DIJKSTRA ALGORITHM-----------------------------//////////
const int INF = 1e9+10;
vector<int> dis(nmax,INF);

void dijkstra(int source){
    set<pair<int,int>> s;  // {wt,node}  : so that set will be sorted according to least WEIGHT

    s.insert({0,source});   dis[source]=0;

    while(s.size())
    {
        auto itrpair= *s.begin();
        int dist = itrpair.first;
        int v = itrpair.second;
        s.erase(s.begin());

        for(auto child : adjwt[v])
        {
            int child_v = child.second;
            int child_dist = child.first;

            if(dis[child_v]>(child_dist+dis[v]))
            {
                if(s.find({dis[child_v],child_v})!=s.end())    s.erase({dis[child_v],child_v});

                s.insert({child_dist,child_v});   
                dis[child_v]=child_dist+dis[v];  
            }
        }

    }

}

signed main() 
{  

    int n,k,l, ans=0; cin>>n>>k;
    
    for (int i = 0; i < n; i++)
    {
        cin>>k>>l;
        adj[k].push_back(l);
        adj[l].push_back(k);
    }

    // for (int i = 0; i <= 8; i++)
    // {
    //     if(vis[i]==0) 
    //     {
    //         dfs(i);
    //         cout<<'\n';
    //     }
    // }
    
    bfs(1);
    for (int i = 1; i <= 7; i++)
    {
        cout<<level[i]<<' ';
    }
    // cout<<dfsVtoN(1,7);
    
    
}