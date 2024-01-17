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

    void process(TreeNode* node, vector<int> &values){
        if(node->left)  process(node->left, values);
        values.push_back(node->val);
        if(node->right) process(node->right, values);
    }
    
    bool isValidBST(TreeNode* root) {
        
        vector<int> a;
        process(root, a);

        bool ans = true;
        for(int i=1;i<a.size() && ans;i++)
            ans = a[i] > a[i-1];
        
        return ans;
    }
};