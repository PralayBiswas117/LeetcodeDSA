class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return dfs(root).first;        
    }

private:
    pair<bool, int> dfs(TreeNode* node) {
        if (!node) return {true, 0};
        
        auto [leftBalanced, leftHeight] = dfs(node->left);
        auto [rightBalanced, rightHeight] = dfs(node->right);
        
        bool isBalanced = leftBalanced && rightBalanced && abs(leftHeight - rightHeight) <= 1;
        
        return {isBalanced, 1 + max(leftHeight, rightHeight)};
    }    
};