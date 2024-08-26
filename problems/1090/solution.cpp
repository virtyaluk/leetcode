class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        int ans = 0;
        vector<pair<int, int>> vp;
        unordered_map<int, int> used;
        
        for (int i = 0; i < size(labels); i++) {
            vp.push_back({values[i], labels[i]});
        }
        
        sort(begin(vp), end(vp), greater<>());
        
        for (auto [value, label]: vp) {
            if (used[label] < useLimit) {
                ans += value;
                used[label]++;
                numWanted--;
            }
            
            if (not numWanted) {
                break;
            }
        }
        
        return ans;
    }
};