#include <bits/stdc++.h>
using namespace std;

int main()  {

    bitset<6> b1; // all 6 bits 0  // 000000
    bitset<6> b = bitset<6>(10);  // 001010   , b[0]==b[3]==1
    b[5]=1;    // 5th Bit set  // 010000 => 110000



    b<<=3;  // Left<< , Right>> Shift 3  // 001010 => 010000
    b^b1;   // |,&,^,!,~ ,etc of two bitset<SAME>



    b.set(4);    // b[4]    //set 4th BIT
    b.flip();    //~b    //flip ALL BITS
    b.flip(5);   // b[5] = !b[5] //   5th Bit flipped  // 110000 => 010000

    b.any();    // true if atleast one 1 is set
    b.none();    //  !b.any();   //true if all set to zero


    cout<<b<<'\n';
}