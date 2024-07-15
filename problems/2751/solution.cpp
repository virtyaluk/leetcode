class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<int> ans;
        vector<pair<int, int>> pi;
        stack<int> st;
        
        for (int i = 0; i < size(positions); i++) {
            pi.push_back({positions[i], i});
        }
        
        sort(begin(pi), end(pi));
        
        for (auto [_, idx]: pi) {
            if (directions[idx] == 'L') {
                if (empty(st)) {
                    ans.push_back(idx);
                } else {
                    while (not empty(st) and healths[st.top()] < healths[idx]) {
                        st.pop();
                        healths[idx]--;
                    }
                    
                    if (empty(st)) {
                        ans.push_back(idx);
                    } else {
                        if (healths[st.top()] == healths[idx]) {
                            st.pop();
                        } else {
                            healths[st.top()]--;
                            
                            if (healths[st.top()] == 0) {
                                st.pop();
                            }
                        }
                    }
                }
            } else {
                st.push(idx);
            }
        }
        
        while (not empty(st)) {
            ans.push_back(st.top());
            st.pop();
        }
        
        sort(begin(ans), end(ans));
        
        for (int i = 0; i < size(ans); i++) {
            ans[i] = healths[ans[i]];
        }
        
        return ans;
    }
};