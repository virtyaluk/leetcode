class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<double> us;
        
        for (const int& num: arr) {
            double n = num;
            
            if (us.count(n / 2) or us.count(n * 2)) {
                return true;
            }
            
            us.insert(n);
        }
        
        return false;
    }
};