#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cstring>
using namespace std;

class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        // Sort numbers in ascending order
        sort(nums.begin(), nums.end());

        // Use a hash map to store the longest streak ending at each number
        unordered_map<int, int> streak;
        int maxStreak = 0;

        for (int num : nums) {
            // Check if the current number can continue a square streak from its square root
            int root = sqrt(num);
            if (root * root == num && streak.count(root)) {
                // If a streak exists for the square root, extend it
                streak[num] = streak[root] + 1;
            } else {
                // Otherwise, start a new streak with length 1
                streak[num] = 1;
            }
            // Update the maximum streak length found
            maxStreak = max(maxStreak, streak[num]);
        }

        // Return -1 if no streak of length >= 2 was found
        return maxStreak >= 2 ? maxStreak : -1;
    }
};
