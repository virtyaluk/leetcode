#define ll long long

void make_set(vector<ll> &id, vector<ll> &rank, ll n) {
    for(ll i=1; i<=n; i++) {
        id[i] = i;
        rank[i] = 1;
    }
}

ll find_set(vector<ll> &id, ll p) {
    ll root = p;
    //find the root
    while(root != id[root]) {
        root = id[root];
    }
    //perform path compression
    while(p != root) {
        ll newp = id[p];
        id[p] = root;
        p = newp;
    }
    return root;
}

bool merge_set(vector<ll> &id, vector<ll> &rank, ll x, ll y) {
    x = find_set(id, x);
    y = find_set(id, y);
    
    if (x == y) {
        return false;
    }
    
    if(rank[x] > rank[y])
        id[y] = x;
    else
        id[x] = y;
    if(rank[x] == rank[y])
        rank[y] += 1;
    
    return true;
}

class Solution {
public:
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<vector<string>>& pairs) {
        if (words1.size() != words2.size()) {
            return false;
        }
        
        unordered_map<string, int> words;
        int counter = 1, n = pairs.size() * 2;
        vector<ll> id(n + 1), rank(n + 1);
        
        make_set(id, rank, n);
        
        for (const vector<string>& p: pairs) {
            const string& word1 = p[0], word2 = p[1];
            
            if (not words.count(word1)) {
                words[word1] = counter++;
            }
            
            if (not words.count(word2)) {
                words[word2] = counter++;
            }
            
            merge_set(id, rank, words[word1], words[word2]);
        }
        
        for (int i = 0; i < words1.size(); i++) {
            const string& word1 = words1[i], word2 = words2[i];
            
            if (word1 == word2) {
                continue;
            }
            
            if (not words.count(word1) or not words.count(word2) or find_set(id, words[word1]) != find_set(id, words[word2])) {
                return false;
            }
        }
        
        return true;
    }
};