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
    vector<int>pre,in;
    unordered_map<int,int>mp;
    TreeNode* buildTree(int inStart,int inEnd,int preStart,int preEnd)
    {
        if(inStart > inEnd || preStart > preEnd) return NULL;

        TreeNode*root = new TreeNode(pre[preStart]);


        int rootIndex = mp[root->val];
        int numsLeft = rootIndex - inStart;
        
        root->left = buildTree(inStart,rootIndex -1,preStart + 1,preStart + numsLeft);
        root->right = buildTree(rootIndex + 1 , inEnd, preStart + numsLeft + 1,preEnd);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        pre = preorder;
        in = inorder;
        int n = inorder.size();
        for(int i=0;i<n;i++)
        {
            mp[in[i]] = i;
        }
        return buildTree(0,n-1,0,n-1);
    }
};