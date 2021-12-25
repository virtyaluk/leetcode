class Solution {
public:
    vector<string> braceExpansionII(string expression) {
        int pos = 0;
        unordered_set<string> us = parse(expression, pos);
        vector<string> ans = {begin(us), end(us)};
        
        sort(begin(ans), end(ans));
        
        return ans;
    }
    
    unordered_set<string> parse(string& ex, int& pos) {
        unordered_set<string> ans, prevWords;
        
        while (pos < size(ex) and ex[pos] != '}') {
            unordered_set<string> curWords;
            
            if (ex[pos] == '{') {
                pos++;

                curWords = parse(ex, pos);

                pos++;
            } else if (ex[pos] == ',') {
                pos++;
                
                for (const string& s: prevWords) {
                    ans.insert(s);
                }
                
                prevWords.clear();
            } else {
                string word;
                
                while (ex[pos] >= 'a' and ex[pos] <= 'z') {
                    word.push_back(ex[pos++]);
                }
                
                curWords.insert(word);
            }
            
            if (empty(prevWords)) {
                prevWords = curWords;
            } else {
                // product
                unordered_set<string> wordsProduct;
                
                for (const string& prevWord: prevWords) {
                    for (const string& curWord: curWords) {
                        wordsProduct.insert(prevWord + curWord);
                    }
                }
                
                swap(wordsProduct, prevWords);
            }
        }
        
        for (const string& word: prevWords) {
            ans.insert(word);
        }
        
        return ans;
    }
};