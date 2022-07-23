#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1000000007;

#define nodeSize 26

typedef struct Trie* trie;
struct Trie {
    trie bit[nodeSize];
    bool endOfWord = false;
};
trie root;

void insert (string word) {
    trie temp = root;

    for (int i=0;i<word.size();i++) {
        int b = word[i]-'a';
        if (!temp->bit[b]) {
            temp->bit[b] = new Trie();
        }
        temp = temp->bit[b];
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
