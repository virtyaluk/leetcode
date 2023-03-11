class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        long long ans = 0;
        unordered_map<int, unordered_set<string>> um;
        
        for (const string& str: ideas) {
            um[str.front() - 'a'].insert(str.substr(1));
        }
        
        for (int i = 0; i < 25; i++) {
            for (int j = i + 1; j < 26; j++) {
                long long cnt1 = 0, cnt2 = 0;
                
                for (const string& str: um[i]) {
                    cnt1 += not um[j].count(str);
                }
                
                for (const string& str: um[j]) {
                    cnt2 += not um[i].count(str);
                }
                
                ans += cnt1 * cnt2;
            }
        }
        
        return ans * 2ll;
    }
};