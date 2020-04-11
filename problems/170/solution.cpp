class TwoSum {
public:
    unordered_map<int, int> m;
    
    /** Initialize your data structure here. */
    TwoSum() {
        
    }
    
    /** Add the number to an internal data structure.. */
    void add(int number) {
        m[number]++;
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        for (auto [key, val]: m) {
            int complement = value - key;
            
            if (key != complement) {
                if (m.find(complement) != m.end()) {
                    return true;
                }
            } else if (val > 1) {
                return true;
            }
        }
        
        return false;
    }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */