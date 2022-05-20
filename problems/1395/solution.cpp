class Solution {
public:
    int numTeams1(vector<int>& rating) {
        int ans = 0;
        
        for (int i = 0; i < rating.size() - 2; i++) {
            for (int j = i + 1; j < rating.size() - 1; j++) {
                for (int k = j + 1; k < rating.size(); k++) {
                    if ((rating[i] < rating[j] && rating[j] < rating[k]) || (rating[i] > rating[j] && rating[j] > rating[k])) {
                        ans++;
                    }
                }
            }
        }
        
        return ans;
    }
    
    int numTeams(vector<int>& rating) {
        int ans = 0;
        
        for (int i = 1; i < rating.size() - 1; i++) {
            int leftSmallest = 0, leftBiggest = 0, rightSmallest = 0, rightBiggest = 0;
            
            for (int j = 0; j < i; j++) {
                if (rating[j] < rating[i]) {
                    leftSmallest++;
                }
                
                if (rating[j] > rating[i]) {
                    leftBiggest++;
                }
            }
            
            for (int k = i + 1; k < rating.size(); k++) {
                if (rating[k] < rating[i]) {
                    rightSmallest++;
                }
                
                if (rating[k] > rating[i]) {
                    rightBiggest++;
                }
            }
            
            ans += leftSmallest * rightBiggest + leftBiggest * rightSmallest;
        }
        
        return ans;
    }
};