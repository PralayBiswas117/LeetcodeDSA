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
        if (root==NULL) return "";
        string result="";
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            root=que.front();
            que.pop();
            result+=to_string(root->val)+'|';
            if (root->left!=NULL){
                que.push(root->left);
            }
            if (root->right!=NULL){
                que.push(root->right);
            }
        }
        return result;
    
    }

    void insert(TreeNode* root,int val){
        if(val<root->val){
            if(root->left==NULL){
                root->left=new TreeNode(val);   
                return;
            }
            insert(root->left,val);
            return;
        }
        if(val>root->val){
            if(root->right==NULL){
                root->right=new TreeNode(val);   
                return;
            }
            insert(root->right,val);
            return;
        }
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data=="") return NULL;
        queue<string> que;
        string temp="";
        int indx=0;
        
        while(data[indx] != '|'){
            temp+=data[indx];
            ++indx;
            // cout<<data[indx];
        }
        ++indx;
        // que.push(temp)
        TreeNode* root=new TreeNode(stoi(temp));
        temp="";
        while(indx<data.size()){
               
    //    cout<<data[indx];
        while(data[indx] != '|'){
            temp+=data[indx];
            ++indx;
        }
        ++indx;
        // que.push(temp)
        this->insert(root,stoi(temp));
        temp="";
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;