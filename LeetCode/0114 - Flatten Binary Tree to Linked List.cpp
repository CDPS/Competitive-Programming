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

    TreeNode* getLeaf(TreeNode* node){
        if(isLeaf(node))
            return node;
        return getLeaf(node->right);
    }

    void flat(TreeNode* root, TreeNode* left, TreeNode* right){
        
        if(left == NULL)
            return;
        
        if(right == NULL)
            root->right = root->left;
        else{
            TreeNode* leaf = getLeaf(root->left);
            leaf->right = root->right;
            root->right = root->left;
        }

        root->left = NULL;
    }

    void flatten(TreeNode* root) {
       
       if(isLeaf(root))
            return;
       flatten(root->left);
       flatten(root->right);
       
       flat(root,root->left,root->right );
    }
};