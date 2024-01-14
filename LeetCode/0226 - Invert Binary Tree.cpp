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

    bool isLeaf(TreeNode* node){
        return !node || !node->left && !node->right;
    }

    TreeNode* invertTree(TreeNode* node) {
        if(isLeaf(node))
            return node;
        TreeNode* left  = invertTree(node->left);
        TreeNode* right = invertTree(node->right);
        node->left = right; node->right = left; 
        return node;
    }
};