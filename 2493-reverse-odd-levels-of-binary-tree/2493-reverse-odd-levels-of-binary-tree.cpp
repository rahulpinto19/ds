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
    void help(TreeNode* root, int level)
    {
        if(!root)
            return ;
        if(level%2 == 1 and root->left and root->right)
        {
            int temp = root->left->val;
            root->left->val = root->right->val;
            root->right->val = temp;
        }
        help(root->left,level+1);
        help(root->right,level+1);

    }
    TreeNode* reverseOddLevels(TreeNode* root) 
    {
        queue<TreeNode*>q;
        q.push(root);
        int level = 1;
        while(q.size()>=1)
        {
            int size = q.size();
            vector<TreeNode*>temp;
            for(int i =0;i<size;i++)
            {
               
                TreeNode*curr = q.front();
                q.pop();
                if(curr->left)
                {
                    temp.push_back(curr->left);
                    q.push(curr->left);
                }
                if(curr->right)
                {
                    temp.push_back(curr->right);
                    q.push(curr->right);

                }
            }
             if(level%2 == 1)
            {
                for(auto x:temp)
                {
                    cout<<x->val<<" ";
                }
                cout<<endl;
                for(int i=0;i<temp.size()/2;i++)
                {
                    int fake = temp[i]->val; 
                    temp[i]->val = temp[temp.size()-1 - i]->val;
                    temp[temp.size()-1 - i]->val = fake;
                }
            }
            level++;
           
        }
        return root;
    }
};