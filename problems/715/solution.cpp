class RangeModule {
private:
    map<int, int> range;

public:
    RangeModule() {}
    
    void addRange(int left, int right) {
        auto l = range.upper_bound(left),
            r = range.upper_bound(right);
        
        if (l != begin(range)) {
            l--;
            
            if (l->second < left) {
                l++;
            }
        }
        
        if (l != r) {
            left = min(left, l->first);
            right = max(right, (--r)->second);
            range.erase(l, ++r);
        }
        
        range[left] = right;
    }
    
    bool queryRange(int left, int right) {
        auto it = range.upper_bound(left);
        
        // false, if first el larger than left or right is bigger than the prev range end
        if (it == begin(range) || (--it)->second < right) {
            return false;
        }
        
        return true;
    }
    
    void removeRange(int left, int right) {
        auto l = range.upper_bound(left),
            r = range.upper_bound(right);
        
        if (l != begin(range)) {
            l--;
            
            if (l->second < left) {
                l++;
            }
        }
        
        if (l == r) {
            return;
        }
        
        int newLeft = min(left, l->first),
            newRight = max(right, (--r)->second);
        
        range.erase(l, ++r);
        
        if (newLeft < left) {
            range[newLeft] = left;
        }
        
        if (newRight > right) {
            range[right] = newRight;
        }
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */