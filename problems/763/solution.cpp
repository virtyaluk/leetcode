class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> lastSeen(26);
        vector<int> ans;
        
        for (int i = 0; i < S.size(); i++) {
            lastSeen[S[i] - 'a'] = i;
        }
        
        int partStart = 0, partEnd = 0;
        
        for (int i = 0; i < S.size(); i++) {
            partEnd = max(partEnd, lastSeen[S[i] - 'a']);
            
            if (partEnd == i) {
                ans.push_back(partEnd - partStart + 1);
                partStart = i + 1;
            }
        }
        
        return ans;
    }
};