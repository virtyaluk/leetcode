class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    unordered_map<string, int> counter;
    bool isWord = false;
    
    TrieNode() {}
};

struct Compare {
    bool operator()(const pair<string, int>& lhs, const pair<string, int>& rhs) {
        if (lhs.second == rhs.second) {
            return lhs.first > rhs.first;
        }
        
        return lhs.second < rhs.second;
    }
};

class AutocompleteSystem {
private:
    TrieNode *root = new TrieNode();
    string prefix;
    
    void insert(string word, int time) {
        TrieNode *node = root;
        
        for (const char& ch: word) {
            if (not node->children.count(ch)) {
                node->children[ch] = new TrieNode();
            }
            
            node = node->children[ch];
            node->counter[word] += time;
        }
        
        node->isWord = true;
    }
public:
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        for (int i = 0; i < size(times); i++) {
            insert(sentences[i], times[i]);
        }
    }
    
    vector<string> input(char c) {
        if (c == '#') {
            insert(prefix, 1);
            prefix.clear();
            
            return {};
        }
        
        vector<string> ans;
        priority_queue<pair<string, int>, vector<pair<string, int>>, Compare> pq;
        TrieNode *node = root;
        prefix.push_back(c);
        
        for (const char& ch: prefix) {
            if (not node->children.count(ch)) {
                return {};
            }
            
            node = node->children[ch];
        }
        
        for (auto [word, times]: node->counter) {
            pq.push({word, times});
        }
        
        for (int i = 0; i < 3 and not empty(pq); i++) {
            ans.push_back(pq.top().first);
            pq.pop();
        }
        
        return ans;
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */