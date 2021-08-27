class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        vector<string> ans;
        unordered_map<char, int> bCounter;
        
        for (const string& str: B) {
            unordered_map<char, int> bsubCounter;

            for (const char& ch: str) {
                bsubCounter[ch]++;
            }
            
            for (auto [ch, freq]: bsubCounter) {
                bCounter[ch] = max(bCounter[ch], freq);
            }
        }
        
        for (const string& str: A) {
            unordered_map<char, int> aCounter = getCounter(str);
            bool good = true;
            
            for (auto [ch, freq]: bCounter) {
                if (aCounter[ch] < freq) {
                    good = false;
                    break;
                }
            }
            
            if (good) {
                ans.push_back(str);
            }
        }
        
        return ans;
    }

private:    
    unordered_map<char, int> getCounter(const string& str) {
        unordered_map<char, int> ans;
        
        for (const char& ch: str) {
            ans[ch]++;
        }
        
        return ans;
    }
};