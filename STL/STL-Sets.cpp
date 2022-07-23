/* SETS- avg O(log(n)) */

set<string> s;

s.insert("abc");    //stores in Lexographically Sorted order
            //s[] is invalid unlike in Maps


s.erase("abc");    //Unlike maps, it CAN directly erase Value (if exists)
//or
auto it = s.find("xyz");       //or Iterator wise like in Maps
    if(it!=s.end()) s.erase(it);


//printing set
for(string i : s){
    cout<<i<<endl;
}

for(auto it=s.begin(); it!=s.end() ; ++it){
    cout<<(*it)<<endl;
}


//other fn
s.size();
s.clear();


/* UNORDERED SETS - avg O(1) */

unordered_sets<T>  //T can be basic data types-int/float/../strings
 

/* MULTISETs  - avg O(log(n)) */
multiset<string> ms;
ms.insert("abc");
ms.insert("abc");       //it will store "abc" twice..

ms.erase("abc");   //will erase ALL occurances of "abc"
//or
auto it = ms.find("abc");       //This will erase only FIRST occurance of "abc"
    if(it!=s.end()) s.erase(it);

