#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
#define int long long 

/* x^2+√x=n  . Find x?*/
double func(double n)
{
  double eps = 1e-7; //for 6 decimal precision

  double l=0 ,r=n;
  while(r-l>eps)
  {
    double mid = (l+r)/2;
    if(mid*mid+sqrt(mid)<n) l=mid;
    else r=mid;
  }
  return l;
}

signed main() 
{  
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  cout.precision(numeric_limits<double>::max_digits10);


  double n,x,y,m,k,ans=0; cin>>n;

  cout<<func(n);
  
}