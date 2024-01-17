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

    vector<int> rightSideView(TreeNode* root) {
        
        if(!root)
            return {};
        
        queue<TreeNode*> q;
        q.push(root);

        vector<int> ans;
        while(!q.empty()){
            
            vector<TreeNode*> temp;
            while(!q.empty())
                temp.push_back(q.front()), q.pop();

            ans.push_back(temp.back()->val);

            for (int i=0;i < temp.size();i++){
                if(temp[i]->left) q.push(temp[i]->left);
                if(temp[i]->right)q.push(temp[i]->right);
            }
        }
        return ans;
    }
};