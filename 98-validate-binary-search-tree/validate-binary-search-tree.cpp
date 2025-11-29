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
    bool helper(TreeNode* root, TreeNode* min, TreeNode* max){
        if(root == NULL){
            return true;
        }
        // Check if current node violates BST property
        if(min != NULL && root->val <= min->val){
            return false;
        }
        if(max != NULL && root->val >= max->val){
            return false;
        }
        // Recursively check left and right subtrees
        return helper(root->left, min, root) && helper(root->right, root, max);
    }
    
    bool isValidBST(TreeNode* root) {
        return helper(root, NULL, NULL);
    }
};