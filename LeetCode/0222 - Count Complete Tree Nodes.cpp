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

    int countNodes(TreeNode* node) {
        if(!node)
            return 0;
        if(isLeaf(node))
            return 1;
        int ans = 1;
        ans = (node->left)?  ans + countNodes(node->left)  : ans;
        ans = (node->right)? ans + countNodes(node->right) : ans;
        return ans;
    }
};