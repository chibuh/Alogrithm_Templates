vector<int> v;  [Declaration]
v.push_back(value);

vector<int> v(4,-1);  //where 4 is the no. of elements and -1 is the value with which it is initialised
vector<int> v({6,4,5,7}); //Isme = vgerah lagake nhi karte
vector<int> v(arr,arr+3);
//arr is a pointer which points to the first element of array
//Vector vgerah me har jagah [First,Last) types scheme lagti hai
vector<int> v(v2.begin(),v2.end());
v2.begin() is a pointer [pointers are called iterators in case of vectors] that points to the 1st element of v2
v2.end() points to next to last element of v2
as v.begin(); is an operator comiple karne ke liye isko aise likhna padega
vector<int>::iterator it = v.begin(); // it is the var. name
or
auto it = v.begin(); // it is the var. name

Vector, arrays vaali saari properties dikhate hain, jaise v[1] se kisi bhi (initialised) element ko access kar sakte hain

v.size(); //To find size of array
v.empty(); //Batayega ki function empty hai ya nhi  //Ye bool dunction hai, 0/1 output dega
Assume vector hai - (2,5,2,7)
v.resize(8,-4);  //Ab vector- (2,5,2,7,-4,-4,-4,-4)
Agar- v.resize(3,-4);   //Ab vector- (2,5,2)





Min element/Max element -   //Ye array ke liye bhi chalta hai
min_element(v.begin(),v.end());
Ye ek pointer hai, to agar min element ki value ko store karna hai ya cout karana hai to * lagana padega
e.g.
int a=*min_element(v.begin(),v.end());
cout << *min_element(v.begin(),v.end()) << endl;

If we do -
cout << min_element(v.begin(),v.end()) << endl;
it will return the pointer.
E.g. like arr, v.begin() were pointers.
So, in v=(4,2,7,3,6)
*max_element(v.begin(),v.end())  will return 7 and
max_element(v.begin(),v.end()) will return v.begin()+2
Therefore, max_element(v.begin(),v.end()) - v.begin() will give the position of max element !!!!
So, position of max element in vector/array -
max_element(v.begin(),v.end()) - v.begin();
max_element(arr,arr+n) - arr;
Position of max/min element from end -
(v.end()-1)-max_element(v.begin(),v.end());
// We could have used v.rbegin() here as it points to the last element, but we can't as they are diff. type of operators







//To display a vector -
for (i=0;i<n(or v.size());i++)
{
    cout << v[i] << endl;
}

// This type of loops are called for each loops (Study more about them)
for (auto x: v)   // auto ki jagah int bhi use kar sakte hain, par auto se dhundhna ni padta kis cheez ka vector hai
{                 // ye auto vaali cheez arrays ke lie bhi applicable hai
    cout << x << endl;
}
for (auto it = v.begin();it!=v.end();it++)  // We use != here and not </<= etc. s </<= don't work with all iterators
{
    cout << *it << endl; // sirf it nhi chalega kyunki vo iterator hai
}



//To display a vector in reverse
for(i=n-1(or v.size()-1);i>=0;i--)
{
    cout << v[i] << endl;
}
for (auto it=v.end()-1;it!=v.begin()-1(or it>=v.begin();it--)) // We use != here and not </<= etc. s </<= don't work with all iterators

{
    cout << *it << endl;                                       // Can r.begin()-1 be used ???
}
for (auto it=v.rbegin();it!=v.rend();it++) //Here v.rbegin() points to the lest element (v.end()-1), and v.rend() points towards element before the 1st one (v.begin()-1)
{
    cout << *it << endl;
}
reverse(v.begin(),v.end());     
// Then display uding normal methods
The time complexity of the reverse() function is
-----------------O(n)---------------------- 
Strings are accessed like vectors whenever they need to be reversed/sorted.
reverse(str.begin(),str.end());
Using reverse/sort function on limited no. of arguments would just reverse/sort those elements of the arrey and keep others untouched.


//Sorting
The sort function we use [sort()], is a mixture of multiple type of sorts (merge, quick and bubble)(probably these), to provide us with the best time complexity in different scenarios.
Best case, avg. case and worst case time complexity of sort(), is
-------------------O(nlog(n))-------------------
Syntax - For arrays - sort(arr,arr+n);
         For vectors - sort(v.begin(),v.end());

Sort function syntax -
sort(kahan se shuru, kahan pe khatam(this not included), kaise sort karna hai);

Conventionally, it sorts in ascending order for numerals, and alphabetical order for strings (we can sort a single string among itself and a vector of different strings too)
                it sorts using the first value of the pair, if nothing is mentioned.


To sort in descending order -
sort(v.begin(),v.end());
reverse(v.begin(),v.end());

sort(v.begin(),v.end(),greater<int>()); // For strings too, greater<int>()/greater<char>(), can be used


If we want to sort in any particular order - e.g. first all even no. in ascending order, then all odd no. in descending order
Then, we use -
sort(v.begin(),v.end(),fn());
And we'll have to define the function above (before int main())

bool fn(int a,int b)  // a aur b hmare vector ke koi bhi 2 no. hain
{                     // agar a, b se pehle chahiye (a,b), to return 1, agar baad me chahiye (b,a), to return 0
    if (a%2==0 && b%2==0)
    {
        if (a>b)
        {return 0;}
        else
        {return 1;}   //return b>a;
    }
    else if (a%2==0)
    {return 1;}
    else if (b%2==0)
    {return 0;}
    else
    {return a>b;}
}

Here fn(), is known as custom comparator, to sort function jab bhi sort karega vo 2 elements is fn() me daalega aur us basis pe sort karega



------------
v.resize(10,-1) // resize to 10 indexes and (if new spaces created then fill -1. Else remove extra indexes from back)

