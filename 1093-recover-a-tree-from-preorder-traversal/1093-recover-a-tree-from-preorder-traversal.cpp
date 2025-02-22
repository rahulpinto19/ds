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
   
    TreeNode* recoverFromPreorder(string str) 
    {
        stack<pair<int,TreeNode*>>st;
        TreeNode*ans;
        int i = 0;
        while(i<str.size() || st.empty())
        {
            int level = 0;
            while(i<str.size() and str[i] == '-')
            {
                i++;
                level++;
            }
            string number = "";
            while(i<str.size() and str[i] != '-')
            {
                number+=str[i++];
            }
            TreeNode*curr = new TreeNode(stoi(number));
            
            if(st.size() == 0)
            {
                ans = curr;
                st.push({0,curr});
            }
            else if(st.top().first+1 == level)
            {
                st.top().second->left = curr;
                st.push({st.top().first + 1,curr});
            }
            else
            {
                while(st.size() and st.top().first >= level)
                    st.pop();
                if(st.size())
                {
                    st.top().second->right = curr; 
                    st.push({st.top().first + 1,curr});
                }
            }
        }
        return ans;
    }
};