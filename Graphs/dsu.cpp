#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define autorep(it,s) for(auto it = s.begin(); it!= s.end(); it++)

const int nmax = 100000+1;
// vector<int> adj[nmax];
// vector<pair<int,int>> adjwt[nmax];
// int vis[nmax]={};

////////---------------------DISJOINT SET UNION-----------------------------//////////
int size1[nmax]={};
int parent[nmax]={};

//initializing all vertex's parent = itself  _AND_  size of it's set=1;
void make_set(int v){
    parent[v]=v;
    size1[v]=1;
}

//finds root of the set in which v is  _AND_  also directly connects/make parent root
int find_parent(int v){
    if(parent[v]==v)    return v;

    return parent[v]=find_parent(parent[v]);     //makes all's parent one
}

//combining a's and b's set if root/parent is not same  (b-->a : if size of a's set is larger)
void Union(int a, int b){
    a = find_parent(a);
    b = find_parent(b);
    
    if(a!=b){
        if(size1[a]<size1[b]) swap(a,b);
        parent[b]=a;
        size1[a]+=size1[b];
    }

}

int main() 
{  
    int n,k,l2,l1, ans=0,sum=0; cin>>n>>k;
    
    for (int i = 1; i <= n; i++)    make_set(i);
    
    for (int i = 0; i < k; i++)
    {
        cin>>l1>>l2;
        Union(l1,l2);        
    }

    for (int i = 1; i <= n; i++)
    {
        if(size1[i]>1)   ans++,sum+=size1[i];
    }
    cout<<ans+(n-sum); 
    
}