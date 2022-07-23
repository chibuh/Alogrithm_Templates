#include<bits/stdc++.h>
pair<int,int> p;  //Declaration
p.first=x;   //To access fisrt element    //Initialisation
p.second=y;  //To access second element   //Initialisation
p = make_pair(x,y);    //Initialisation
p = {x,y};             //Initialisation

pair<int,int> p(x,y);  //Declaration + Initialisation

p1(1,2);   p2(2,-7);    If we want to check p1>=p2 etc.
If 1st elements are different then it would be judged on the basis of 1st element only irrespective of the 2nd element
If 1st elements are same the the comparison is done on the basis of 2nd element

/*array of pair-*/
pair<int,int> pa[n];

pa[i] = {x,y};
pa[i] = make_pair(x,y);
//or
pa[i].first=x;   //To access fisrt element    //Initialisation
pa[i].second=y;  //To access second element   //Initialisation

//printing
    for(auto p : pa)
    {
        cout<<p.first<<' '<<p.second<<'\n';
    }

/*vector of pairs -*/
vector<pair<int,int>> vp;   //Declaration   i.e. each vector element will store a pair    (like integer in vector<int>)

vp[i].first=x;   //To access fisrt element    //Initialisation
vp[i].second=y;  //To access second element   //Initialisation

vp[i].pushback({x,y});    //Initialisation
vp[i] = make_pair(x,y);   //

vector<pair<int,int>> vp(n,{x,y});  //Declaration + Initialisation
vector<pair<int,int>> vp(n,make_pair(x,y));  //Declaration + Initialisation
Both of these will make vp as a vector of n pairs (x,y)


To display -
for (auto p: vp)
{
    cout << p.first << " " << p.second << endl;
}



