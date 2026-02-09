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
    vector<int>v;
    void get(TreeNode*root) {
        if(!root)return;

        get(root->left);
        v.push_back(root->val);
        get(root->right);

    }
    TreeNode* convert(int left,int right) {

        if(left > right) return NULL;
        if(left == right) return new TreeNode(v[left]);
        
        int mid = (left + right)/2;

        TreeNode *curr = new TreeNode(v[mid]);
        curr->left = convert(left,mid-1);
        curr->right = convert(mid+1,right);

        return curr;
    }
    TreeNode* balanceBST(TreeNode* root) {
        
        get(root);
        return convert(0,int(v.size())-1);

    }
};