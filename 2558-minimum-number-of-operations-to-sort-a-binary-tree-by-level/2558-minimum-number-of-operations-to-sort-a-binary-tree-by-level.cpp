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
    int help(vector<int>&v)
    {
        int cnt = 0;
        for(int i = 0;i<v.size();i++)
        {
            int minIndex = i;
            for(int j = i;j<v.size();j++)
            {
                if(v[j]<v[minIndex])
                    minIndex = j;
            }
            if(i != minIndex)
                cnt++;
            swap(v[minIndex],v[i]);
        }
        return cnt;
    }
    int minimumOperations(TreeNode* root) 
    {
        queue<TreeNode*>q;
        q.push(root);
        int ans = 0;
        while(q.size())
        {
            int size = q.size();

            vector<int>v;
            while(size--)
            {
                TreeNode*temp = q.front();
                q.pop();
                if(temp->left)
                {
                    v.push_back(temp->left->val);
                    q.push(temp->left);
                }
                if(temp->right)
                {
                    v.push_back(temp->right->val);
                    q.push(temp->right);
                }
            }
            ans+=help(v);
        }    
        return ans;
    }
};