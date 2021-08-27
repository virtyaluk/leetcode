using namespace std;

class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
        sort(A.begin(), A.end());
        int max_time = -1;
        
        do {
            int h = A[0] * 10 + A[1], m = A[2] * 10 + A[3];
            
            if (h < 24 && m < 60) {
                max_time = max(max_time, h * 60 + m);
            }
        } while (next_permutation(A.begin(), A.end()));
        
        if (max_time == -1) {
            return "";
        } else {
            ostringstream strstream;
            strstream << std::setw(2) << std::setfill('0') << max_time / 60
               << ":" << std::setw(2) << std::setfill('0') << max_time % 60;
            return strstream.str();
        }
    }
};