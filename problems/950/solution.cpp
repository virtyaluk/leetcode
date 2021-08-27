class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = size(deck);
        vector<int> ans(n);
        deque<int> dq;
        
        for (int i = 0; i < n; i++) {
            dq.push_back(i);
        }
        
        sort(begin(deck), end(deck));
        
        for (const int& card: deck) {
            ans[dq.front()] = card;
            dq.pop_front();
            
            if (not empty(dq)) {
                dq.push_back(dq.front());
                dq.pop_front();
            }
        }
        
        return ans;
    }
};