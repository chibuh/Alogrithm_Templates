// Given array and sum, find if sum can be found using an element 0 or 1 time.
// 11:00 https://www.youtube.com/watch?v=jqJ5s077OKo 

#include <bits/stdc++.h>
using namespace std;


// O(1e5*n)

bitset<100001> can;
int main()  {

    int n,sum; cin>>n>>sum;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }

    can[0]=true;
    for (int i = 0; i < n; i++)
    {
        can |= can << (a[i]);       // here LEFT-SHIFT a[i] and taking OR is similar to setting all prev set bit and prev set bit + a[i];
    }

    if(can[sum])    cout<<"YES"<<'\n';
    else    cout<<"NO"<<'\n';
    
    
}