class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int zeros = 0, n = arr.size();
        
        for (const int& num: arr) {
            if (num == 0) {
                zeros++;
            }
        }
        
        for (int i = n - 1; i >= 0; i--) {
            if (arr[i] == 0) {
                if (zeros + i < n) {
                    arr[zeros + i] = 0;
                }
                
                if (zeros + i - 1 < n) {
                    arr[zeros + i - 1] = 0;
                }
                
                zeros--;
            } else if (zeros + i < n) {
                arr[zeros + i] = arr[i];
            }
        }
    }

    void duplicateZeros1(vector<int>& arr) {
        int n = arr.size();
        queue<int> q;
        
        for (const int& num: arr) {
            q.push(num);
            
            if (num == 0) {
                q.push(0);
            }
            
            if (q.size() >= n) {
                break;
            }
        }
        
        for (int i = 0; i < n; i++) {
            arr[i] = q.front();
            q.pop();
        }
    }
};