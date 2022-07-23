#include <bits/stdc++.h>
using namespace std;
//Pointers -  points to address.. to access value= *(pointer)

//Iterators-  points elements of a container

//ex)
begin()   // points to FIRST element of a container
end()     // points to NEXT of LAST (i.e. last+1) element of a container

rend()    // points to PREVIOUS oF FIRST (i.e. first-1) element of a container
rbegin()  //points to LAST element of a container



//DECLARING an iterator     container ::iterator itr;
//ex)
vector<int> ::iterator itr = v.begin();
    //Value iterator is pointing at?
cout<<(*itr);    //prints the first element v[0]


//NOTE   itr++  vs itr+1
itr++ // itr now points to next element of container
itr+1 // itr+1 points to next address   [NOTE: it won't work in maps/sets ,etc as next elemnt is not in address+1 ]

vector<int> ::iterator itr;
for (itr = v.begin(); itr !=v.end() ; ++itr)
{
    cout<<(*itr);
}

//vectorPair
vector<pair<int,int>> ::iterator itr;
for (itr = v.begin(); itr !=v.end() ; ++itr)
{
    cout<<(*itr).first<<' '<<(*itr).second;
}
//or             (*itr).first  ==SAME==  (itr->first)
for (itr = v.begin(); itr !=v.end() ; ++itr)
{
    cout<<(itr->first)<<' '<<(itr->second);
}




