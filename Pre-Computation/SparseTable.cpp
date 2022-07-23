// SPARSE TABLE   https://www.youtube.com/watch?v=0jWeUdxrGm4
/* RANGE Minimum Query */
//USE ? MIN, MAX, GCD in range (l,r) in O(1)        (for sum->O(logn), better use Prefx Sum)

#include <bits/stdc++.h>
using namespace std;

int LOG;
vector<vector<int>> m;

//O(n*log(n))
void build(int n) {
    for(int i = 1; i < LOG; i++) {
		for(int j = 0; j + (1 << i) - 1 < n; j++) {
			m[j][i] = min(m[j][i-1], m[j+(1<<(i-1))][i-1]);
		}
	}
}

int query(int l, int r) {
    int len = (r-l+1);
    // int j = log2(len);
    int j = 0;
    while((1<<(j+1))<=len)   {
        j++;
    }

    return min( m[l][j] , m[r-(1<<j)+1][j] );
}

int main()  {

    int n; cin>>n;
    LOG = ceil(log2(n));
    m = vector<vector<int>> (n,vector<int> (LOG));



    //1) Input
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }

    //2) Preprocessing
    for (int i = 0; i < n; i++)
    {
        m[i][0] = a[i];
    }
    build(n);

    //3) Query
    int q; cin>>q;
    for (int i = 0; i < q; i++)
    {
        int l,r; cin>>l>>r;
        cout<<query(l,r)<<'\n'; 
    }

}