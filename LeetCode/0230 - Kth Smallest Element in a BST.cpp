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

    int acc=0;
    int ans;
    void process(TreeNode* node, int k){
        if(node->left) process(node->left, k);
        acc++;
        if(acc == k)
            ans = node->val;
        if(node->right) process(node->right, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        process(root, k);
        return ans;
    }
};