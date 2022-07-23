#include <bits/stdc++.h>
using namespace std;

#define long long int

signed main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n; cin>>n;

    for (int i = 1; i < 180; i++)
    {
        if(i*i*i*i>=n)  
        {
            cout<<4*i<<'\n';
            break;
        }
        else if(i*i*i*(i+1)>=n)
        {
            cout<<4*i+1<<'\n';
            break;
        }
        else if(i*i*(i+1)*(i+1)>=n)
        {
            cout<<4*i+2<<'\n';
            break;
        }
        else  if(i*(i+1)*(i+1)*(i+1)>=n)
        {
            cout<<4*i+3<<'\n';
            break;
        }
    }
    
}