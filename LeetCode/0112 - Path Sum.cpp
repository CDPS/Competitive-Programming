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
        return !node->left && !node->right;
    }

    bool backtrack(TreeNode* node, int targetSum, int acc){
        
        if(isLeaf(node))
            return acc + node->val == targetSum;
        bool ans = false;
        if(node->left !=NULL)
            ans = backtrack(node->left, targetSum , acc + node->val);
        if(node->right !=NULL && !ans)
            ans = backtrack(node->right, targetSum , acc + node->val);
        return ans;
    } 

    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root)  return false;
        return backtrack(root, targetSum, 0);    
    }
};