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
    vector<double> averageOfLevels(TreeNode* root) {
                
        queue<TreeNode*> q;
        q.push(root);

        vector<double> ans;
        while(!q.empty()){
            
            vector<TreeNode*> temp;
            
            while(!q.empty())
                temp.push_back(q.front()), q.pop();

            double avg = 0;
            for (int i=0;i < temp.size();i++){
                avg += temp[i]->val;
                if(temp[i]->left) q.push(temp[i]->left);
                if(temp[i]->right)q.push(temp[i]->right);
            }
            ans.push_back(avg/temp.size() );
        }
        return ans;
    }
};