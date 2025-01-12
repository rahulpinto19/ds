class Solution {
public:
    bool canBeValid(string brackets, string lockStatus) {
        int n = brackets.size();
       
        if (n % 2 == 1) {
            return false;
        }

        stack<int> openIndices, flexibleIndices;

        
        for (int i = 0; i < n; i++) {
            if (lockStatus[i] == '0') {
                flexibleIndices.push(i); 
            } else if (brackets[i] == '(') {
                openIndices.push(i);  
            } else if (brackets[i] == ')') {
                if (!openIndices.empty()) {
                    openIndices.pop();  
                } else if (!flexibleIndices.empty()) {
                    flexibleIndices.pop();  
                } else {
                    return false; 
                }
            }
        }

       
        while (!openIndices.empty() && !flexibleIndices.empty() &&
               openIndices.top() < flexibleIndices.top()) {
            openIndices.pop();
            flexibleIndices.pop();
        }

       
        return openIndices.empty();
    }
};
