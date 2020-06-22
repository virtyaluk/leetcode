class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> ans;
        
        for (int i = 0; i < size(expression); i++) {
            if (ispunct(expression[i])) {
                vector<int> leftVals = diffWaysToCompute(expression.substr(0, i)),
                    rightVals = diffWaysToCompute(expression.substr(i + 1));
                
                for (const int& lhsv: leftVals) {
                    for (const int& rhsv: rightVals) {
                        switch (expression[i]) {
                            case '+':
                                ans.push_back(lhsv + rhsv);
                                break;
                            case '-':
                                ans.push_back(lhsv - rhsv);
                                break;
                            case '*':
                                ans.push_back(lhsv * rhsv);
                                break;
                        }
                    }
                }
            }
        }
        
        if (empty(ans)) {
            ans.push_back(stoi(expression));
        }
        
        return ans;
    }
};