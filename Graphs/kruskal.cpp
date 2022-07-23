#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define autorep(it,s) for(auto it = s.begin(); it!= s.end(); it++)

const int nmax = 100000+1;
// vector<int> adj[nmax];
// vector<pair<int,int>> adjwt[nmax];
// int vis[nmax]={};

////////---------------------KRUSKAL's ALGORITHM-------(to find minimum cost spanning tree)----------------------//////////

int size1[nmax]={};
int parent[nmax]={};

void make_set(int v){
    parent[v]=v;
    size1[v]=1;
}
int find_parent(int v){
    if(parent[v]==v)    return v;

    return parent[v]=find_parent(parent[v]);     //makes all's parent one
}

int Kruskal(){

 int n,m, cost=0; cin>>n>>m;  

    for (int i = 1; i <= n; i++) make_set(i);   //assuming vertices start from 1;
    
 pair<int,pair<int,int>> edges[m];  //{wt,{v1,v2}}  -  so that sort according to weights of edges

    for (int i = 0; i < m; i++)
    {
        int wt,a,b; cin>>a>>b>>wt;
        edges[i]={wt,{a,b}};
    }
    sort(edges,edges+m);

    for (int i = 0; i < m; i++)
    {
        int wt = edges[i].first;
        int v1 = edges[i].second.first;
        int v2 = edges[i].second.second;

        v1 = find_parent(v1);
        v2 = find_parent(v2);
        
        if(v1!=v2){
            if(size1[v1]<size1[v2]) swap(v1,v2);
            parent[v2]=v1;
            size1[v1]+=size1[v2];
            cost+=wt;
            // cout<<edges[i].second.first<<' '<<edges[i].second.second<<' '<<wt<<'\n';
            // cout<<size1[v1]<<'\n';
        }
    }

    return cost;

}

int main() 
{    
    cout<<Kruskal();
}