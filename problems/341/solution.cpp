/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
private:
    stack<NestedInteger> st;
    
    void processNestedList(vector<NestedInteger> &nestedList) {
        for (auto it = rbegin(nestedList); it != rend(nestedList); it++) {
            if (it->isInteger()) {
                st.push(*it);
            }
            
            processNestedList(it->getList());
        }
    }

public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        processNestedList(nestedList);
    }
    
    int next() {
        if (st.empty()) {
            return -1;
        }
        
        if (st.top().isInteger()) {
            int ans = st.top().getInteger();
            
            st.pop();
            
            return ans;
        }
        
        vector<NestedInteger> ni = st.top().getList();
        st.pop();
        
        processNestedList(ni);
        
        return next();
    }
    
    bool hasNext() {
        return not st.empty();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */