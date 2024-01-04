class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        vector<int> ans;
        unordered_map<int, vector<int>> um;
        int start = INT_MAX, prev;
        
        for (const vector<int>& ap: adjacentPairs) {
            um[ap.front()].push_back(ap.back());
            um[ap.back()].push_back(ap.front());
        }
        
        for (auto [k, v]: um) {
            if (size(v) == 1) {
                start = k;
                break;
            }
        }
        
        ans.push_back(start);
        
        while (not empty(um)) {
            int next;
            
            if (um[start].front() != prev) {
                next = um[start].front();
            } else if (size(um[start]) == 2) {
                next = um[start].back();
            } else {
                break;
            }
            
            um.erase(start);
            ans.push_back(next);
            prev = start;
            start = next;
        }
        
        return ans;
    }
};

/*
-2:4
-3:1
1:4

*/