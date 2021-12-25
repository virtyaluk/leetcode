class MajorityChecker {
private:
    vector<int> ar;
    unordered_map<int, vector<int>> um;

    int countHelper(vector<int>& arr, int idx) {
        int i = -1;
        
        for (int j = size(arr); j > 0; j /= 2) {
            while (i + j < size(arr) and arr[i + j] <= idx) {
                i += j;
            }
        }
        
        return i + 1;
    }
public:
    MajorityChecker(vector<int>& arr): ar{arr} {
        for (int i = 0; i < size(arr); i++) {
            um[arr[i]].push_back(i);
        }
    }
    
    int query(int left, int right, int threshold) {
        srand(time(0));
        
        int len = right - left + 1;
        
        for (int i = 0; i < min(len, 30); i++) {
            int rndIdx = left + rand() % len;
            vector<int>& tmp = um[ar[rndIdx]];
            int cnt = countHelper(tmp, right) - countHelper(tmp, left - 1);
            
            if (cnt >= threshold) {
                return ar[rndIdx];
            }
        }
        
        return -1;
    }
};

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);
 */