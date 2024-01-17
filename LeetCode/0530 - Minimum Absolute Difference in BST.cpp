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
    
    int getMinimumDifference(TreeNode* root) {
        
        vector<int> a;
        process(root, a);

        int mini = 1000000;
        for(int i=1;i<a.size();i++)
            mini = min (mini, a[i]-a[i-1]);
        
        return mini;
    }
};