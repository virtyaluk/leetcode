class Solution {
public:
    int maximumNumberOfOnes(int width, int height, int sideLength, int maxOnes) {
        vector<int> seq;
        for(int i = 0; i < sideLength; i++){
            for(int j = 0; j < sideLength; j++){
				//RoundUp((width - i)/sideLength)) * RoundUp((height - j)/sideLength)) 
                int toInsert = ((width - i + sideLength - 1)/sideLength) * ((height - j + sideLength - 1)/sideLength);
                seq.push_back(toInsert);
            }
        }
        
        sort(seq.begin(), seq.end(), greater<int>());
        int ans = 0;
        for(int i = 0; i < maxOnes; i++){
            ans += seq[i];
        }
        return ans;
    }
};