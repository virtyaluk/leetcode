class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> ans;
        unordered_set<string> words(begin(wordList), end(wordList));
        queue<vector<string>> q;
        
        q.push({beginWord});
        
        while (not q.empty()) {
            for (int qlen = q.size(); qlen > 0; qlen--) {
                vector<string> seq = q.front();
                q.pop();

                if (seq.back() == endWord) {
                    ans.push_back(seq);
                    continue;
                }

                string word = seq.back();
                words.erase(word);

                for (int i = 0; i < word.size(); i++) {
                    string newWord = seq.back();

                    for (char ch = 'a'; ch <= 'z'; ch++) {
                        newWord[i] = ch;

                        if (words.count(newWord)) {
                            q.push(seq);
                            q.back().push_back(newWord);
                        }
                    }
                }
            }
            
            if (not ans.empty()) {
                break;
            }
        }
        
        return ans;
    }
};