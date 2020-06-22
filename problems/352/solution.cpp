class SummaryRanges {
private:
    set<int> range;

public:
    SummaryRanges() {}
    
    void addNum(int val) {
        range.insert(val);
    }
    
    vector<vector<int>> getIntervals() {
        if (empty(range)) {
            return {};
        }
        
        vector<vector<int>> ans;
        
        for (const int& num: range) {
            if (empty(ans) or num > ans.back().back() + 1) {
                ans.push_back({num, num});
            } else {
                ans.back().back() = num;
            }
        }
        
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */