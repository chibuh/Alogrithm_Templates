#include <bits/stdc++.h>
using namespace std;

const int M = 26;

struct Trie {
    Trie* bit[M];
    int count = 0;
};
Trie* root;

void insert(string word) {
    Trie* temp = root;
    for(auto ch : word) {
        int b = ch - 'a';
        if(!temp->bit[b]) {
            temp->bit[b] = new Trie();
        }
        temp = temp->bit[b];
        temp->count++;
    }
}

int score(string word) {
    Trie* temp = root;
    int ans = 0;
    for(auto ch : word) {
        int b = ch - 'a';
        temp = temp->bit[b];
        ans += temp->count;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    root = new Trie();

    int n, k;
    cin >> n >> k;
    vector <string> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        insert(v[i]);
    }
    for(int i = 0; i < n; i++) {
        cout << score(v[i]) << " ";
    }
    
    return 0;
}