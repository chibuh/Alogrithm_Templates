#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
#define int long long 
#define LINE cout<<'\n'


const int nmax = (1e5) +1;
int a[nmax];

int fibo(int n)
{
  if(a[n]!=-1)  return a[n];

  if(n==1)  return a[1]=0;
  if(n==2)  return a[2]=1;

  return a[n]=fibo(n-1)+fibo(n-2);
}

signed main() 
{  
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  // cout.precision(numeric_limits<double>::max_digits10);

  memset(a,-1,sizeof(a));
  cin>>m;
  
  cout<<fibo(n);

}