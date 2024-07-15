class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int satisfied = 0,
            notSatisfied = 0;
        
        for (int i = 0, cur = 0; i < size(customers); i++) {
            satisfied += !grumpy[i] * customers[i];
            cur += grumpy[i] * customers[i];
            
            if (i >= minutes) {
                cur -= grumpy[i - minutes] * customers[i - minutes];
            }
            
            notSatisfied = max(notSatisfied, cur);
        }
        
        return satisfied + notSatisfied;
    }
};