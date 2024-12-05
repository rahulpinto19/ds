/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) 
    {
        if(nums.size() == 0)
            return NULL;
        if(nums.size() == 1)
            return new TreeNode(nums[0]);

        int start = 0 ,end = nums.size()-1;
        int mid = (start+end)/2;

        vector<int>left,right;

        for(int i=start;i<mid;i++)
        {
            left.push_back(nums[i]);
        }
        for(int i = mid+1;i<nums.size();i++)
        {
            right.push_back(nums[i]);
        }
        TreeNode*root = new TreeNode(nums[mid]);
        root->left = sortedArrayToBST(left);
        root->right = sortedArrayToBST(right);

        return root;
    }
};