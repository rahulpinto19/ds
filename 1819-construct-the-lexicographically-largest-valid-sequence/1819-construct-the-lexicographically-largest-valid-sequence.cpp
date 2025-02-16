class Solution {
public:
    vector<int> ans;
    vector<bool> vis;
    int n;
    bool found = false; // Early stopping flag

    void backTrack(int index) {
        if (found) return; // Stop if solution is already found
        if (index == ans.size()) {
            found = true; // Mark sequence as found
            return;
        }

        if (ans[index] != 0) {
            backTrack(index + 1);
            return;
        }

        for (int number = n; number >= 1; number--) {
            if (vis[number]) continue;

            if (number == 1) { 
                ans[index] = 1;
                vis[1] = true;
                backTrack(index + 1);
                if (found) return; // Stop further recursion
                ans[index] = 0;
                vis[1] = false;
            } else if (index + number < ans.size() && ans[index + number] == 0) {
                ans[index] = ans[index + number] = number;
                vis[number] = true;
                backTrack(index + 1);
                if (found) return; // Stop further recursion
                ans[index] = ans[index + number] = 0;
                vis[number] = false;
            }
        }
    }

    vector<int> constructDistancedSequence(int N) {
        n = N;
        ans.resize((2 * n) - 1, 0);
        vis.resize(n + 1, false);
        backTrack(0);
        return ans;
    }
};
