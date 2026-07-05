class Solution {
public:
    int totalWaviness(int num1, int num2) 
    {
        int ans = 0;

        for (int i = num1; i <= num2; i++) {
            int n = i;
            vector<int> t;

            while (n > 0) {
                t.push_back(n % 10);
                n = n / 10;
            }
    
            for(int j = 1; j < size(t) -1; j++) {
                ans += (t[j] > t[j - 1] and t[j] > t[j + 1]) or (t[j] < t[j - 1] and t[j] < t[j + 1]);
            }
        }

        return ans;
    }
};