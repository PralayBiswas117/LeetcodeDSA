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
    void pathsum(TreeNode* node, int sum, int &ans){
        if(node == NULL) return;

        sum = (sum * 10) + node->val;
        pathsum(node->left, sum, ans);
        if(node->left == NULL && node->right == NULL) ans += sum;
        
        pathsum(node->right, sum, ans);
    }
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        pathsum(root, 0, ans);
        return ans;
    }
};