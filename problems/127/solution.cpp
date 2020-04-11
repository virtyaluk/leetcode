class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int ans = 1;
        unordered_set<string> us(wordList.begin(), wordList.end());
        queue<string> q;
        q.push(beginWord);
        
        while (!q.empty()) {
            for (int l = q.size(); l > 0; l--) {
                string word = q.front();
                q.pop();
                
                for (int i = 0; i < word.size(); i++) {
                    string next = word;
    
                    for (char ch = 'a'; ch <= 'z'; ch++) {
                        next[i] = ch;
                        
                        if (us.find(next) != us.end()) {
                            if (next == endWord) {
                                return ans + 1;
                            }
                            
                            q.push(next);
                            us.erase(next);
                        }
                    }
                }
            }
            
            ans++;
        }
        
        return 0;
    }
};