class Solution {
public:
    int dp[200005][5];

    int subArr(vector<int>& prefixSum, int subarrayLength, int currentIndex, int totalElements, int selectedChunks) {
        if (currentIndex + subarrayLength > totalElements) return INT_MIN;

        if (dp[currentIndex][selectedChunks] != -1) return dp[currentIndex][selectedChunks];

        int currentSum = prefixSum[currentIndex + subarrayLength - 1] - (currentIndex >= 1 ? prefixSum[currentIndex - 1] : 0);
        int takeCurrent = 0;

        // Option 1: Take the current subarray
        if (selectedChunks + 1 <= 3) {
            takeCurrent = subArr(prefixSum, subarrayLength, currentIndex + subarrayLength, totalElements, selectedChunks + 1);
        }

        // Option 2: Skip the current subarray
        int skipCurrent = subArr(prefixSum, subarrayLength, currentIndex + 1, totalElements, selectedChunks);

        dp[currentIndex][selectedChunks] = max(currentSum + takeCurrent, skipCurrent);
        return dp[currentIndex][selectedChunks];
    }

    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int subarrayLength) {
        int totalElements = nums.size();
        vector<int> prefixSum(totalElements + 5, 0);

        // Compute prefix sum
        for (int i = 0; i < totalElements; i++) {
            prefixSum[i] = nums[i] + (i > 0 ? prefixSum[i - 1] : 0);
        }

        memset(dp, -1, sizeof(dp));

        // Calculate the maximum possible sum
        int maxSum = subArr(prefixSum, subarrayLength, 0, totalElements, 1);

        // Backtrack to find indices for the solution
        vector<int> result;
        int currentIndex = 0, selectedChunks = 1, remainingSum = dp[0][1];
        while (result.size() < 3 && currentIndex < totalElements && selectedChunks <= 3) {
            if (dp[currentIndex][selectedChunks] <= -1) {
                currentIndex++;
                continue;
            }
            int currentSubarraySum = prefixSum[currentIndex + subarrayLength - 1] - (currentIndex >= 1 ? prefixSum[currentIndex - 1] : 0);
            if (selectedChunks + 1 <= 3 && currentIndex + subarrayLength <= totalElements - 1 &&
                dp[currentIndex][selectedChunks] - currentSubarraySum == dp[currentIndex + subarrayLength][selectedChunks + 1]) {
                result.push_back(currentIndex);
                remainingSum -= currentSubarraySum;
                currentIndex += subarrayLength;
                selectedChunks++;
                continue;
            }
            currentIndex++;
        }

        // Add the last subarray index
        for (int i = 0; i < totalElements; i++) {
            if (dp[i][3] == remainingSum && i >= result.back() + subarrayLength &&
                prefixSum[i + subarrayLength - 1] - prefixSum[i - 1] == remainingSum) {
                result.push_back(i);
                break;
            }
        }

        return result;
    }
};
