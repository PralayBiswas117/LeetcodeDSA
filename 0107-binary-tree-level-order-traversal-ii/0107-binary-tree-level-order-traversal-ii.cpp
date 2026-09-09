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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {

        // If the tree is empty, return an empty answer.
        if(root == nullptr){
            return {};
        }

        vector<vector<int>> ans;

        // Queue is used for BFS (level-order traversal).
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){

            // Number of nodes in the current level.
            int n = q.size();

            vector<int> temp;

            // Process all nodes of the current level.
            for(int i = 0; i < n; i++){

                TreeNode* help = q.front();
                q.pop();

                // Store current node's value.
                temp.push_back(help->val);

                // Add children for the next level.
                if(help->left){
                    q.push(help->left);
                }

                if(help->right){
                    q.push(help->right);
                }
            }

            // Store the current level.
            ans.push_back(temp);
        }

        // BFS generated levels from top to bottom,
        // so reverse them to get bottom-to-top order.
        reverse(ans.begin(), ans.end());

        return ans;
    }
};