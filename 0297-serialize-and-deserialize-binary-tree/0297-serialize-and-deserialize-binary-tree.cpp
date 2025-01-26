/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    vector<string> splitString(string& str, char delimiter) {
    vector<string> result;
    std::stringstream ss(str);
    std::string item;

    while (std::getline(ss, item, delimiter)) {
        result.push_back(item);
    }

    return result;
}
    string convert(int number)
    {
        return to_string(number);
    }
    string serialize(TreeNode* root) 
    {
        if(!root) return "";

        string serialized = "";
        queue<TreeNode*>q;
        q.push(root);
        serialized+= convert(root->val);
        serialized+=',';
        while(q.size())
        {
            int size = q.size();
            while(size --)
            {
                TreeNode* top = q.front();
                q.pop();
                
                if(top->left)
                {
                    q.push(top->left);
                    serialized+= convert(top->left->val);
                    serialized+=',';
                }
                else
                {
                    serialized+= '#';
                    serialized+=',';
                } 
                if(top->right)
                {
                    q.push(top->right);
                    serialized+= convert(top->right->val);
                    serialized+=',';
                }
                else
                {
                    serialized+= '#';
                    serialized+=',';
                } 
            }
        }
        return serialized;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) 
    {
        vector<string>parsedValues = splitString(data,',');
        if(parsedValues.size() == 0 || parsedValues[0] == "#") return NULL;

        int number = stoi(parsedValues[0]);
        
        
        TreeNode*root = new TreeNode(number);
        queue<TreeNode*>q;
        q.push(root);
        int ptr = 0;
        while(q.size())
        {
            int size = q.size();
            while(size--)
            {
                TreeNode*top = q.front();
                q.pop();
                ptr+=1;
                if(parsedValues[ptr] == "#") top->left = NULL;
                else {top->left = new TreeNode(stoi(parsedValues[ptr])); q.push(top->left);}
                ptr+=1; 
                if(parsedValues[ptr] == "#") top->right = NULL;
                else {top->right = new TreeNode(stoi(parsedValues[ptr])); q.push(top->right);}
            }
        } 
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));