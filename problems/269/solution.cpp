class Solution {
public:
    string alienOrder(vector<string>& words) {
        string ans;
        unordered_map<char, unordered_set<char>> g;
        unordered_map<char, int> indegree;
        queue<char> q;
        
        for (const string& word: words) {
            for (const char& ch: word) {
                g[ch] = {};
                indegree[ch] = 0;
            }
        }
        
        for (int i = 1; i < size(words); i++) {
            string word1 = words[i - 1], word2 = words[i];
            
            if (size(word1) > size(word2) and word1.find(word2) == 0) {
                return "";
            }
            
            for (int j = 0; j < min(size(word1), size(word2)); j++) {
                if (word1[j] == word2[j]) {
                    continue;
                }
                
                g[word1[j]].insert(word2[j]);
                break;
            }
        }
        
        for (auto &[ignore, abc]: g) {
            for (const char& ch: abc) {
                indegree[ch]++;
            }
        }
        
        for (auto &[ch, deg]: indegree) {
            if (not deg) {
                q.push(ch);
            }
        }
        
        while (not empty(q)) {
            char ch = q.front();
            q.pop();
            
            for (const char& nch: g[ch]) {
                if (not --indegree[nch]) {
                    q.push(nch);
                }
            }
            
            ans.push_back(ch);
        }
        
        // for (auto [ch, abc]: g) {
        //     cout << ch << ": ";
        //     copy(begin(abc), end(abc), ostream_iterator<char>(cout, ", "));
        //     cout << endl;
        // }
        
        return size(ans) == size(indegree) ? ans : "";
    }
};

