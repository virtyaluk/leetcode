class ProductOfNumbers {
private:
    vector<int> nums;

public:
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        if (not num) {
            nums.clear();
        } else {
            nums.push_back(num * (empty(nums) ? 1 : nums.back()));
        }
        
        // helper(num);
    }
    
    int getProduct(int k) {
        // helper(-k);
        
        if (size(nums) < k) {
            return 0;
        }
        
        
        return nums.back() / (size(nums) == k ? 1 : nums[size(nums) - k - 1]);
        
        
        return -1;
    }
    
    void helper(int k) {
        cout << k << ": ";
        copy(begin(nums), end(nums), ostream_iterator<int>(cout, ", "));
        cout << endl;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */