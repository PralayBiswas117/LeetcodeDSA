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
    bool validBST(TreeNode* node,int min , int max,unordered_map<int,TreeNode*>&mp,TreeNode* root){
        if(node==NULL){
            return true;
        }
        if(node->val <= min || node->val >= max){
            return false;
        }
        if(node->left ==NULL && node->right ==NULL){
            if(mp.count(node->val) && node != root){
                TreeNode* temp = mp[node->val];
                node->left = temp->left;
                node->right = temp->right;
                mp.erase(node->val);
            }
        }
        return validBST(node->left,min,node->val,mp,root) && 
                validBST(node->right,node->val,max,mp,root);
    }

    TreeNode* canMerge(vector<TreeNode*>& trees) {
        unordered_map<int,TreeNode*>mp;
        unordered_set<int>childNodes;

        for(auto &tree : trees){
            mp[tree->val] = tree;
            if(tree->left){
                childNodes.insert(tree->left->val);
            }
            if(tree->right){
                childNodes.insert(tree->right->val);
            }
        }
        TreeNode* root = NULL;
        for(auto &tree : trees){
            if(childNodes.count(tree->val) == 0){
                if(root != NULL){
                    return NULL; //more than one root
                }
                root = tree;
            }
        }
        if(root==NULL) return NULL;

        if(!validBST(root, INT_MIN, INT_MAX, mp, root) || mp.size() != 1)
            return NULL;
        return root;
    }
};