Map is like a vector of pairs
Just map(), is always remains sorted in increasing order w.r.t KEY (Cant be sorted on base of value)

SYNTAX - map<key,value> mp;
mp[key]=x; //To access value corresponding to a particular key value

map<int,int> mp;
Here all operations has   //Operations like map me koi element daalna, ya kisi element ko access karke change karna etc.
------------------O(logn)------------------ time complexity ON AVERAGE

mp.size();   //For finding size
//If we add any element to the map, it itself gets sorted, so if we print the values, they will be displayed in sorted order
map<int,int> mp;
//If we do
mp[3]=6;  //map={3,6}  //mp.size()=1;
mp[2]++;  //We know that a point with key 2 hasn't been initialised yet, but map itself intialises each value as 0
          //So, now map={2,1},{3,6}     //mp.size()=2;
mp[-3];    //map={-3,0},{2,1},{3,6}     //mp.size()=3;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

To store frequencies of values in any array -
long long int a[n]={1,5,2,5,6,5445,63463,6,77587,856,4873459875833 . . . . . . . };  //This array can have any large values too
map<long long int,int> cnt;  //No need to initialise like in case of array
for (int i=0;i<n;i++)
{
    cnt[a[i]]++;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

To print a map -
   1)   for(auto pi : mp)     // auto = pair<int,int>
    	{
           cout << pi.first << ' ' << pi.second << '\n';
    	}

   2)   for (auto itr = mp.begin(); itr != mp.end(); ++itr) 
    	{
      	   auto pi = *itr;
      	   cout << pi.first << ' ' << pi.second << '\n';
    	}

   3) 	map<int, int>::iterator itr;
    	for (itr = mp.begin(); itr != mp.end(); ++itr) 
		{
           cout << itr->first << ' ' << itr->second << '\n';
    	}

//If we wanna keep an data type instead of auto - Use-
for (pair<int,int> pi: mp)
........


If we want to know if an element has been earlier initialised or not - (Searches by KEY value)
-------------------------O(logn)---------------------------
if (mp.find(4)!=mp.end())
{
    cout << "YES";
}

mp.erase(mp.find(3));    //For deleting an element  //NOTE: can't give mp.end iterator in erase (else SEGMENTATION FAULT)
-------------------------O(logn)--------------------------------
So, its easy to delete element for a map than vectors etc. (Vectors take O(n) time)

auto it = mp.find(x) //mp.find() returns a iterator pointing to the key x, (if not present, point to mp.end())
if(it!=mp.end()) cout<<(*it).first<<' '<<(*it).first;


mp.clear() //clears map


//TIME COMPLEXITY is generally O(log(n)) , but ex)
mpstr["abcd"]="cdc";    //O(log(n))*s.size()    as so string can be arranged to be in sorted order by keys


//Q) given N strings, Print unique string in lexographically order and their frequency
map<string,int>  mapstr;  //keys will be sorted lexxogr.. with value as frequency







/*UNORDERED MAPS  - use Hash Tables (instead of Trees) implementation - O(1) Average time complexity - no sorting of keys, random order*/  
unordered_map<int,int> unmp;   //in unordered maps: key can't be pair<int,int>/vectors,etc as their implementation is not defined in unordered maps

/*MULTIMAPS- can store same key multiple times--- but instead, can use map<int,vector<int>>*/
