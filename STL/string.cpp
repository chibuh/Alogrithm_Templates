#include <bits/stdc++.h>
using namespace std;
// #include<iostream>
// #include<string>

using namespace std;

int main(){
/*INITIALIZATION OF STRING*/

/*i*/       string str1=" ";

/*ii*/      string str2(5,'n');   // nnnnn

/*iii*/     string str3="Hi I'm Chirag.";     //Hi I'm Chirag.
             /*BUT*/
            string str3b; cin>>str3b; cout<<str3b;   //Input= Hi I'm Chirag.  || Output=Hi
            // space is considered /0 in string (char array), whereas if Method3 OR Method4 space is considered as Null Character ACII

    
        // Therefore use getline()
/*iv*/      string str4;            //Input a string line from User
            getline(cin,str4);  //Input= Hi I'm Chirag.  || Output=Hi I'm Chirag.   

/*DISPLAY STRING*/
/*i*/       cout<<str1;       //displays complete string.

/*ii*/      for (int i = 0; i < str1.length(); i++)
            {
                cout<<str1[i];
            }

/*iii*/     string s1="Family";  cout<<s1[1];    //Output=a   //2nd element ie 1 index  //Accessing Element (Just Like Vectors)

            
/*OPERATIONS*/
    
    string t = str1;    //copies complete string

    str1 + str2;   

    str2.append(str3);   // str2 = str2 + str3    //Output(str2 string changes to)= nnnnnHi   //Note: value of str2 changes

    cout<<str2+str1+str3;


/*FUNCTIONS*/

    s1.push_back('s');   // only insert CHAR
    s1.pop_back();       // deletes last CHAR
    s1.length(); s1.size();


    s1.clear();          // string becomes empty (length becomes 0)
    s1.empty();          // Tests whether the string is empty. This function return a Boolean value.
    //ERASE Between ELEMENTS
    s1.erase(3,2);       // s1.erase( <starting index> , <how many char> ) ||| ex) s1="0123456" ==> s1="01256";               

    //SORTING
    sort(s1.begin(), s1.end());     sort(s1.begin(), s1.end(), greater<>());
    reverse(s1.begin(), s1.end());

    //INSERT
        string s= "01267";
        s.insert(3,"345");      // insert "345" at 3rd index(starting from 0)
    
    //SUBSTRING
        s.substr(3,4);          // s1.substr( <starting index> , <how many char> ) ||| ex) s1="01234567" ==> s="3456"
    
    //FIND          https://www.geeksforgeeks.org/string-find-in-cpp/
    int ind1 = s.find(s1);       // returns the index of the first occurrence of sub-string.
    int ind2 = s.find(s1,ind1+1); // return next occurance
        
        // if the sub-string is not found it returns string::npos(string::pos is static member with value as the highest possible for the size_t data structure).
        if(ind1 != string::npos)
            cout<<"Substring found at index"<<ind1;

    int ind = s.find("geeks.practice", 0, 5);   // Only search first 5 characters of "geeks.practice" (ie geeks) in s


    //CONVERSION DataType
        /*A) string to Float/Int */
            int x= stoi("01234567")+1;        // x=1234568
            // stoi(s) / stol(s) / stoll(s) / stoul(s),etc   BASICALLY S_TO_Int/Long/LongLong/Unsinged....
            float y= stof("12.321")+10;       // y=22.321
            //stod(s) / stof(s) ,etc 

        /*B) Float/Int to String */  
            string sx = to_string(32) + '1';   //s="321" 
            string sy = to_string(21.3) + '1';   //s="21.3000001"

    //ALL to UPPER/LOWER CASE
        string s="a.Bc1";       //        transform( <pass string start> , <pass string end> , <start from which index?> , ::toupper); 
        transform(s.begin(),s.end(), s.begin(), ::toupper);  //s="A.BC1"
        transform(s.begin(),s.end(), s.begin(), ::tolower);  //s="a.bc1"

}
