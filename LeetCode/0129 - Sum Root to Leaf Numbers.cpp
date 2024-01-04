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

    int ans = 0;
    bool isLeaf(TreeNode* node){
        return !node->left && !node->right;
    }

    void backtrack(TreeNode* node, int acc ){
        
        if(isLeaf(node)){
            ans += (acc*10) + node->val;
            return;
        }
        if(node->left) backtrack(node->left, (acc*10) + node->val);
        if(node->right) backtrack(node->right, (acc*10) + node->val);
    }

    int sumNumbers(TreeNode* root) {
        backtrack(root, 0);
        return ans;
    }
};