#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
#define int long long 
#define LINE cout<<'\n'
#define PYES cout<<"YES"<<'\n'
#define PNO cout<<"NO"<<'\n'


int BinarySearch(int a[], int l, int r, int x)
{
  while(r-l>1)
  {
    int mid = (l+r)/2;
    if(a[mid]<x)  l=mid+1;
    else r=mid;
  }
  if(a[l]==x) return l;
  else if(a[r]==x) return r;
  else return -1;
}


int MaxIndexBinarySearch(int a[], int l, int r, int x)
{
  while (r-l>1)
  {
    int mid = (l+r)/2;
    if(a[mid]<=x)  l=mid+1;
    else r=mid;    
  }
  if(a[r]<=x) return r;
  if(a[r-1]<=x) return r-1;
  if(a[r-2]<=x) return r-2;
  return -1;
}

int MinIndexBinarySearch(int a[], int l, int r, int x)
{
  while (r-l>1)
  {
    int mid = (l+r)/2;
    if(a[mid]<x)  l=mid+1;
    else r=mid;    
  }
  if(a[l]>=x) return l;
  if(a[l+1]>=x) return l+1;
  if(a[l+2]>=x) return l+2;
  return l+3;
}

signed main() 
{  
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  // cout.precision(numeric_limits<double>::max_digits10);

    int n,m,k,ans=0; cin>>n;
    int _q; cin>>_q;

    int a[n];
    for (int i = 0; i < n; i++)
    {
      cin>>a[i];
    }

  for (int _t = 0; _t < _q; _t++)
  {
    cin>>k;
    // cout<<LowerBoundBinarySearch(a,0,n-1,k)+1<<'\n';   
    cout<<MinIndexBinarySearch(a,0,n-1,k)+1<<'\n';    

  }
  
}