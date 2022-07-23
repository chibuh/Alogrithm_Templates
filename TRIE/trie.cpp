#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1000000007;
const int N2 = 998244353;
const int INF = 1000000000000000000;

#define nodeSize 26

typedef struct Trie* trie;
struct Trie {
    trie bit[nodeSize];
    bool endOfWord = false;
};
trie root;

void insert (string word) {

    trie temp = root;

    for(char c : words)
    {
        if(!temp->bit[c])
        {
            temp = temp->bit[c];
        }
        else 
        {
            trie newTrie;
            temp->bit[c] = newTrie;
            temp = newTrie;
        }
    }
    temp->endOfWord = true;
    
}

bool search (string word) {
    trie temp = root;

    for (int i=0;i<word.size();i++) {
        int b = word[i]-'a';
        if (!temp->bit[b]) {
            return false;
        }
        temp = temp->bit[b];
    }
    return temp->endOfWord;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    

    
    return 0;
}
