class Solution {
public:
    unordered_map<TreeNode*, int> dp;

    int rec(TreeNode* root) {
        if (!root) return 0;
        if (dp.count(root)) return dp[root];

        int notTake = rec(root->left) + rec(root->right);
        int take = root->val;

        if (root->left) {
            take += rec(root->left->left) + rec(root->left->right);
        }
        if (root->right) {
            take += rec(root->right->left) + rec(root->right->right);
        }

        return dp[root] = max(take, notTake);
    }

    int rob(TreeNode* root) {
        return rec(root);
    }
};