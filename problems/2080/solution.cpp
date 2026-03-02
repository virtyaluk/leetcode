class RangeFreqQuery {
private:
    unordered_map<int, vector<int>> um;

public:
    RangeFreqQuery(vector<int>& arr) {
        for (int i = 0; i < size(arr); i++) {
            um[arr[i]].push_back(i);
        }
    }
    
    int query(int left, int right, int value) {
        if (um.find(value) == end(um)) {
            return 0;
        }

        auto it = lower_bound(begin(um[value]), end(um[value]), left);
        auto it2 = upper_bound(begin(um[value]), end(um[value]), right);

        return it2 - it;
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */