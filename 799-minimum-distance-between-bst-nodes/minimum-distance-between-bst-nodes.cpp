/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *l, TreeNode *r) : val(x), left(l), right(r) {}
 * };
 */

class Solution {
public:
    // Helper that keeps teacher's structure
    int solve(TreeNode* root, TreeNode* &prev) {
        if (root == NULL) return INT_MAX;

        int ans = INT_MAX;

        // 1. Left subtree
        if (root->left != NULL) {
            int leftMin = solve(root->left, prev);
            ans = min(ans, leftMin);
        }

        // 2. Current node vs previous inorder node
        if (prev != NULL) {
            ans = min(ans, root->val - prev->val);
        }
        prev = root;

        // 3. Right subtree  ✅ (fixed: uses root->right)
        if (root->right != NULL) {
            int rightMin = solve(root->right, prev);
            ans = min(ans, rightMin);
        }

        return ans;
    }

    int minDiffInBST(TreeNode* root) {
        TreeNode* prev = NULL;      // shared across recursion
        return solve(root, prev);
    }
};
