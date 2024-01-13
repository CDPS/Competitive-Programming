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
class BSTIterator {
public:

    vector<int> it;
    int currIndex = 0;
    
    bool isLeaf(TreeNode* node){
        return !node || !node->left && !node->right;
    }

    void init(TreeNode* root){
        
        if(!root)
            return;

        if(isLeaf(root)){
            it.push_back(root->val);
            return;
        }

        init(root->left);
        it.push_back(root->val);
        init(root->right);
    }

    BSTIterator(TreeNode* root) {
        init(root);
    }
    
    int next() {
        return it[currIndex++];
    }
    
    bool hasNext() {
        return currIndex < it.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */