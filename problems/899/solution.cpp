class Solution {
public:
    string orderlyQueue(string s, int k) {
        if (k > 1) {
            sort(begin(s), end(s));
            
            return s;
        }
        
        string mins = s;
        
        for (int i = 0; i < size(s); i++) {
            s.push_back(s.front());
            s.erase(0, 1);
            mins = min(mins, s);
        }
        
        return mins;
    }
};