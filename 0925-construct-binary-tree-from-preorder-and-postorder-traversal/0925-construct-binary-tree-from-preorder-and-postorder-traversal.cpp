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
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) 
    {
        stack<TreeNode*>st;
        st.push(new TreeNode(pre[0]));
        for(int i = 1,j = 0;i<pre.size();i++)
        {
            TreeNode* node = new TreeNode(pre[i]);
            while(st.top()->val == post[j])
                {st.pop();j++;}
            if(st.top()->left == NULL) st.top()->left = node;
            else st.top()->right = node;

            st.push(node);
        }    
        while(st.size() !=1)
            st.pop();
        return st.top();
    }
};