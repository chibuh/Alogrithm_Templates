#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
#define int long long 
#define LINE cout<<'\n'
#define PYES cout<<"YES"<<'\n'
#define PNO cout<<"NO"<<'\n'


// Q) Given 'q' queries => (x,l,r) i.e.  to add 'x' to a[l] to a[r]

// O(n)

/*
 arr =  1   2   3   4   5   6
        0   z   0   0  -z   0   (l=2 to r=4 tak add z to every element)
presum= 0   z   z   z   0   0 
      
        y   0   0  -y   0   0   (l=1 to r=3 tak add z to every element)
        y   z   0  -y  -z   0
presum= y  y+z y+z z    0   0
*/



signed main() 
{  
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  int n,m,k,ans=0; cin>>n;
  int a[n], pre[n]={};
  for (int i = 0; i < n; i++) cin>>a[i];

  int _q; cin>>_q;

  for (int _t = 0; _t < _q; _t++)
  {
    int l,r,z; cin>>l>>r>>z; l--,r--;
    pre[l]=z; pre[r+1]=-z;    
  }

  for (int i = 1; i < n; i++)
  {
    pre[i]=pre[i-1]+pre[i];
  }
  
  
}