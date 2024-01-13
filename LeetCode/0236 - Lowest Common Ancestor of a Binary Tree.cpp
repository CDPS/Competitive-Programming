/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    bool isLeaf(TreeNode* node){
        return !node || !node->left && !node->right;
    }

    bool getParentPath(TreeNode* root, int val, stack<TreeNode*> & parent){
        
        if(!root) 
            return false;
        if(root->val == val){
            parent.push(root);
            return  true;
        }
        if(isLeaf(root)) 
            return false;
        
        bool ans = getParentPath(root->left,val, parent) || 
                   getParentPath(root->right,val,parent); 
        if(ans) 
            parent.push(root);
        return ans;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        stack<TreeNode*> parentP, parentQ;
        getParentPath(root, p->val,parentP );
        getParentPath(root, q->val,parentQ );
        int n = min(parentP.size(),parentQ.size());
        
        int i=n;
        TreeNode* ans;
        for(;i>0; i--){

            TreeNode* pv = parentP.top();
            TreeNode* qv = parentQ.top();

            if(pv->val != qv->val)
                break;
            ans = pv;
            parentP.pop(); parentQ.pop();
        }
        return ans;
    }
};