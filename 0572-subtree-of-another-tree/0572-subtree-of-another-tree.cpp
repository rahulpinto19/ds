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
  bool isSameTree(TreeNode* p, TreeNode* q) 
    {
        
        if(!p && !q)//null
        return 1;

        if(!p || !q)
        return 0;

        
        if(p->val == q->val)
            return isSameTree(p->left,q->left ) && isSameTree(p->right,q->right);
        else
        return false;
    }
    bool isSubtree(TreeNode* s, TreeNode* t) 
    {
       if(!s) return false;
       if(isSameTree(s,t)) return true;

       return isSubtree(s->left,t) || isSubtree(s->right,t);
    }
};