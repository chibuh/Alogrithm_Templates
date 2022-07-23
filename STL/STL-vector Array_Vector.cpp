#include <bits/stdc++.h>
using namespace std;
const int n=10,i=1;

/*ARRAY OF VECTORS*/    
vector<int> va[n];   // 'n' empty vectors are made, 
    //i.e. va[i] is a vector
va[i].push_back(x);

va[0][2];  //va[0]'s  2nd index (i.e. 3rd element)


/*VECTOR of VECTORS*/

vector<vector<int>> pa;
//input
	for (int i = 0; i < n; i++)
    {
	    cin>>l>>k;
        pa.push_back(vector<int> ());  //pushing empty vector
 
        pa[i].push_back(l);
        pa[i].push_back(k);
    }
//or
	for (int i = 0; i < n; i++)
    {
	  cin>>l>>k;
      vector<int> v;
      v.push_back(l);  v.push_back(k);
        
      pa.push_back(v);    //pushing vetor directly
    }


vv.push_back(vector<int> v());