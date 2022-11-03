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
    string serialize(TreeNode* root) {
        if(root==nullptr) return "";
        queue<TreeNode*> q;
        q.push(root);
        string res = "";
        while(!q.empty()){
            int n = q.size();
            for(int i=n; i>0; i--){
                TreeNode *t = q.front();
                q.pop();
                if(t!=nullptr){
                    res += to_string(t->val)+" ";
                    q.push(t->left);
                    q.push(t->right);
                }
                else res+= "# ";
           
            }
            
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        istringstream istr(data);
        if(data.size()==0) return nullptr;
        queue<TreeNode*> q;
        string str;
        istr >> str;
        TreeNode *res = new TreeNode(stoi(str)), *cur = res;
        q.push(cur);
        
        while(!q.empty()){
            int n = q.size();
            TreeNode* temp = q.front();
            q.pop();
            if(!(istr>>str)) break;
            if(str!="#"){
                TreeNode *l = new TreeNode(stoi(str));
                temp->left = l;
                q.push(l);
            }
            if(!(istr>>str)) break;
            if(str!="#"){
                TreeNode *r = new TreeNode(stoi(str));
                temp->right = r;
                q.push(r);

            }
        }
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));