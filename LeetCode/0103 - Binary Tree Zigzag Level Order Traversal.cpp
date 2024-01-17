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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)
            return {};
        
        queue<TreeNode*> q;
        q.push(root);

        vector<vector<int>> ans;
        bool direction = true;
        while(!q.empty()){
            
            vector<TreeNode*> temp;
            
            while(!q.empty())
                temp.push_back(q.front()), q.pop();

            vector<int> partial;
            for (int i=0;i < temp.size();i++){
                if(temp[i]->left) q.push(temp[i]->left);
                if(temp[i]->right)q.push(temp[i]->right);
            }

            if(direction){
                 for (int i=0;i < temp.size();i++)
                    partial.push_back(temp[i]->val);
            }else{
                for(int i= temp.size()-1;i >=0 ;i--)
                    partial.push_back(temp[i]->val);
            }
            direction = !direction;
            ans.push_back(partial);
        }
        return ans;
    }
};