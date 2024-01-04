class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> um;
        
        for (const string& str: arr) {
            um[str]++;
        }
        
        for (const string& str: arr) {
            k -= um[str] == 1;
            
            if (not k) {
                return str;
            }
        }
        
        return "";
    }
};