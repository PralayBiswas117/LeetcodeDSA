class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return root;
        // sort p and q 
        if (p->val > q->val) swap(p, q);
        TreeNode* cur = root;
        while (cur) {
            if (cur->val >= p->val && cur->val <= q->val) return cur;
            else if (cur->val < p->val && cur->val < q->val) {
                cur = cur->right;
            } else {
                cur = cur->left;
            }
        }
        return cur;
    }
};