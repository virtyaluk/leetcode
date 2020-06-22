class WordDistance {
private:
    unordered_map<string, vector<int>> um;

public:
    WordDistance(vector<string>& wordsDict) {
        for (int i = 0; i < size(wordsDict); i++) {
            um[wordsDict[i]].push_back(i);
        }
    }
    
    int shortest(string word1, string word2) {
        int ans = INT_MAX;
        
        for (const int i: um[word1]) {
            for (const int j: um[word2]) {
                ans = min(ans, abs(i - j));
            }
        }
        
        return ans;
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(wordsDict);
 * int param_1 = obj->shortest(word1,word2);
 */