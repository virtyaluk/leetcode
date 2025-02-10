class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;
        
        ans.push_back(words.front());
        
        for (int i = 1; i < size(words); i++) {
            string s1 = words[i],
                s2 = words[i - 1];

            sort(begin(s1), end(s1));
            sort(begin(s2), end(s2));
            
            if (s1 != s2) {
                ans.push_back(words[i]);
            }
        }
    
        return ans;
    }
};