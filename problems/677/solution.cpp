class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    int sum = 0;
    
    TrieNode() {}
};

class MapSum {
private:
    TrieNode *root = new TrieNode();
    unordered_map<string, int> pairs;
    
    void add(string key, int val) {
        int x = 0;
        TrieNode *node = root;
        
        if (pairs.count(key)) {
            x = pairs[key];
        }
        
        pairs[key] = val;
        
        for (const char& ch: key) {
            if (not node->children.count(ch)) {
                node->children[ch] = new TrieNode();
            }
            
            node = node->children[ch];
            node->sum += (val - x);
        }
    }
    
    int findPrefixSum(string prefix) {
        TrieNode *node = root;
        
        for (const char& ch: prefix) {
            if (not node->children.count(ch)) {
                return 0;
            }
            
            node = node->children[ch];
        }
        
        return node->sum;
    }
public:
    /** Initialize your data structure here. */
    MapSum() {}
    
    void insert(string key, int val) {
        add(key, val);
    }
    
    int sum(string prefix) {
        return findPrefixSum(prefix);
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */