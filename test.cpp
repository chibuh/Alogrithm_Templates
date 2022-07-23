#include <bits/stdc++.h>
using namespace std;
#define long long int

signed main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);


	int a,b; cin>>a>>b;
	vector<int> v;

    int l = a;

    while(l<=b)
    {
        int pow = firstStep(l);

        while(pow>10)
        {
            int dif = (l/(pow/10))%10-(l/(pow/100))%10;
            if(dif==0)
            {
                l+=(pow/100);
            }
            else if(dif>1)
            {
                l+=(dif-1)*(pow/100);
            }
            else if(dif<-1)
            {
                l+=(pow/10);
				l-=(-dif)*(pow/100);
            }

            pow/=10;
        }

		if(v.size()!=0 && v[v.size()-1]==l)	l++;	
        else if(l<=b) v.push_back(l);
    }

	cout<<v.size()<<'\n';
	for (int i = 0; i < v.size(); i++)
	{
		cout<<v[i]<<' ';
	}

	
}