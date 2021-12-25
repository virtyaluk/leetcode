class Solution {
public:
    vector<string> generateSentences(vector<vector<string>>& synonyms, string text) {
        unordered_map<string, unordered_set<string>> g;
        set<string> ans;
        queue<string> q;
        
        q.push(text);
        
        for (const vector<string>& syn: synonyms) {
            g[syn[0]].insert(syn[1]);
            g[syn[1]].insert(syn[0]);
        }
        
        while (not empty(q)) {
            string cur = q.front();
            q.pop();
            
            ans.insert(cur);
            
            vector<string> words = getWords(cur);
            
            for (int i = 0; i < size(words); i++) {
                if (not g.count(words[i])) {
                    continue;
                }
                
                for (const string& syn: g[words[i]]) {
                    words[i] = syn;
                    string newText = join(words, " ");
                    
                    if (not ans.count(newText)) {
                        q.push(newText);
                    }
                }
            }
        }
        
        return {begin(ans), end(ans)};
    }
    
    vector<string> getWords(string& str) {
        vector<string> words;
        string token;
        istringstream iss(str);
        
        while (getline(iss, token, ' ')) {
            words.push_back(token);
        }
        
        return words;
    }
    
    string join(vector<string>& strings, string del) {
        string ans;
        
        for (int i = 0; i < size(strings); i++) {
            ans += strings[i];
            
            if (i != size(strings) - 1) {
                ans += del;
            }
        }
        
        return ans;
    }
};