class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.size() != word2.size()) {
            return false;
        }
        
        vector<int> counter1(26), counter2(26);
        
        for (char ch: word1) {
            counter1[ch - 'a']++;
        }
        
        for (char ch: word2) {
            counter2[ch - 'a']++;
        }
        
        for (int i = 0; i < counter1.size(); i++) {
            if ((counter1[i] > 0 && counter2[i] == 0) || (counter1[i] == 0 && counter2[i] > 0)) {
                return false;
            }
        }
        
        map<int, int> t;
        
        for (int cnt: counter1) {
            t[cnt]++;
        }
        
        for (int cnt: counter2) {
            if (t.find(cnt) == t.end() || t[cnt] == 0) {
                return false;
            }
            
            t[cnt]--;
        }
        
        return true;
    }
};