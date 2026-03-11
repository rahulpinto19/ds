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
    string serialize(TreeNode* root) {
        
        if(!root) return "";

        string str = "";;
        queue<TreeNode*>q;
        q.push(root);
        str+=to_string(root->val);
        str+=',';
        while(q.size()) {

            int size = q.size();
            while(size--) {
                TreeNode*top = q.front();
                q.pop();


                if(top->left) {
                    q.push(top->left);
                    str+=to_string(top->left->val);
                    str+=',';

                }else{
                    str+="#,";
                }
                
                if(top->right) {
                    q.push(top->right);
                    str+=to_string(top->right->val);
                    str+=',';
                } else{
                    str+="#,";
                }
            }
        }
        cout<<str;
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string>nodes = splitString(data,',');

        if(nodes.size() == 0 or nodes[0] == "#") return NULL;

        TreeNode*root = new TreeNode(stoi(nodes[0]));
        queue<TreeNode*>q;
        q.push(root);

        int ptr = 0;
        while(q.size()) {

            int size = q.size();
            while(size--) {

                TreeNode*curr = q.front();
                q.pop();
                ptr+=1;
                if(nodes[ptr] != "#") {
                    curr->left = new TreeNode(stoi(nodes[ptr])); 
                    q.push(curr->left);
                }
                ptr+=1;
                if(nodes[ptr] != "#") {
                    curr->right = new TreeNode(stoi(nodes[ptr]));
                    q.push(curr->right);

                }
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));