class Solution {
public:
    string longestWord(vector<string>& words) {
        string ans;
        unordered_set<string> us;
        queue<string> q;
        
        for (const string& word: words) {
            us.insert(word);
            
            if (size(word) == 1) {
                q.push(word);
            }
        }
        
        while (not empty(q)) {
            string word = q.front();
            q.pop();
            
            if (size(word) > size(ans)) {
                ans = word;
            } else if (size(word) == size(ans) and word < ans) {
                ans = word;
            }
            
            for (char ch = 'a'; ch <= 'z'; ch++) {
                word.push_back(ch);
                
                if (us.count(word)) {
                    q.push(word);
                }
                
                word.pop_back();
            }
        }
        
        return ans;
    }
};